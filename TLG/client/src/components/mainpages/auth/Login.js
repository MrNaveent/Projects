import React, {useState} from 'react'
import {Link} from 'react-router-dom'
import axios from 'axios'
import styles from "../styles.module.css";

function Login() {
    const [user, setUser] = useState({
        email:'', password: ''
    })

    const onChangeInput = e =>{
        const {name, value} = e.target;
        setUser({...user, [name]:value})
    }

    const loginSubmit = async e =>{
        e.preventDefault()
        try {
            await axios.post('/user/login', {...user})

            localStorage.setItem('firstLogin', true)
            
            window.location.href = "/";
        } catch (err) {
            alert(err.response.data.msg)
        }
    }

    return (
        <div className={styles.login_container}>
            <div className={styles.login_form_container}>
				<div className={styles.left}>
                    <form className={styles.form_container} onSubmit={loginSubmit}>
                        <h1 className={styles.head}> Login</h1>
                        <input 
                            type="email" name="email" required className={styles.input}
                            placeholder="Email" value={user.email} onChange={onChangeInput} />
        
                        <input type="password" name="password" required autoComplete="on" className={styles.input}
                        placeholder="Password" value={user.password} onChange={onChangeInput} />
        
                        
                            <button type="submit" className={styles.green_btn}>
                                Login
                            
                            </button>

                        <div className={styles.right}>   
                            <Link to="/register">
                            <button type="button" className={styles.white_btn}>
							Register
						    </button>
                            </Link>
                        
                        </div>
                    </form>
        
                </div>
            </div>
        </div>
        
    )
}

export default Login
