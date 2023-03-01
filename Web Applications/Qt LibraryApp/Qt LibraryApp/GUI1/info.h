#ifndef info_H
#define info_H
#include <QJsonArray>
#include <QDateTime>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>

struct User {
    QString login;
    QString password;
    User(const QJsonObject& in) {
        login = in["user"].toString();
        password = in["pwd"].toString();
    }
    User(QString _login,  QString _password)
    {
        login = _login;
        password = _password;
    }
    QJsonObject convert() const{
        QJsonObject obj;
        obj.insert("user", login);
        obj.insert("pwd", password);
        return obj;
    }
    bool operator==(const QString _in_login) const{
        return login == _in_login;
    }

    bool checkPassword(QString _password){
        return password == _password;
    }

};

template<typename T>
class container {
    std::vector<T> _info;
    QString _path;
    public:
        void add(const T& ele) {
             _info.emplace_back(ele);
        }
        bool addIfUnique(const QString& in, const T& ele) {
            if(!contains(in)) {
                _info.emplace_back(ele);
                return true;
            }
            return false;
        }
        bool addIfUnique(const int& in, const T& ele) {
            if(!contains(in)) {
                _info.emplace_back(ele);
                return true;
            }
            return false;
        }
        bool deleteElement(const QString& in){
            int i = 0;
            bool found = false;
            for(auto& ele : _info){
                qDebug() << "a";
                if (ele == in){
                    qDebug() << "b";
                    found = true;
                    break;
                }
                else{
                    i++;
                }
            }
            if(found){
                qDebug() << "c";
                _info.erase(_info.begin()+i);
            }
            qDebug() << "d";
            return found;
        }
        template<typename Fun>
        bool forEach(std::function<bool(Fun&)> function) {
            for(auto& ele : _info) {
                if(function(ele)){
                    return true;
                }
            }
            return false;
        }
        T& get(const QString& in){
            for(auto& ele : _info) {
                if(ele == in) {
                    return ele;
                }
            }
        }
        T& get(const int& in){
            for(auto& ele : _info){

                if(ele == in){
                    return ele;
                }
            }
        }
        bool contains(const QString& in) const {
            for(const auto& ele : _info) {
                if(ele == in) {
                    return true;
                }
            }
            return false;
        }
        bool contains(const int& in) const {
            for(const auto& ele : _info) {
                if(ele == in) {
                    return true;
                }
            }
            return false;
        }
        container(QString path): _path(path) {
            QFile file(path);
            if(file.open( QIODevice::ReadOnly )){
                qDebug() << "file: " << path << " opened";
                QJsonDocument jsonOrg = QJsonDocument::fromJson(file.readAll());
                QJsonObject jsonObj = jsonOrg.object();
                QJsonArray jsonArr = jsonOrg.array();
                foreach(auto ele, jsonArr) {
                    _info.emplace_back(T(ele.toObject()));
//                    qDebug() << ele;
                }
                file.close();
            }
            else{
                qDebug() << "file not opened";
            }
        }
        void save() {
            qDebug () << "save called";
            QFile file1(_path);
            if(file1.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
                qDebug() << "file succesfully oppened";
                QTextStream iStream( &file1 );
//                iStream.setCodec( "utf-8" );
                QJsonArray localArr;
                for(const auto& ele : _info) {
                    localArr.append(ele.convert());
                }
                QJsonDocument jsonNew(localArr);
//                qDebug () << jsonNew.toJson(QJsonDocument::Indented);
                iStream << jsonNew.toJson(QJsonDocument::Indented);
//                file.write(jsonNew.toJson(QJsonDocument::Indented), qstrlen(jsonNew.toJson(QJsonDocument::Indented)));
                file1.close();
            }
            else{
                qDebug () << "file not opened!";
            }
        }
        ~container() {
            save();
        }
};




struct Book {
    int date;
    QString user;
    QDateTime reserved;
    QDateTime leased;
    int bookId;
    QString author;
    QString title;
    QString publisher;

    Book(const QJsonObject& in){
        bookId = in["id"].toInt();
        author = in["author"].toString();
        title = in["title"].toString();
        publisher = in["publisher"].toString();
        date= in["date"].toInt();
        user = in["user"].toString();
        QString reservedString = in["reserved"].toString();
        reserved = QDateTime::fromString(reservedString, "yyyy-MM-dd");
        QString leasedString = in["leased"].toString();
        leased = QDateTime::fromString(leasedString, "yyyy-MM-dd");

        if(getStatus() == "reserved"){
             QDateTime theDayBeforeYesterday =  QDateTime::currentDateTime().addDays(-2);
             if(reserved < theDayBeforeYesterday){
                 setAvailable();
             }

        }
    }
    QJsonObject convert() const{
        QJsonObject obj;
        obj.insert("id", bookId);
        obj.insert("author", author);
        obj.insert("title", title);
        obj.insert("publisher", publisher);
        obj.insert("date", date);
        obj.insert("user", user);
        QString reservedString = reserved.toString("yyyy-MM-dd");
        if(reservedString == "1970-01-01"){
            obj.insert("reserved", "");
        }
        else{
            obj.insert("reserved", reservedString);
        }

        QString leasedString = leased.toString("yyyy-MM-dd");
        if(leasedString == "1970-01-01"){
            obj.insert("leased", "");
        }
        else{
            obj.insert("leased", leasedString);
        }
        return obj;
    }
    const int getId() const{
        return bookId;
    }
    const QString getAuthor() const{
        return author;
    }
    const QString getTitle() const{
        return title;
    }
    const QString getPublisher() const{
        return publisher;
    }
    const int getDate() const{
        return date;
    }
    const QString getUser() const{
        return user;
    }
    const QDateTime getReserved() const{
        return reserved;
    }
    bool setReserved(QString _user){
        QDateTime old = reserved;
        reserved = QDateTime::currentDateTime();
        leased = QDateTime::fromString("1990-02-30","yyyy-MM-dd");
        user = _user;
        bool ret;
        if(old == reserved){
            ret = false;
        }
        else{
            ret = true;
        }
        return ret;
    }
    bool setLeased(){
        qDebug() << "setLeased called";
        QDateTime old = leased;
        leased = QDateTime::currentDateTime();
        if(!reserved.isValid()){
            reserved = leased;
        }
        if(old == leased){
            return false;
        }
        else{
            return true;
        }
    }
    bool setLeased(QString _user){
        user = _user;
        return setLeased();
    }
    void setAvailable(){
        qDebug() << "setAvaliable called book id: " << bookId;
        user = "";
        leased = QDateTime::fromString("1990-02-30","yyyy-MM-dd");
        reserved = QDateTime::fromString("1990-02-30","yyyy-MM-dd");
        qDebug() << "book status: " << getStatus();
    }
    const QDateTime getLeased() const{
        return leased;
    }
    const QString printAll() const{
        QString str =  "id: author: " + author + " title: " + title + " publisher: " + publisher + " date: " + QString::number(date) + " user: " + user + " reserved: " + reserved.toString("yyyy-MM-dd")+  " leased: " + leased.toString("yyyy-MM-dd");
        qDebug() << str << "\n";
        return str;
    }

    bool operator==(const int _in_bookId) const{
        return bookId == _in_bookId;
    }

    const QString getStatus() const{
        if(leased.isValid()){
            return "leased";
        }
        else{
            if (reserved.isValid()){
                return "reserved";
            }
            else{
                return "available";
            }
        }
    }

};

class info {
private:
    container<User> users;
    container<Book> books;
    QString currUser;
    info():
        users("/Users/naveen/GUI1/users.json"),
        books("/Users/naveen/GUI1/books.json"){};
    public:
        info(const info&) = delete;
        info(info&&) = delete;
        static info& get() {
            static info _info;
            return _info;
        }
        container<User>& getUsers(){
            return users;
        }
        const QString getCurrUser(){
            return currUser;
        }
        void saveUsers(){
            users.save();
        }
        void saveBooks(){
            books.save();
        }
        container<Book>& getBooks(){
            return books;
        }
        void setCurrUser(QString _user){
            qDebug() << "user set to " << _user << "\n";
            currUser = _user;
        }



};

#endif // info_H
