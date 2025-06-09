#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <filesystem>
#include "json.hpp"


#define CL_RED "\033[1;31m"
#define CL_BLUE "\033[1;34m"
#define CL_GREEN "\033[1;32m"
#define CL_MAGENTA "\033[1;35m"
#define cl_rang "\033[1;40m"
#define CL_DEFAULT "\033[0m"

using namespace std;

namespace fs = std::filesystem;
using json = nlohmann::json;

class Reservation;
    json admin_config = {};
    json ConfigPaths = {};
    json meals = {
        {"gorme sabzy",6585, 15000, "active", "non-veg"},
        {"chelow kabab",8432, 18000, "active", "non-veg"},
        {"fesenjan",7512, 16000, "active", "non-veg"},
        {"kashk e bademjan",8465, 12000, "active", "veg"},
        {"ash reshteh",5411, 13000, "active", "veg"},
        {"mirza ghasemi",9912, 14000, "active", "veg"},

    };
    json dininghalls = {
        {"shokat" , 5485,"shokat","birjand",6500},
        {"amirabad" , 3295,"amirabad","birjand",3000},
    };
    json foodservice_ids = {};




class User {
private :    
    int userID;
    string name;
    string LastName;
    string hashedPassword;
public :
    User();
    virtual void print()const;
    void setPassword(string password);
    bool checkPassword(string password);
    void setHashedPassword(string);
    string getHashedPassword();

    virtual void getType();
    int getuserid();
    string getname();
    string getLastName();
    string gethashedPassword();
    void setuserID(int);
    void setname(string);
    void setLastName(string);
    void sethashedPassword(string);
};

class Admin : public User{
public :
    void print()const;
    void getType();
};

class Student : public User {
private:
    int user_id;
    string student_id;
    string phone;
    vector<Reservation> reservation;
    string name;
    string email;
    float balance;
    bool is_active;

public:
    Student();
    void print();
    bool cancel_reservation();
    int getuser_id();
    string getphone();
    string getstudent_id();
    string getname();
    string getemail();
    void getType();
    vector<Reservation> getReserves();
    float getbalance();
    bool getis_active();
    void activate();
    void deactivate();
    void setuserid(int);
    void setphone(string);
    void setstudent_id(string);
    void setname(string);
    void setemail(string);
    void setbalance(float);
    void setis_active(bool);
};


enum meal_type { BREAKFAST ,LUNCH ,DINNER };
enum RStatus {SUCCESS ,CANCELLED , FAILED ,NOT_PAID};
enum TransactionType {TRANSFER , PAYMENT};
enum TransactionStatus {PENDING ,COMPLETED ,FIALED};
enum SessionStatus {AUTHENTICATED ,ANONYMOUS};
enum status { pending, CONFIRMED, cancelled };

class Meal {
private:
    int meal_id;
    string name;
    float price;
    bool isActive;
    meal_type type;
    vector<string> side_items;

public:
    Meal();
    void print();
    bool isactive();
    void update_price(float);
    void add_side_item(string);
    int getmeal_id();
    bool getisActive();
    string getname();
    float getprice();
    meal_type getmeal_type();
    vector<string> getside_item();
    void activate();
    void deactivate();
    void addSideItem(string);
    void addprice(float);
    void setisActive(bool);
    void setmeal_id(int);
    void setname(string);
    void setprice(float);
    void setmeal_type(meal_type);
    void setside_item(string);
};





class Dinninghall {
private:
    int hall_id;
    string name;
    string address;
    int capacity;

public:
    Dinninghall();
    void print();
    int gethall_id();
    string getname();
    string getaddress();
    int getcapacity();
    void sethall_id(int);
    void setname(string);
    void setaddress(string);
    void setcapacity(int);
};

class Reservation {
private:
    int reservation_id;
    Student student;
    Dinninghall dhall;
    Meal meal;
    status res_status;
    time_t createdAt;

public:
    Reservation();
    void print();
    bool cancel();
    int getreservation_id();
    Student getstudent();
    Dinninghall getdhall();
    Meal getmeal();
    status getstatus();
    void setreservation_id(int);
    void setstudent(Student);
    void setdhall(Dinninghall);
    void setmeal(Meal);
    void setstatus(status);
};
class Transaction {
private :
    int transactionID;
    string _trackingCode;
    float _amount;
    TransactionType _type;
    TransactionStatus _status;
    time_t _createdAt;
public :
    Transaction();
    int gettransactionID();
    string gettrackingCode();
    float getamount();
    TransactionType gettype();
    TransactionStatus getstatus();
    time_t getcreatedAt();
    void settransactionID(int);
    void settrackingCode(string);
    void setamount(float);
    void settype(TransactionType);
    TransactionStatus setstatus(TransactionStatus);
    void setcreatedAt(time_t);
};

class ShoppingCart{
    private :
        vector<Reservation> reservation;
    public :
        Transaction confirm();
        void addReservation(Reservation reservation);
        void removeReservation(int ID);
        void viewShoppingCartItems();
        void clear();
        vector<Reservation> getReservations() const;
};

Transaction::Transaction() {
    transactionID = 0;
    _trackingCode = " ";
    _amount = 0.0;
    TransactionType _type;
    TransactionStatus _status;
    time_t _createdAt;
}

int Transaction::gettransactionID() {
    return transactionID;
}

string Transaction::gettrackingCode() {
    return _trackingCode;
}

float Transaction::getamount() {
    return _amount;
}

TransactionType Transaction::gettype() {
    return _type;
}

TransactionStatus Transaction::getstatus() {
    return _status;
}

time_t Transaction::getcreatedAt() {
    return _createdAt;
}

void Transaction::settransactionID(int id) {
    transactionID = id;
}

void Transaction::settrackingCode(string code) {
    _trackingCode = code;
}

void Transaction::setamount(float amount) {
    _amount = amount;
}

void Transaction::settype(TransactionType type) {
    _type = type;
}

TransactionStatus Transaction::setstatus(TransactionStatus status) {
    _status = status;
    return _status;
}

void Transaction::setcreatedAt(time_t createdAt) {
    _createdAt = createdAt;
}


Transaction ShoppingCart::confirm() {
    
}

void ShoppingCart::addReservation(Reservation res) {
    reservation.push_back(res);
}

void ShoppingCart::removeReservation(int ID) {
    for (auto it = reservation.begin(); it != reservation.end(); ++it) {
        if (it->getreservation_id() == ID) { // Assuming Reservation has getID() method
            reservation.erase(it);
            break;
        }
    }
}

void ShoppingCart::viewShoppingCartItems() {
  
}

void ShoppingCart::clear() {
    reservation.clear();
}

vector<Reservation> ShoppingCart::getReservations() const {
    return reservation;
}


User :: User(){
    int userID = 0 ;
    string name = " ";
    string LastName = " ";
    string hashedPassword = " ";
}
void  User :: print()const{
    cout << userID << endl;
    cout << name<< endl ;
    cout << LastName << endl;
    cout << hashedPassword << endl;
}
//void User :: getType(){}
int User :: getuserid(){
    return userID;
}
string User :: getname(){
    return name;
}
status getstatus();
string User :: getLastName(){
    return LastName;
}
string User :: gethashedPassword(){
    return hashedPassword;
}
void User :: setuserID(int x){
    userID = x;
}
void User :: setname(string st){
    name = st;
}
void User :: setLastName(string st){
    LastName = st;
}
void User :: sethashedPassword(string st){
    hashedPassword = st;
}

class Storage {
private:
    int _mealIDCounter;
    int _diningHallIDCounter;
    std::vector<Meal> allMeals;
    std::vector<Dinninghall> allDiningHalls;

    Storage() = default;  // Default constructor
    Storage(const Storage&) = delete;  
    Storage& operator=(const Storage&) = delete; 

public:
    void addMeal(Meal);
    void addDinningHall(Dinninghall);
    void removeMeal(int);
    void removeDinningHall(int);
    void MealActivation(int, bool);
    vector<Meal>::iterator findMeal(int);
    vector<Dinninghall>::iterator findDiningHall(int);

    static Storage& instance() {
    static Storage storageInstance;
    return storageInstance;
    }
};
class ConfigPaths {
private : 
    fs::path d_config = "d-config";
    fs::path c_students = "c-students";
    fs::path d_foodservice = "d-foodservice";
    fs::path d_sessions= "d-sessions";
    fs::path j_admin_config = "j_admin_config";
    fs::path j_ConfigPaths = "j-configpaths";
    fs::path j_meals = "j-meals";
    fs::path j_dininghalls = "j-dinninghalls";
    fs::path d_student_sessions = "d-student-sessions";
    fs::path d_admin_sessions = "d-admin-session";
    fs::path j_foodservice_ids = "j-foodservice-ids";
    fs::path l_students_log_file = "l-student-log-file";
    fs::path l_admins_log_file = "l-admin-log-file";
    fs::path d_logs = "d-logs";
    fs::path t_student_transactions = "t-student-transactions";
public :
    static ConfigPaths& instance();
    fs::path j_reservations(Student* = nullptr);
};
class FoodServiceFilling {
public :
    static vector<Meal> giveAllMeals();
    static bool saveMeals(vector<Meal>);
    static int getLastMealID();
    static bool updateLastMealID(int);
    static bool initialMealIDFile();
};
class SessionBase {
private:
    time_t _createdAt;
    time_t _lasttimeLogin;
    SessionStatus _status;
public:
    virtual ~SessionBase() = default;
    virtual void load_session() = 0;
    virtual void save_session() = 0;
    virtual void login(string, string) = 0;
    virtual void logout() = 0;
    
    time_t get_createdat();
    time_t get_lasttimeLogin();
    SessionStatus get_status();
    void set_createdat(time_t);
    void set_lasttimeLogin(time_t);
    void set_status(SessionStatus);
};

namespace AdminSession {
class SessionManager : public SessionBase {
private:
    Admin* _currentAdmin;
    int _adminID;
public:
    static bool sign_in();
    static bool isThereAnyAdmin();
    Admin* currentAdmin()  const;
    void setCurrentAdmin(Admin*);
    int getAdminId()  const;
    void setAdminID(int);
    void load_session() override;
    void save_session() override;
    void login(string, string) override;
    void logout() override;
    
    Admin currentAdmin();
    Admin get_curentAdmin();
    int get_adminID();
    static SessionManager& instance();
};
}

namespace StudentSession {
class SessionManager : public SessionBase {  // Fixed typo in class name
private:
    Student* _currentStudent;
    ShoppingCart* _shopping_cart;
    int _studentID;
public:
    Student* currentStudent()  const;
    ShoppingCart* shoppingCart()  const;
    void setShoppingCart(ShoppingCart*);
    void setCurrentStudent(Student*);
    int getStudentID()  const;
    void setStudentID(int);

    void load_session() override;
    void save_session() override;
    void login(string, string) override;
    void logout() override;
    
    ShoppingCart shoppingCart() { return *_shopping_cart; }
    Student get_currentStudent() { return *_currentStudent; }
    ShoppingCart get_shopping_cart() { return *_shopping_cart; }
    int get_studentID() { return _studentID; }
    static SessionManager& instance();
};
}


time_t SessionBase::get_createdat() {
    return _createdAt;
}

time_t SessionBase::get_lasttimeLogin() {
    return _lasttimeLogin;
}

SessionStatus SessionBase::get_status() {
    return _status;
}

void SessionBase::set_createdat(time_t time) {
    _createdAt = time;
}

void SessionBase::set_lasttimeLogin(time_t time) {
    _lasttimeLogin = time;
}

void SessionBase::set_status(SessionStatus st) {
    _status = st;
}


Admin AdminSession::SessionManager::currentAdmin() { 
    return *_currentAdmin; 
}

Admin AdminSession::SessionManager::get_curentAdmin() { 
    return *_currentAdmin; 
}

int AdminSession::SessionManager::get_adminID() { 
    return _adminID; 
}

AdminSession::SessionManager& AdminSession::SessionManager::instance() {

}


StudentSession::SessionManager& StudentSession::SessionManager::instance() {

}
class Admin_Panel {
public :
    void chooseCsvFile(fs::path);
    void displayAllMeals();
    void displayAllDininigHalls();
    void addNewMealIntractive();
    void addNewDiningHallIntractive();
    void removeMeal(int);
    void mealAcitvation(int, bool);
    void removeDiningHall(int);
    void showMenu();
    void action(int);

};






class Student_Panel{
    public:
    void Action(int);
    void showMenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void viewShppingCart();
    void addToShoppingCart();
    // +void confirmShoppingCart()
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int);
    void exit();  
};
void Student_Panel :: Action(int n){

}
void Student_Panel::showMenu(){
    string* menu;
    int size;
    cout << endl;
    for (int i = 0; i < size; i++) {
        Sleep(100);
        cout << CL_BLUE << i + 1 << ". " << menu[i] << CL_DEFAULT<< endl;
    }
}


void Student_Panel::exit(){
    cout << "exiting....";
}

void Student_Panel :: showStudentInfo(){
    Student st;
    cout << "name :" << st.getname() << endl;
    cout << "email :"<< st.getemail() << endl;
}
void Student_Panel :: checkBalance(){
    Student st;
    cout << "the balance is :" << st.getbalance() << endl;
}
void Student_Panel :: viewReservations(){
    Student st;
    
    cout << "the reservation is :" << endl;
    st.getReserves();
}
void Student_Panel :: viewShppingCart(){
    ShoppingCart cart;
    cart.viewShoppingCartItems();
}
    
void Student_Panel :: addToShoppingCart(){
    ShoppingCart cart;
    cart.confirm();
}

void Student_Panel :: removeShoppingCartItem(){
    ShoppingCart cart;
    cart.clear();
}
void Student_Panel :: increaseBalance(){
    Student st;
    int x;
    cout << "enter balance\n";
    cin >> x;
    st.setbalance(x); 
}



Student::Student() {
    user_id = 0;
    student_id = "";
    name = "";
    email = "";
    balance = 0;
    is_active = false;
}

void Student::print() {
    cout << "User ID: " << user_id << endl;
    cout << "Student ID: " << student_id << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Balance: " << balance << endl;
    cout << "Active Status: " << (is_active ? "Active" : "Inactive") << endl;
}

int Student::getuser_id() {
    return user_id;
}
string Student:: getphone(){
    return phone;
}

string Student::getstudent_id() {
    return student_id;
}

string Student::getname() {
    return name;
}

string Student::getemail() {
    return email;
}
vector<Reservation> Student ::  getReserves(){
    for (Reservation reserv : reservation){
        reserv.print();
    }
}

float Student::getbalance() {
    return balance;
}

bool Student::getis_active() {
    return is_active;
}

void Student::setuserid(int x) {
    user_id = x;
}
void Student :: setphone(string st){
    phone = st;
}

void Student::setstudent_id(string st) {
    student_id = st;
}

void Student::setname(string st) {
    name = st;
}

void Student::setemail(string st) {
    email = st;
}

void Student::setbalance(float fl) {
    balance = fl;
}

void Student::setis_active(bool check) {
    is_active = check;
}


Meal::Meal() {
    meal_id = 0;
    name = "";
    price = 0;  
}

void Meal::print() {
    cout << "Meal ID: " << meal_id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Meal Type: ";

    cout << endl;

    cout << "Side Items: ";
    for (const auto& item : side_items) {
        cout << item << " ";
    }
    cout << endl;
}
int Meal :: getmeal_id(){
    return meal_id;
}
bool Meal :: getisActive(){
    return isActive;
}
string Meal :: getname(){
    return name;
}
float Meal :: getprice(){
    return price;
}

void Meal::add_side_item(string st) {
    side_items.push_back(st);
}

vector<string> Meal::getside_item() {
    return side_items;
}

meal_type Meal::getmeal_type() {
    return type;
}
void Meal :: setisActive(bool bl){
    isActive = bl;
}

void Meal::setmeal_id(int x) {
    meal_id = x;
}

void Meal::setname(string st) {
    name = st;
}

void Meal::setprice(float fl) {
    price = fl;
}

void Meal::setmeal_type(meal_type t) {
    type = t;
}

void Meal::setside_item(string st) {
    side_items.push_back(st);
}
void Meal::addprice(float fl){
    price = fl;
}

Reservation::Reservation() {
    reservation_id = 0;
    res_status = pending; 
}

void Reservation::print() {
    cout << "Reservation ID: " << reservation_id << endl;
    cout << "Reservation Status: ";
    switch (res_status) {
        case PENDING: cout << "Pending"; break;
        case CONFIRMED: cout << CL_GREEN "Confirmed" CL_DEFAULT; break;
        case cancelled: cout << CL_RED "Cancelled" CL_DEFAULT; break;
    }
    cout << endl;

    student.print();
    dhall.print();
    meal.print();
}

bool Reservation::cancel() {
    res_status = cancelled;
    cout << "Reservation cancelled." << endl;
    return true;
}

int Reservation::getreservation_id() {
    return reservation_id;
}

Student Reservation::getstudent() {
    return student;
}
Dinninghall Reservation::getdhall() {
    return dhall;
}

Meal Reservation::getmeal() {
    return meal;
}

status Reservation::getstatus() {
    return res_status;
}

void Reservation::setreservation_id(int id) {
    reservation_id = id;
}

void Reservation::setstudent(Student st) {
    student = st;
}

void Reservation::setdhall(Dinninghall di) {
    dhall = di;
}

void Reservation::setmeal(Meal me) {
    meal = me;
}

void Reservation::setstatus(status s) {
    res_status = s;
}
Dinninghall :: Dinninghall(){
    hall_id = 0;
    name = " ";
    address = " ";
    capacity = 0;
}
void Dinninghall :: print(){
    cout << "hall id  is " << hall_id << endl;
    cout << "name is " << name << endl;
    cout << "address is " << address << endl;
    cout << "capacity is " << capacity << endl;
}
int Dinninghall ::  gethall_id(){
    return hall_id;
}
string Dinninghall ::  getname(){
    return name;
}
string Dinninghall ::  getaddress(){
    return address;
}
int Dinninghall ::  getcapacity(){
    return capacity;
}
void Dinninghall ::  sethall_id(int x){
    hall_id = x;
}
void Dinninghall ::  setname(string st){
    name = st;
}
void Dinninghall ::  setaddress(string st){
    address = st;
}
void Dinninghall ::  setcapacity(int x){
    capacity = x;
}


void printMenuOption(string option) {
    cout << option << endl;
}
/*vector<Meal> FoodServiceFilling :: giveAllMeals(){}
bool FoodServiceFilling :: saveMeals(vector<Meal>){}
int FoodServiceFilling :: getLastMealID(){}
bool FoodServiceFilling :: updateLastMealID(int){}
bool FoodServiceFilling :: initialMealIDFile(){}*/
int main(){
    
}















































