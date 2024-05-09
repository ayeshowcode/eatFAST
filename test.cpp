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
    MultipurposeBuilding(string buildingName) : Building("Multipurpose Building") {}
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
    string name;

public:
    SportsArea(const string &name) : name(name) {}

    void describe() override
    {
        cout << name << " sports area." << endl;
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
            cout << items[i] << " - Rs" << prices[i] << endl;
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
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class PizzaFast : public Shop
{
public:
    PizzaFast(string *menuItems, double *menuPrices, int size) : Shop("Pizza Fast")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class Dhaba : public Shop
{
    Dhaba(string *menuItems, double *menuPrices, int size) : Shop("Dhaba")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class JuiceShop : public Shop
{
    JuiceShop(string *menuItems, double *menuPrices, int size) : Shop("Juice Shop")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class SodaShop : public Shop
{
    SodaShop(string *menuItems, double *menuPrices, int size) : Shop("Soda Shop")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
    }
};
class Cafeteria : public Shop
{
    Cafeteria(string *menuItems, double *menuPrices, int size) : Shop("Cafeteria")
    {
        menu->setMenuItems(menuItems, menuPrices, size);
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
int main ()
{
    cout << "thora sa change" << endl;
}