using System;
using System.IO;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Numerics;


namespace LibraryApp.Models
{
    
    class container<T> where T : struct{
        public List<T> _data;
        public string _path;

        public ref List<T> getData(){
            return ref _data;
        }
        public container(string filePath){
            this._path = filePath;
            this._data = new List<T>();
            
            
        }
        ~container() {
        }
    }
    public class data
    {
        
        private container<User> users;
        private container<Book> books;
        public void addUser(string userId, string password){
            users.getData().Add(new User(userId,  password));
            save();
        }
       
        public void printAllUsers(){
            if(users._data != null){
                for(int i = 0; i < users._data.Count; i++){
                    users._data[i].print();
                }
            }
        }
        public User getUser(string login){
            if(users._data != null){
                for(int i = 0; i<users._data.Count;i++){
                    if(users._data[i].user == login){
                        return users._data[i];
                    }
                }
            }
            return new User("","");
        }
        public Book getBook(int id)
        {
            if (books._data != null)
            {
                for (int i = 0; i < books._data.Count; i++)
                {
                    if (books._data[i].id == id)
                    {
                        return books._data[i];
                    }
                }
            }
            throw new InvalidOperationException("Book not present");
            
        }
        
        public bool editBook(int id, string author, int date, DateTime? leased, string publisher, DateTime? reserved, string title, string user, string status)
        {
         
            if (books._data != null)
            {
                for (int i = 0; i < books._data.Count; i++)
                {
                    if (books._data[i].id == id)
                    {
                    
                        DateTime? locRes = books.getData()[i].reserved;
                        DateTime? locLeas = books.getData()[i].leased;
                        books.getData()[i] = new Book(id, author, title, publisher, date, user, locRes, locLeas);
                        if (status == "reserved")
                        {
                            Book loc = books._data[i];
                            books._data[i] = new Book(id, author, title, publisher, date, user, DateTime.Now.Date, null);
                        }
                        else if (status == "leased")
                        {
                            Book loc = books._data[i];
                            if (loc.getStatus() == "avaliable")
                            {
                                books._data[i] = new Book(id, author, title, publisher, date, user, DateTime.Now.Date, DateTime.Now.Date);
                            }
                            else
                            {
                                books._data[i] = new Book(id, author, title, publisher, date, user, loc.reserved, DateTime.Now.Date);
                            }
                        }
                        else
                        {
                            Book loc = books._data[i];
                            books._data[i] = new Book(id, author, title, publisher, date, "", null, null);
                        }
                        save();
                        return true;
                    }
                }
            }
            return false;
        }
        public bool changeBookStatus(int id, string newStatus, string user)
        {
            if (books._data != null)
            {
                for (int i = 0; i < books._data.Count; i++)
                {
                    if (books._data[i].id == id)
                    {
                        if(newStatus == "reserved")
                        {
                            Book loc = books._data[i];
                            books._data[i] = new Book(id, loc.author, loc.title, loc.publisher, loc.date, user, DateTime.Now.Date, null);
                        }
                        else if(newStatus == "leased")
                        {
                            Book loc = books._data[i];
                            if (loc.getStatus() == "avaliable")
                            {
                                books._data[i] = new Book(id, loc.author, loc.title, loc.publisher, loc.date, user, DateTime.Now.Date, DateTime.Now.Date);
                            }
                            else
                            {
                                books._data[i] = new Book(id, loc.author, loc.title, loc.publisher, loc.date, user, loc.reserved, DateTime.Now.Date);
                            }
                        }
                        else
                        {
                            Book loc = books._data[i];
                            books._data[i] = new Book(id, loc.author, loc.title, loc.publisher, loc.date, "", null, null);
                        }
                        save();
                        return true;
                    }
                }
            }
            return false;

        }

        public bool UserExists(string login){
            if(users._data != null){
                for(int i = 0; i<users._data.Count;i++){
                    if(users._data[i].user == login){
                        return true;
                    }
                }
            }
            return false;

        }
        public bool BookExists(int id){
            if(books._data != null){
                for(int i = 0; i<books._data.Count;i++){
                    if(books._data[i].id == id){
                        return true;
                    }
                }
            }
            return false;

        }
        public List<User> getUsers(){
            return users.getData();
        }
        public List<Book> getBooks(){
            return books.getData();
        }
        public void printAllBooks(){
            if(books._data != null){
                for( int i = 0; i < books._data.Count; i++){
                    books._data[i].print();
                }
            }
            
        }
        public data(string folderPath){
            this.users = new container<User>(folderPath+"users.json");
            this.books = new container<Book>(folderPath+"books.json");
            
            string jsonString = File.ReadAllText(users._path);
            Console.Write(jsonString);
            Console.WriteLine("file length: "+jsonString.Length);
            if(jsonString.Length > 10){
                var options = new JsonSerializerOptions{
                    AllowTrailingCommas = true,
                };
                users._data = JsonSerializer.Deserialize<List<User>>(jsonString,options)!;
            }
            else{
                users._data = new List<User>();
            }

            
            jsonString = File.ReadAllText(books._path);
            Console.Write(jsonString);
            Console.WriteLine("file length: "+jsonString.Length);
            if(jsonString.Length > 10){
                var options = new JsonSerializerOptions{
                    AllowTrailingCommas = true,
                };
                books._data = JsonSerializer.Deserialize<List<Book>>(jsonString, options)!;
                
            }
            else{
                books._data = new List<Book>();
            }

            printAllUsers();
            printAllBooks();
        }

        public void save(){

            var options = new JsonSerializerOptions { WriteIndented = true };

            using FileStream userStream1 = File.Create(users._path);
            JsonSerializer.SerializeAsync(userStream1, users._data, options);
            userStream1.DisposeAsync();

            using FileStream bookStream1 = File.Create(books._path);
            JsonSerializer.SerializeAsync(bookStream1, books._data, options);
            bookStream1.DisposeAsync();

           
        }
        ~data(){
            save();
        }

    }
    public class dataHandler
    {
        static string currUser = "";
        static data _data;
        public static ref data get(){
            return ref _data;
        }
        public static string getUser(){
            return currUser;
        }
        public static void setUser(string usr){
            currUser = usr;
        }
        public dataHandler(string folderPath){
            _data = new data(folderPath);
        }
        
        
    }
}