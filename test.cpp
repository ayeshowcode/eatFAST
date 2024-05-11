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
    Floor() {}
    string getFloorName() const { return floorName; }
    void displayFloor() const
    {
    }
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
    Building(){};
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
    CSBuilding() {}
    CSBuilding(string buildingName, string floorName) : Building(buildingName, floorName) {}
    void displayFloors() const
    {
        cout << "CS Building has 2 floors! and basement" << endl;
        cout << "0. Basement" << endl;
        cout << "1. 1st Floor" << endl;
        cout << "2. 2nd Floor" << endl;
    }
};

class EEBuilding : public Building
{
public:
    EEBuilding(string buildingName, const string &floorName) : Building(buildingName, floorName) {}
    void display() const
    {
        cout << "EE Building has 4 floors! and basement" << endl;
        cout << "0. Basement" << endl;
        cout << "1. A Floor" << endl;
        cout << "2. B Floor" << endl;
        cout << "3. C Floor" << endl;
        cout << "4. D Floor" << endl;
        cout << "5. E Floor" << endl;
    }
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
        cout << "Student " << name << " placing an order from ";
        location->describe();
    }
};

class Faculty : public User
{
public:
    Faculty(const string &name, Location *location) : User(name, location) {}
    void placeOrder() override
    {
        cout << "Faculty " << name << " placeing an order from ";
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
        items = new string[size];
        prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            items[i] = menuItems[i];
            prices[i] = menuPrices[i];
        }
    }

    ~Menu()
    {
        delete[] items;
        delete[] prices;
    }

    Menu(const Menu &other)
    {
        size = other.size;
        items = new string[size];
        prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            items[i] = other.items[i];
            prices[i] = other.prices[i];
        }
    }

    Menu &operator=(const Menu &other)
    {
        if (this != &other)
        {
            delete[] items;
            delete[] prices;
            size = other.size;
            items = new string[size];
            prices = new double[size];
            for (int i = 0; i < size; i++)
            {
                items[i] = other.items[i];
                prices[i] = other.prices[i];
            }
        }
        return *this;
    }

    void displayMenu() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << items[i] << " - Rs/" << prices[i] << endl;
        }
    }

    // Getter functions
    int getSize() const
    {
        return size;
    }

    const string &getItem(int index) const
    {
        if (index >= 0 && index < size)
        {
            return items[index];
        }
        else
        {
            static const string empty = "Invalid index";
            return empty;
        }
    }
};

class Shop
{
protected:
    string name;
    Menu *menu;

public:
    Shop(const string &name) : name(name), menu(nullptr) {}

    virtual ~Shop()
    {
        delete menu;
    }

    virtual void placeOrder(){}

    void setMenu(int size, string *menuItems, double *menuPrices)
    {
        delete menu; // Clean up existing menu before setting a new one
        menu = new Menu(size, menuItems, menuPrices);
    }

    void displayMenu()
    {
        if (menu)
        {
            menu->displayMenu();
        }
    }
};

class ShawarmaShop : public Shop
{
public:
    ShawarmaShop(string *menuItems, double *menuPrices, int size) : Shop("Shawarma Shop")
    {
        setMenu(size, menuItems, menuPrices);
    }

    void placeOrder() override
    {
        displayMenu();
        cout << "Enter the number of the item you want to order: ";
        int choice;
        cin >> choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        if (choice > 0 && choice <= menuSize)
        {
            cout << "Order placed for " << menu->getItem(choice - 1) << " at Shawarma Shop" << endl
                 << "Thank you for ordering!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
};
class PizzaFast : public Shop
{
public:
    PizzaFast(string *menuItems, double *menuPrices, int size) : Shop("Pizza Fast")
    {
        setMenu(size, menuItems, menuPrices);
    }

    void placeOrder() override
{
    displayMenu();
    cout << "Enter the number of the item you want to order: ";
    int choice;
    cin >> choice;
    const int menuSize = menu->getSize(); // Use the getter for size
    if (choice > 0 && choice <= menuSize)
    {
        cout << "Order placed for " << menu->getItem(choice - 1) << " at Dhaba" << endl
             << "Thank you for ordering!" << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}
};
class Dhaba : public Shop
{
public:
    Dhaba(string *menuItems, double *menuPrices, int size) : Shop("Dhaba")
    {
        setMenu(size, menuItems, menuPrices);
    }

    void placeOrder() override
    {
        displayMenu();
        cout << "Enter the number of the item you want to order: ";
        int choice;
        cin >> choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        if (choice > 0 && choice <= menuSize)
        {
            cout << "Order placed for " << menu->getItem(choice - 1) << " at Dhaba" << endl
                 << "Thank you for ordering!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
};
class JuiceShop : public Shop
{
public:
    JuiceShop(string *menuItems, double *menuPrices, int size) : Shop("Juice Shop")
    {
        setMenu(size, menuItems, menuPrices);
    }

    void placeOrder() override
    {
        displayMenu();
        cout << "Enter the number of the item you want to order: ";
        int choice;
        cin >> choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        if (choice > 0 && choice <= menuSize)
        {
            cout << "Order placed for " << menu->getItem(choice - 1) << " at Juice Shop" << endl
                 << "Thank you for ordering!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
};
class SodaShop : public Shop
{   
public:
    SodaShop(string *menuItems, double *menuPrices, int size) : Shop("Soda Shop")
    {
        setMenu(size, menuItems, menuPrices);
    }

    void placeOrder() override
    {
        displayMenu();
        cout << "Enter the number of the item you want to order: ";
        int choice;
        cin >> choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        if (choice > 0 && choice <= menuSize)
        {
            cout << "Order placed for " << menu->getItem(choice - 1) << " at Soda Shop" << endl
                 << "Thank you for ordering!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
};
class Cafeteria : public Shop
{
public:
    Cafeteria(string *menuItems, double *menuPrices, int size) : Shop("Cafeteria")
    {
        setMenu(size, menuItems, menuPrices);
    }

    void placeOrder() override
    {
        displayMenu();
        cout << "Enter the number of the item you want to order: ";
        int choice;
        cin >> choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        if (choice > 0 && choice <= menuSize)
        {
            cout << "Order placed for " << menu->getItem(choice - 1) << " at Cafeteria" << endl
                 << "Thank you for ordering!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
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
            CSBuilding cs;
            cs.displayFloors();
            cout << "Enter the floor name: ";
            cin >> floorName;
            CSBuilding CSBuilding("CS Building", floorName);
            Student s(name, &cs);
            s.placeOrder();

            cout << "SHOPS: " << endl;
            cout << "1. Shawarma Shop" << endl
                 << "2. Pizza Fast" << endl
                 << "3. Dhaba" << endl
                 << "4. Juice Shop" << endl
                 << "5. Soda/shake Shop" << endl
                 << "6. Cafeteria" << endl;
            cout << "Enter the Shop Name: ";
            cin >> shopchoice;
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                CSBuilding.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                CSBuilding.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                CSBuilding.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
                js.placeOrder();
                CSBuilding.describe();
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
                double menuPrices[] = {30, 40, 50, 20, 25};
                SodaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                CSBuilding.describe();
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
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
            s.placeOrder();
        }
    }
}
