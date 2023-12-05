<?php
/**
 * Plugin Name: AI Summary Plugin
 * Description: This plugin creates summary for post using OpenAI API.
 * Version: 1.0
 * PHP Version: 5.6 or higher
 * Author: Gaspare Novara, Giulio Ganci and Naveen Tiwari
 */


 require_once(plugin_dir_path(__FILE__) . 'config.php');


add_action('wp_ajax_custom_summary_request', 'custom_summary_request_handler');
add_action('wp_ajax_nopriv_custom_summary_request', 'custom_summary_request_handler');

function custom_summary_request_handler() {
    check_ajax_referer('custom_summary_nonce', 'security');
    $post_content = sanitize_text_field($_POST['post_content']);
    $summary = perform_openai_api_request($post_content);
    wp_send_json_success($summary);
}
function perform_openai_api_request($post_content) {
    $openai_api_url = 'https://api.openai.com/v1/engines/davinci/completions';
    $openai_api_key = OPENAI_API_KEY; 
    $response = wp_remote_post(
        $openai_api_url,
        array(
            'headers' => array(
                'Content-Type' => 'application/json',
                'Authorization' => 'Bearer ' . $openai_api_key,
            ),
            'body' => json_encode(array(
                'prompt' => $post_content,
                'max_tokens' => 150,
            )),
        )
    );
    
    if (is_wp_error($response)) {
        return 'Error making OpenAI API request: ' . $response->get_error_message();
    }
    $body = wp_remote_retrieve_body($response);
    $data = json_decode($body, true);
    if (isset($data['choices'][0]['text'])) {
        return $data['choices'][0]['text'];
    } else {
        return 'Error: Unable to retrieve summary from OpenAI API.';
    }
}
function enqueue_custom_script($hook) {
    if ($hook == 'post.php' || $hook == 'post-new.php') {
        wp_enqueue_script('custom-script', plugin_dir_url(__FILE__) . 'js/custom-script.js', array('jquery'), null, true);
        wp_localize_script('custom-script', 'custom_script_params', array(
            'ajax_url' => admin_url('admin-ajax.php'),
            'ajax_nonce' => wp_create_nonce('custom_summary_nonce')
        ));
    }
}
add_action('admin_enqueue_scripts', 'enqueue_custom_script');
function add_custom_summary_button() {
    global $post;
    $post_type = get_post_type($post);
    if (post_type_supports($post_type, 'excerpt')) {
        ?>
        <div class="submitbox">
            <div id="minor-publishing">
                <div id="custom_summary_button_container">
                    <button id="custom_summary_button" class="button button-primary button-large">Custom Summary Button</button>
                </div>
            </div>
            <div class="clear"></div>
        </div>
        <?php
    }
}
add_action('edit_form_after_editor', 'add_custom_summary_button');
