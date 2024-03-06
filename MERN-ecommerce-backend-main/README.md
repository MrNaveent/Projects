
# Naveen Tiwari MERN Stack E-commerce Project - Backend Repository
🔥 Features :
- Basic E-commerce Features- Product lists, Product Details, Cart, Checkout 
- Secure Card Payments / Cash payments
- Admin Panel - Add/Edit Orders. Add/Edit Products
- Sorting, Filtering, and Pagination queries using Mongoose
- Authentication with Passport JS strategies
- Order Emails, Reset Password Emails
- User Profile and user orders

🔥 Technical Details :
- React 18 with Tailwind CSS
- Redux Toolkit with Async Thunk
- Mongoose v7 as ODM
- REST API using Express
- Authentication using Passport JS
- API Authentication using Passport JWT
- MongoDB Atlas cloud database
- Vercel Server deployment
- Email using Nodemailer - using GMail SMTP system
- Payments using Stripe - PaymentIntent based custom flow


🔥 How to establish a connection:
- Please download both backend and frontend repositories from github.com.
- Go to the MERN-ecommerce-backend-main directory in terminal and run `npm install --force` command to download the required packages.
- We need to use the `--force` command as some of the packages used in the project are not compatible with the latest version of MERN.
- For simplicity I have also uploaded the `.env` file with the project, which contains all the important configurations, such as Port, MongoDB connection, etc.
- Please add your `stripe server key(stripe secret key)` in `.env` file and `stripe publishable key` in line number 10 of `stripeCheckout.js` file which is in `Frontend directory`(MERN-ecommerce-Frontend-main/src/pages/StripeCheckout.js). 
- Please use my DB url as it contains the data of `products`, `brands` and `categories`, which i fetched using another API.
- Now in terminal run `npm run dev` command, If you can see `server started and databse connected` in terminal. It means everything is working fine, now we can switch to frontend. 
