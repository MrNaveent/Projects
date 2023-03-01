using System.Runtime.CompilerServices;

namespace LibraryApp.Models
{
    public struct Book
    {
       
        public string user { get; set; }
        public DateTime? reserved { get; set; } 
        public DateTime? leased { get; set; }
        public int id { get; set; }
        public string author { get; set; }
        public string title { get; set; }
        public string publisher { get; set; }
        public int date { get; set; }

        public string toJson()
        {
            string ret = "";

            ret += "        \"title\": \"" + title + "\",";
            ret += "        \"user\": \"" + user + "\"";
            ret += "        \"author\": \"" + author + "\",";
            ret += "        \"date\": \"" + date + "\",";
            ret += "        \"id\": \"" + id + "\",";
            ret += "        \"leased\": \"" + leased + "\",";
            ret += "        \"publisher\": \"" + publisher + "\",";
            ret += "        \"reserved\": \"" + reserved + "\"";

            return ret;
        }

        public bool print()
        {
            Console.WriteLine("book id: " + id + "\n author: " + author + "\n title: " + title +
                "\n publisher: " + publisher + "\n date: " + date + "\n user: " + user +
                "\n reserved: " + reserved + "\n leased: " + leased);
            return true;
        }

        public Book(int id, string author, string title, string publisher, int date, string user, DateTime? reserved, DateTime? leased)
        {
            
            this.user = user;
            this.reserved = reserved;
            this.leased = leased;
            this.id = id;
            this.author = author;
            this.title = title;
            this.publisher = publisher;
            this.date = date;
            
        }
       
      
        public void edit(string author, int date, DateTime? leased, string publisher, DateTime? reserved, string title, string user)
        {
            this.author = author;
            this.date = date;
            this.leased = leased;
            this.publisher = publisher;
            this.reserved = reserved;
            this.title = title;
            this.user = user;        
        }
       
       
             public string getStatus()
        {
            if(this.reserved == null)
            {
                this.leased = null;
                return ("avaliable");
            }
            else
            {
                if(this.leased == null)
                {
                    return ("reserved");
                }
                else
                {
                    return ("leased");
                }
            }
        }
    }

}
