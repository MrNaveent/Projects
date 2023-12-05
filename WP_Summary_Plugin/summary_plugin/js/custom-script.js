jQuery(document).ready(function($) {
    function openSummaryModal(event) {
        console.log('AJAX Request Sent'); 
        var postContent = $('#content').val(); 
        var customButton = $('#custom_summary_button');
        customButton.prop('disabled', true).text('Loading...');
        var data = {
            action: 'custom_summary_request',
            security: custom_script_params.ajax_nonce,
            post_content: postContent
        };
        $.post(custom_script_params.ajax_url, data, function(response) {
            console.log('Response Success:', response.success);
            console.log('Response Data:', response.data);
            if (response.success) {
                var summary = response.data; 
                $('#excerpt').val('\n\nGenerated Summary:\n\n' + summary);
                customButton.prop('disabled', false).text('Custom Summary Button');
            } else {
                console.log('Error:', response.data.message);
                customButton.prop('disabled', false).text('Custom Summary Button');
            }
        });
        return false;
    }
    var customButton = $('#custom_summary_button');
    customButton.on('click', openSummaryModal);
});
