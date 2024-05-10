#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
class Floor
{
    string floorName;

public:
    Floor(const string &floorName) : floorName(floorName) {}
    Floor()
    {
        cout << "Multipurpose building has no floors!" << endl;
    }
    string getFloorName() const { return floorName; }
};

class Location
{
public:
    virtual void describe() = 0;
    virtual ~Location() {}
};

class Building : public Location
{
    string buildingName;
    Floor floor;

public:
    Building(const string &buildingName, const string &floorName) : buildingName(buildingName), floor(floorName) {}
    Building(const string &buildingName) : buildingName(buildingName) {}

    void describe() override
    {
        cout << "Building: " << buildingName << ", Floor: " << floor.getFloorName() << endl;
    }
};
class CSBuilding : public Building
{
public:
    CSBuilding(string buildingName, const string &floorName) : Building(buildingName, floorName) {}
};

class EEBuilding : public Building
{
public:
    EEBuilding(string buildingName, const string &floorName) : Building(buildingName, floorName) {}
};

class MultipurposeBuilding : public Building
{
public:
    MultipurposeBuilding(string buildingName, const string &floorName) : Building("Multipurpose Building", floorName) {}
};

class CommonRoom : public Location
{
public:
    void describe() override
    {
        cout << "Common room for students." << endl;
    }
};

class Auditorium : public Location
{
public:
    void describe() override
    {
        cout << "University auditorium." << endl;
    }
};

class SportsArea : public Location
{
public:

    void describe() override
    {
        cout << " sports area." << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class User
{
protected:
    string name;
    Location *location;

public:
    User(const string &name, Location *location) : name(name), location(location) {}
    virtual void placeOrder() = 0;
    virtual ~User() {}
};

class Student : public User
{
public:
    Student(const string &name, Location *location) : User(name, location) {}
    void placeOrder() override
    {
        cout << "Student " << name << " places an order from ";
        location->describe();
    }
};

class Faculty : public User
{
public:
    Faculty(const string &name, Location *location) : User(name, location) {}
    void placeOrder() override
    {
        cout << "Faculty " << name << " places an order from ";
        location->describe();
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Menu
{
protected:
    int size;
    string *items;
    double *prices;

public:
    Menu() : size(0), items(nullptr), prices(nullptr) {}
    Menu(int size, string *menuItems, double *menuPrices) : size(size)
    {
        this->items = new string[size];
        this->prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->items[i] = menuItems[i];
            this->prices[i] = menuPrices[i];
        }
    }
    void setMenuItems(string *items, double *prices, int size)
    {
        this->items = items;
        this->prices = prices;
        this->size = size;
    }
    void displayMenu() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << items[i] << " - Rs/" << prices[i] << endl;
        }
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Shop
{
protected:
    string name;
    Menu *menu;
    int menuSize;

public:
    Shop(const string &name) : name(name) {}
    virtual ~Shop() {}
};

class ShawarmaShop : public Shop
{
public:
    ShawarmaShop(string *menuItems, double *menuPrices, int size) : Shop("Shawarma Shop")
    {
        menu = new Menu(size, menuItems, menuPrices);
        menu->displayMenu();
    }
};
class PizzaFast : public Shop
{
public:
    PizzaFast(string *menuItems, double *menuPrices, int size) : Shop("Pizza Fast")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
        menu->displayMenu();
    }
};
class Dhaba : public Shop
{
public:
    Dhaba(string *menuItems, double *menuPrices, int size) : Shop("Dhaba")
    {
        menu = new Menu(size, menuItems, menuPrices);
        menu->displayMenu();
    }
};
class JuiceShop : public Shop
{
public:
    JuiceShop(string *menuItems, double *menuPrices, int size) : Shop("Juice Shop")
    {
        menu = new Menu(size, menuItems, menuPrices);
        menu->displayMenu();
    }
};
class SodaShop : public Shop
{
public:
    SodaShop(string *menuItems, double *menuPrices, int size) : Shop("Soda Shop")
    {
        menu = new Menu(size, menuItems, menuPrices);
        menu->displayMenu();
    }
};
class Cafeteria : public Shop
{
public:
    Cafeteria(string *menuItems, double *menuPrices, int size) : Shop("Cafeteria")
    {
        menu = new Menu(size, menuItems, menuPrices);
        menu->displayMenu();
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Service
{
    string serviceType;

public:
    Service(string serviceType) : serviceType(serviceType) {}
};

class OrderService : public Service
{
public:
    OrderService() : Service("Order Service") {}
};
class PickupService : public Service
{
public:
    PickupService() : Service("Pickup Service") {}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "Welcome to the FAST EATS APP!" << endl;
    cout << "Please select your role:" << endl;
    cout << "1. Student" << endl
         << "2. Faculty" << endl;
    int userchoice;
    cin >> userchoice;
    string name;
    string buildingName;
    string floorName;
    int locationChoice;
    int shopchoice;
    if (userchoice == 1)
    {
        cout << "Enter your Name: ";
        getline(cin, name);
        cout << "Select the Location: " << endl;
        cout << "1. CS Building" << endl
             << "2. EE Building" << endl
             << "3. Multipurpose Building" << endl;
        cout << "4. Common Room" << endl
             << "5. Auditorium" << endl
             << "6. Sports Area" << endl;
        cout << "Enter your choice:";
        cin >> locationChoice;
        if (locationChoice == 1)
        {
            cout << "Enter the floor name: ";
            cin >> floorName;
            CSBuilding cs("CS Building", floorName);
            Student s(name, &cs);
            s.placeOrder();

            cout << "SHOPS: " << endl;
            cout << "1. Shawarma Shop" << endl
                 << "2. Pizza Fast" << endl
                 << "3. Dhaba" << endl
                 << "4. Juice Shop" << endl
                 << "5. Soda/shake Shop" << endl
                 << "6. Cafeteria" << endl;
            cout << "Enter the Shop Name: " << endl;
            cin >> shopchoice;
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "box patties", "samosa", "shami burger", "spring roll", "Cold Drinks", "Juice", "Water Bottle" };
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani"};
                double menuPrices[] = {200, 250, 300, 150};
                Dhaba d(menuItems, menuPrices, 4);
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite"};
                double menuPrices[] = {30, 40, 50, 20};
                SodaShop ss(menuItems, menuPrices, 4);
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+fizzup"};
                double menuPrices[] = {20, 30, 40, 50};
                Cafeteria c(menuItems, menuPrices, 4);
            }
        }
        else if (locationChoice == 2)
        {
            cout << "Enter the floor name: ";
            cin >> floorName;
            EEBuilding ee("EE Building", floorName);
            Student s(name, &ee);
            s.placeOrder();
        }
        else if (locationChoice == 3)
        {
            MultipurposeBuilding mp("Multipurpose Building", "No Specific Floor");
            Student s(name, &mp);
            s.placeOrder();
        }
        else if (locationChoice == 4)
        {
            CommonRoom cr;
            Student s(name, &cr);
            s.placeOrder();
        }
        else if (locationChoice == 5)
        {
            Auditorium a;
            Student s(name, &a);
            s.placeOrder();
        }
        else if (locationChoice == 6)
        {
            cout << "Enter the sports area name: ";
            SportsArea sa;
            Student s(name, &sa);
        }
    }
}