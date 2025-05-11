#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#define CL_RED "\033[1;31m"
#define CL_BLUE "\033[1;34m"
#define CL_GREEN "\033[1;32m"
#define CL_MAGENTA "\033[1;35m"
#define cl_rang "\033[1;40m"
#define CL_DEFAULT "\033[0m"

using namespace std;


class Reservation;
class Student;
class Meal;
class Dinninghall;



class User {
private :    
    int userID;
    string name;
    string LastName;
    string hashedPassword;
public :
    User();
    virtual void print()const;
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
    vector<Reservation> getReserves;
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


enum meal_type { VEG, NON_VEG, VEGAN };


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
    bool isActive();
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


enum status { PENDING, CONFIRMED, CANCELLED };


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
    static Storage& instance() {
        static Storage storageInstance;
        return storageInstance;
    }
};
class Panel{
    public:
    void Action(int);
    void showMenu();
    // +void showStudentInfo()
    // +void checkBalance()
    // +void viewReservations()
    // +void addReservation(Reservation)
    // +void addToShoppingCart()
    // +void confirmShoppingCart()
    // +void removeShoppingCartItem()
    // +void increaseBalance()
    // +void viewRecentTransactions()
    // +void cancelReservation(int)
    void exit();  
};
void Panel::showMenu(){
    string* menu;
    int size;
    cout << endl;
    for (int i = 0; i < size; i++) {
        Sleep(100);
        cout << CL_BLUE << i + 1 << ". " << menu[i] << CL_DEFAULT<< endl;
    }
}
void Panel::exit(){
    return 0;
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
    type = VEG;  
}

void Meal::print() {
    cout << "Meal ID: " << meal_id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Meal Type: ";
    switch (type) {
        case VEG: cout << CL_GREEN "Veg" CL_DEFAULT; break;
        case NON_VEG: cout << CL_RED "Non-Veg" CL_DEFAULT; break;
        
    }
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















































