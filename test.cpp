#include <iostream>
#include <string>

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
class OrderCounter {
protected:
    static int orderCount;

public:
    OrderCounter() {}
    static int getOrderCount() {
        return orderCount;
    }

    static int allocateTokken(){
        return orderCount;
    }

    static void incrementOrderCount() {
        orderCount++;
    }
};

class Shop : public OrderCounter
{
protected:
    string name;
    Menu *menu;
    int menuSize;

public:
    Shop(){}
    Shop(const string &name) : name(name) {}
    virtual ~Shop() {}
};

class ShawarmaShop : public Shop
{
public:
    ShawarmaShop(){}
    ShawarmaShop(string *menuItems, double *menuPrices, int size) : Shop("Shawarma Shop")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class PizzaFast : public Shop
{
public:
    PizzaFast(){}
    PizzaFast(string *menuItems, double *menuPrices, int size) : Shop("Pizza Fast")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class Dhaba : public Shop
{
    Dhaba(){}
    Dhaba(string *menuItems, double *menuPrices, int size) : Shop("Dhaba")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class JuiceShop : public Shop
{
    JuiceShop(){}
    JuiceShop(string *menuItems, double *menuPrices, int size) : Shop("Juice Shop")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class SodaShop : public Shop
{
    SodaShop(){}
    SodaShop(string *menuItems, double *menuPrices, int size) : Shop("Soda Shop")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class Cafeteria : public Shop
{
    Cafeteria(){}
    Cafeteria(string *menuItems, double *menuPrices, int size) : Shop("Cafeteria")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Location
{
public:
    virtual void describe() = 0;
    virtual ~Location() {}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class User
{
protected:
    string name;

public:
    User(){}
    User(const string &name) : name(name){}
    virtual void placeOrder() = 0;
    virtual void getTokken() =0;
    virtual ~User() {}
};

class Student : public User
{
public:
    Student(){}
    Student(const string &name) : User(name) {}
};

class Faculty : public User
{
    Location *location;
    int extensionNo;
public:
    Faculty(){}
    Faculty(const string &name, Location *location, int num) : User(name) , location(location), extensionNo(num) {}
    void placeOrder() override
    {
        cout << "Faculty " << name << " places an order from ";
        location->describe();
        cout << "\nExtention number for the faculty " << name << "is : " << extensionNo << endl;
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
            cout << items[i] << " - Rs" << prices[i] << endl;
        }
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Service : public Shop
{
    string serviceType;

public:
    Service(string serviceType) : serviceType(serviceType) {
        Shop::allocateTokken;
    }
};

class OrderService : public Service , public Faculty
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
int main ()
{
    PizzaFast pf;
    pf.getOrderCount;
    cout << "thora sa change" << endl;
}