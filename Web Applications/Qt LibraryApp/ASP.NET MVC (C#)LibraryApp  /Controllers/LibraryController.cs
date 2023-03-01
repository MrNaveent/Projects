using LibraryApp.Models;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;

namespace LibraryApp.Controllers
{
    public class LibraryController : Controller
    {
        public IActionResult EditBook(int b)
        {

            if (Request.HasFormContentType && Request.Form != null && Request.Form.Count > 0)
            {
                String a = HttpContext.Request.Form["a"].ToString();
                if (dataHandler.getUser() != "librarian")
                {
                    return Redirect("/library");
                }
                Book loc = dataHandler.get().getBook(b);
                if (a == "edit")
                {
                    string author = HttpContext.Request.Form["author"].ToString();
                    int date = Int32.Parse(HttpContext.Request.Form["date"].ToString());
                    string publisher = HttpContext.Request.Form["publisher"].ToString();
                    string title = HttpContext.Request.Form["title"].ToString();
                    string user = HttpContext.Request.Form["user"].ToString();
                    b = Int32.Parse(HttpContext.Request.Form["b"].ToString());
                    string status = HttpContext.Request.Form["status"].ToString();
                    dataHandler.get().editBook(b, author, date, loc.leased, publisher, loc.reserved, title, user, status);

                }

            }
            else if (b == 0)
            {
                return Redirect("/library");
            }

            ViewBag.b = b;

            return View();
        }

        public IActionResult ReserveBook(int b)
        {
            dataHandler.get().changeBookStatus(b, "reserved", dataHandler.getUser());
            return Redirect("/library");
        }

        public IActionResult Index(string myBooks = "off", string author = "", string title = "")
        {
            if(myBooks != "off" || author != "" || title != "")
            {
                if (title == null) title = "";
                else title = title.ToLower();
                if (author == null) author = "";
                else author = author.ToLower();
                List<Book> books = new List<Book>();
                List<Book> allBooks = dataHandler.get().getBooks();
         
                foreach (Book book in allBooks)
                {
                    
                    if((myBooks == "off" || book.user == dataHandler.getUser()) && book.author.ToLower().Contains(author) && book.title.ToLower().Contains(title) )
                    {
                        books.Add(book);
                    }
                }
                ViewBag.myBooks = myBooks == "on";
                ViewBag.author = author;
                ViewBag.filterTitle = title;
                return View(books);
            }
            else
            {
                return View(dataHandler.get().getBooks());
            }
            
        }
        public IActionResult Book(int b)
        {
            if (b == 0)
            {
                return Redirect("/library");
            }
            ViewBag.b = b;
            return View();
        }
 
        
    }
}
