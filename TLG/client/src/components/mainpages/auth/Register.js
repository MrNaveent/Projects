import React, {useState} from 'react'
import {Link} from 'react-router-dom'
import axios from 'axios'
import styles from "../styles.module.css";
function Register() {
    const [user, setUser] = useState({
        name:'', email:'', password: ''
    })

    const onChangeInput = e =>{
        const {name, value} = e.target;
        setUser({...user, [name]:value})
    }

    const registerSubmit = async e =>{
        e.preventDefault()
        try {
            await axios.post('/user/register', {...user})

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
                     <form className={styles.form_container} onSubmit={registerSubmit}>
                         <h1 className={styles.head}> Register</h1>
                         <input type="text" name="name" required className={styles.input}
                         placeholder="Name" value={user.name} onChange={onChangeInput} />
         
                         <input type="email" name="email" required className={styles.input}
                         placeholder="Email" value={user.email} onChange={onChangeInput} />
         
                         <input type="password" name="password" required autoComplete="on" className={styles.input}
                         placeholder="Password" value={user.password} onChange={onChangeInput} />
         
                         
                        <button type="submit" className={styles.green_btn}>
                            Register
                        </button>
                             
                        <div className={styles.right}>   
                            <Link to="/login">
                            <button type="button" className={styles.white_btn}>
							 Login
						    </button>
                            </Link>
                        
                        </div>
                             
                    </form>
                 </div>
            </div>

        </div>
    )
}

export default Register