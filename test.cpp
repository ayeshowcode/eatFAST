#include <iostream>
#include <string>
using namespace std;
#include <fstream>
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
    void setFloorName(const string &floorName)
    {
        this->floorName = floorName;
    }
    string getFloorName() const { return floorName; }
    void displayFloor() const
    {
    }
};

class Location
{
public:
    virtual void describe() = 0;
    virtual string getBuildingName() = 0;
    virtual string getBuildingFloorName() = 0;
    virtual ~Location() {}
    static void displayAllLocations()
    {
        cout << "1. CS Building" << endl
             << "2. EE Building" << endl
             << "3. Multipurpose Building" << endl
             << "4. Sports Area" << endl
             << "5. Auditorium" << endl
             << "6. Common Room" << endl;
    }
    static Location *selectLocation();
};

class Building : public Location
{
protected:
    string buildingName;
    Floor floor;

public:
    Building(){};
    Building(const string &buildingName, const string &floorName) : buildingName(buildingName), floor(floorName) {}
    Building(const string &buildingName) : buildingName(buildingName) {}
    virtual string selectFloor() = 0;

    void describe() override
    {
        cout << "Building: " << buildingName << ", Floor: " << floor.getFloorName() << endl;
    }
    static Building *selectLocation();
};
class CSBuilding : public Building
{
public:
    CSBuilding() {}
    CSBuilding(string buildingName, string floorName) : Building(buildingName, floorName) {}
    void setBuildingName(string buildingName)
    {
        this->buildingName = buildingName;
    }
    string getBuildingName() override
    {
        return buildingName;
    }
    void setBuildingFloorName(string floorName)
    {
        floor.setFloorName(floorName);
    }
    string getBuildingFloorName() override
    {
        return floor.getFloorName();
    }

    void displayFloors()
    {
        cout << "CS Building has 2 floors and a basement" << endl;
        cout << "0. Basement" << endl;
        cout << "1. 1st Floor" << endl;
        cout << "2. 2nd Floor" << endl;
    }
    string selectFloor() override
    {
        displayFloors();
        int floorChoice;
        cout << "Select the floor: ";
        cin >> floorChoice;
        while (1)
        {
            if (floorChoice != 0 && floorChoice != 1 && floorChoice != 2)
            {
                floor.setFloorName("Invalid Floor!");
                return getBuildingFloorName();
            }
            else
            {
                cout << "Floor selected successfully!" << endl;
                if (floorChoice == 0)
                {
                    floor.setFloorName("Basement");
                }
                else if (floorChoice == 1)
                {
                    floor.setFloorName("1st Floor");
                }
                else if (floorChoice == 2)
                {
                    floor.setFloorName("2nd Floor");
                }
                return getBuildingFloorName();
            }
        }
    }
    void describe() override
    {
        cout << "CS Building    " << "Floor: " << floor.getFloorName() << endl;
    }
};
class EEBuilding : public Building
{
public:
    EEBuilding(){};
    EEBuilding(string buildingName, const string &floorName) : Building(buildingName, floorName) {}
    void setBuildingName(string buildingName)
    {
        this->buildingName = buildingName;
    }
    string getBuildingName() override
    {
        return buildingName;
    }
    void setFloorName(string floorName)
    {
        floor.setFloorName(floorName);
    }
    string getBuildingFloorName() override
    {
        return floor.getFloorName();
    }
    void displayFloors()
    {
        cout << "CS Building has 4 floors and a basement" << endl;
        cout << "0. Basement" << endl;
        cout << "1. B Floor" << endl;
        cout << "2. C Floor" << endl;
        cout << "3. D Floor" << endl;
        cout << "4. E Floor" << endl;
    }
    string selectFloor() override
    {
        displayFloors();
        int floorChoice;
        cout << "Select the floor: ";
        cin >> floorChoice;
        while (1)
        {
            if (floorChoice != 0 && floorChoice != 1 && floorChoice != 2 && floorChoice != 3 && floorChoice != 4)
            {
                floor.setFloorName("Invalid Floor!");
                return getBuildingFloorName();
            }
            else
            {
                cout << "Floor selected successfully!" << endl;
                if (floorChoice == 0)
                {
                    floor.setFloorName("Basement");
                }
                else if (floorChoice == 1)
                {
                    floor.setFloorName("B Floor");
                }
                else if (floorChoice == 2)
                {
                    floor.setFloorName("C Floor");
                }
                else if (floorChoice == 3)
                {
                    floor.setFloorName("D Floor");
                }
                else if (floorChoice == 4)
                {
                    floor.setFloorName("E Floor");
                }
                return getBuildingFloorName();
            }
        }
    }
    void describe() override
    {
        cout << "EE Building" << endl
             << "floor: " << floor.getFloorName() << endl;
    }
};

class MultipurposeBuilding : public Building
{
public:
    MultipurposeBuilding(string buildingName, const string &floorName) : Building("Multipurpose Building", floorName) {}
    MultipurposeBuilding() : Building("Multipurpose Building") {}
    void setBuildingName(string buildingName)
    {
        this->buildingName = buildingName;
    }
    string getBuildingName() override
    {
        return buildingName;
    }
    void setFloorName(string floorName)
    {
        floor.setFloorName(floorName);
    }
    string getBuildingFloorName() override
    {
        return floor.getFloorName();
    }
    void displayFloors()
    {
        cout << "No floors in Multipurpose Building" << endl;
    }
    string selectFloor() override
    {
        displayFloors();
        floor.setFloorName("No Specific Floor");
        return getBuildingFloorName();
    }
    void describe() override
    {
        cout << "Multipurpose Building" << endl;
    }
};
Building *Building ::selectLocation()
{
    int choice;
    cout << "Select a building (1 for CS Building, 2 for EE Building, 3 for Multipurpose Building): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        return new CSBuilding(); // Assuming CSBuilding is a subclass of Building
    case 2:
        return new EEBuilding(); // Assuming EEBuilding is a subclass of Building
    case 3:
        return new MultipurposeBuilding(); // Assuming MultipurposeBuilding is a subclass of Building
    default:
        cout << "Invalid choice. Please select a valid building.";
        return nullptr;
    }
}
class SportsArea : public Location
{
public:
    void describe() override
    {
        cout << " sports area." << endl;
    }
    string getBuildingName() override
    {
        return "Sports Area";
    }
    string getBuildingFloorName() override
    {
        return "No Specific Floor";
    }
};
class CommonRoom : public Location
{
public:
    void describe() override
    {
        cout << "Common room for students." << endl;
    }
    string getBuildingName() override
    {
        return "Common Room";
    }
    string getBuildingFloorName() override
    {
        return "No Specific Floor";
    }
};

class Auditorium : public Location
{
public:
    void describe() override
    {
        cout << "University auditorium." << endl;
    }
    string getBuildingName() override
    {
        return "Auditorium";
    }
    string getBuildingFloorName() override
    {
        return "No Specific Floor";
    }
};
Location *Location::selectLocation()
{
    int locationChoice;
    cout << "Select Location: 4 for Auditorium, 5 for Common Room, 6 for Multipurpose Building: ";
    cin >> locationChoice;
    switch (locationChoice)
    {
    case 4:
        return new Auditorium();
    case 5:
        return new CommonRoom();
    case 6:
        return new SportsArea();
    default:
        return nullptr;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Student;
class User
{
protected:
    Location *location;
    string name;
    string phoneNo;
    string rollNo;

public:
    User() {}
    User(const string &name) : name(name) {}
    User(Location *location) : location(location) {}
    virtual void describeUser() = 0;
    virtual ~User() {}
    friend ostream &operator<<(ostream &os, const Student &e);
    friend istream &operator>>(istream &is, Student &e);
};

class Student : public User
{
public:
    Student() {}
    Student(Location *location) : User(location) {}
    void describeUser() override
    {
        cout << "Student " << name << " placing an order from ";
        location->describe();
    }
    friend ostream &operator<<(ostream &os, const Student &e);
    friend istream &operator>>(istream &is, Student &e);
    string getName()
    {
        return name;
    }
    string getPhoneNo()
    {
        return phoneNo;
    }
    string getRollNo()
    {
        return rollNo;
    }
    string getLocation()
    {
        return location->getBuildingName();
    }
    string getFloor()
    {
        return location->getBuildingFloorName();
    }
};

ostream &operator<<(ostream &os, const Student &e) // Overloading << operator
{
    os << endl;
    os << "-----------------------------------------------------------------" << endl;
    os << "Student's name :" << e.name << endl;
    os << "Student's Roll No: " << e.rollNo << endl;
    os << "Student's Phone No: " << e.phoneNo << endl;

    if (e.location != nullptr)
    {
        os << "Student's Location" << e.location->getBuildingName();
    }
    return os;
}
istream &operator>>(istream &is, Student &e)
{
    cout << "Enter student's name: ";
    getline(is, e.name);
    cout << "Enter the student's roll No: ";
    getline(cin, e.rollNo);
    cout << "Enter the student's phone No: ";
    getline(cin, e.phoneNo);

    int choice;
    cout << "Choose 1 if you want to order from the building or 2 for some other location: ";
    cin >> choice;
    if (choice == 1)
        e.location = Building::selectLocation();
    else if (choice == 2)
        e.location = Location::selectLocation();
    return is;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

    // Menu &operator=(const Menu &other)
    // {
    //     if (this != &other)
    //     {
    //         delete[] items;
    //         delete[] prices;
    //         size = other.size;
    //         items = new string[size];
    //         prices = new double[size];
    //         for (int i = 0; i < size; i++)
    //         {
    //             items[i] = other.items[i];
    //             prices[i] = other.prices[i];
    //         }
    //     }
    //     return *this;
    // }

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
    const double &getPrice(int index) const
    {
        if (index >= 0 && index < size)
        {
            return prices[index];
        }
        else
        {
            static const double empty = -1.0;
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

    virtual void placeOrder() {}

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

    static Shop *createShop(int shopChoice);

    void processOrder(Location &location)
    {
        this->placeOrder();
        location.describe();
    }
    static void displayAllShops()
    {
        cout << "1. Shawarma Shop" << endl
             << "2. Pizza Fast" << endl
             << "3. Dhaba" << endl
             << "4. Juice Shop" << endl
             << "5. Soda Shop" << endl
             << "6. Cafeteria" << endl;
    }
    static int selectShop()
    {
        int shopChoice;
        cout << "Enter the Shop Choice: ";
        cin >> shopChoice;
        return shopChoice;
    }
};
class ShawarmaShop : public Shop
{
public:
    ShawarmaShop(string *menuItems, double *menuPrices, int size) : Shop("Shawarma Shop")
    {
        setMenu(size, menuItems, menuPrices);
    }
    ShawarmaShop() : Shop("shawarma Shop"){}; // Default constructor
    void placeOrder() override
    {
        displayMenu();
        char userChoice;
        while (true)
        {
            cout << "Do you want to order or leave? (y/n): ";
            cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y')
            {
                cout << "Enter the number of the item you want to order: ";
                int itemChoice;
                cin >> itemChoice;
                const int menuSize = menu->getSize(); // Use the getter for size
                if (itemChoice > 0 && itemChoice <= menuSize)
                {
                    cout << "Enter the quantity of the item: ";
                    int quantity;
                    cin >> quantity;
                    double totalPrice = menu->getPrice(itemChoice - 1) * quantity;

                    cout << "Order placed for " << quantity << " " << menu->getItem(itemChoice - 1) << " at Shawarma Shop" << endl
                         << "Thank you for ordering!" << endl;

                    std::ofstream billFile("bill.txt", std::ios::app); // Open in append mode
                    if (billFile.is_open())
                    {
                        billFile << "Quantity: " << quantity << "\n"
                                 << "Item: " << menu->getItem(itemChoice - 1) << "\n"
                                 << "Price: " << menu->getPrice(itemChoice - 1) << "\n"
                                 << "Total amount: " << totalPrice << "\n"
                                 << "Location: " << "Shawarma Shop" << "\n\n"; // Replace with actual location
                        billFile.close();
                    }
                    else
                    {
                        cout << "Unable to open file bill.txt" << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (userChoice == 'n' || userChoice == 'N')
            {
                break;
            }
            else
            {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
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
        char userChoice;
        while (true)
        {
            cout << "Do you want to order or leave? (y/n): ";
            cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y')
            {
                cout << "Enter the number of the item you want to order: ";
                int itemChoice;
                cin >> itemChoice;
                const int menuSize = menu->getSize(); // Use the getter for size
                if (itemChoice > 0 && itemChoice <= menuSize)
                {
                    cout << "Enter the quantity of the item: ";
                    int quantity;
                    cin >> quantity;
                    double totalPrice = menu->getPrice(itemChoice - 1) * quantity;

                    cout << "Order placed for " << quantity << " " << menu->getItem(itemChoice - 1) << " at Pizza Fast" << endl
                         << "Thank you for ordering!" << endl;

                    std::ofstream billFile("bill.txt", std::ios::app); // Open in append mode
                    if (billFile.is_open())
                    {
                        billFile << "Quantity: " << quantity << "\n"
                                 << "Item: " << menu->getItem(itemChoice - 1) << "\n"
                                 << "Price: " << menu->getPrice(itemChoice - 1) << "\n"
                                 << "Total amount: " << totalPrice << "\n"
                                 << "Location: " << "Pizza Fast" << "\n\n"; // Replace with actual location
                        billFile.close();
                    }
                    else
                    {
                        cout << "Unable to open file bill.txt" << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (userChoice == 'n' || userChoice == 'N')
            {
                break;
            }
            else
            {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
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
        char userChoice;
        while (true)
        {
            cout << "Do you want to order or leave? (y/n): ";
            cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y')
            {
                cout << "Enter the number of the item you want to order: ";
                int itemChoice;
                cin >> itemChoice;
                const int menuSize = menu->getSize(); // Use the getter for size
                if (itemChoice > 0 && itemChoice <= menuSize)
                {
                    cout << "Enter the quantity of the item: ";
                    int quantity;
                    cin >> quantity;
                    double totalPrice = menu->getPrice(itemChoice - 1) * quantity;

                    cout << "Order placed for " << quantity << " " << menu->getItem(itemChoice - 1) << " at Dhaba" << endl
                         << "Thank you for ordering!" << endl;

                    std::ofstream billFile("bill.txt", std::ios::app); // Open in append mode
                    if (billFile.is_open())
                    {
                        billFile << "Quantity: " << quantity << "\n"
                                 << "Item: " << menu->getItem(itemChoice - 1) << "\n"
                                 << "Price: " << menu->getPrice(itemChoice - 1) << "\n"
                                 << "Total amount: " << totalPrice << "\n"
                                 << "Location: " << "Dhaba" << "\n\n"; // Replace with actual location
                        billFile.close();
                    }
                    else
                    {
                        cout << "Unable to open file bill.txt" << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (userChoice == 'n' || userChoice == 'N')
            {
                break;
            }
            else
            {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
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
        char userChoice;
        while (true)
        {
            cout << "Do you want to order or leave? (y/n): ";
            cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y')
            {
                cout << "Enter the number of the item you want to order: ";
                int itemChoice;
                cin >> itemChoice;
                const int menuSize = menu->getSize(); // Use the getter for size
                if (itemChoice > 0 && itemChoice <= menuSize)
                {
                    cout << "Enter the quantity of the item: ";
                    int quantity;
                    cin >> quantity;
                    double totalPrice = menu->getPrice(itemChoice - 1) * quantity;

                    cout << "Order placed for " << quantity << " " << menu->getItem(itemChoice - 1) << " at Juice Shop" << endl
                         << "Thank you for ordering!" << endl;

                    std::ofstream billFile("bill.txt", std::ios::app); // Open in append mode
                    if (billFile.is_open())
                    {
                        billFile << "Quantity: " << quantity << "\n"
                                 << "Item: " << menu->getItem(itemChoice - 1) << "\n"
                                 << "Price: " << menu->getPrice(itemChoice - 1) << "\n"
                                 << "Total amount: " << totalPrice << "\n"
                                 << "Location: " << "Juice Shop" << "\n\n"; // Replace with actual location
                        billFile.close();
                    }
                    else
                    {
                        cout << "Unable to open file bill.txt" << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (userChoice == 'n' || userChoice == 'N')
            {
                break;
            }
            else
            {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
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
        char userChoice;
        while (true)
        {
            cout << "Do you want to order or leave? (y/n): ";
            cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y')
            {
                cout << "Enter the number of the item you want to order: ";
                int itemChoice;
                cin >> itemChoice;
                const int menuSize = menu->getSize(); // Use the getter for size
                if (itemChoice > 0 && itemChoice <= menuSize)
                {
                    cout << "Enter the quantity of the item: ";
                    int quantity;
                    cin >> quantity;
                    double totalPrice = menu->getPrice(itemChoice - 1) * quantity;

                    cout << "Order placed for " << quantity << " " << menu->getItem(itemChoice - 1) << " at Soda Shop" << endl
                         << "Thank you for ordering!" << endl;

                    std::ofstream billFile("bill.txt", std::ios::app); // Open in append mode
                    if (billFile.is_open())
                    {
                        billFile << "Quantity: " << quantity << "\n"
                                 << "Item: " << menu->getItem(itemChoice - 1) << "\n"
                                 << "Price: " << menu->getPrice(itemChoice - 1) << "\n"
                                 << "Total amount: " << totalPrice << "\n"
                                 << "Location: " << "Soda Shop" << "\n\n"; // Replace with actual location
                        billFile.close();
                    }
                    else
                    {
                        cout << "Unable to open file bill.txt" << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (userChoice == 'n' || userChoice == 'N')
            {
                break;
            }
            else
            {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
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
        char userChoice;
        while (true)
        {
            cout << "Do you want to order or leave? (y/n): ";
            cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y')
            {
                cout << "Enter the number of the item you want to order: ";
                int itemChoice;
                cin >> itemChoice;
                const int menuSize = menu->getSize(); // Use the getter for size
                if (itemChoice > 0 && itemChoice <= menuSize)
                {
                    cout << "Enter the quantity of the item: ";
                    int quantity;
                    cin >> quantity;
                    double totalPrice = menu->getPrice(itemChoice - 1) * quantity;

                    cout << "Order placed for " << quantity << " " << menu->getItem(itemChoice - 1) << " at Cafeteria" << endl
                         << "Thank you for ordering!" << endl;

                    std::ofstream billFile("bill.txt", std::ios::app); // Open in append mode
                    if (billFile.is_open())
                    {
                        billFile << "Quantity: " << quantity << "\n"
                                 << "Item: " << menu->getItem(itemChoice - 1) << "\n"
                                 << "Price: " << menu->getPrice(itemChoice - 1) << "\n"
                                 << "Total amount: " << totalPrice << "\n"
                                 << "Location: " << "Cafeteria" << "\n\n"; // Replace with actual location
                        billFile.close();
                    }
                    else
                    {
                        cout << "Unable to open file bill.txt" << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (userChoice == 'n' || userChoice == 'N')
            {
                break;
            }
            else
            {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
        }
    }
};

Shop *Shop::createShop(int shopChoice)
{
    switch (shopChoice)
    {
    case 1:
    {
        string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
        double menuPrices[] = {150, 200, 250, 160, 170};
        return new ShawarmaShop(menuItems, menuPrices, 5);
    }

    case 2:
    {
        string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
        double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
        return new PizzaFast(menuItems, menuPrices, 9);
    }

    case 3:
    {
        // Add more cases as needed for other shop choices
        string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
        double menuPrices[] = {50, 100, 150, 180, 120, 200};
        return new Dhaba(menuItems, menuPrices, 6);
    }

    case 4:
    {
        string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
        double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
        return new JuiceShop(menuItems, menuPrices, 9);
    }

    case 5:
    {
        string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
        double menuPrices[] = {30, 40, 50, 20, 25};
        return new SodaShop(menuItems, menuPrices, 5);
    }

    case 6:
    {
        string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
        double menuPrices[] = {20, 30, 40, 50};
        return new Cafeteria(menuItems, menuPrices, 4);
    }

    default:
        cout << "Invalid shop choice." << endl;
        return nullptr;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <string>

class Bill
{
private:
    std::string filename;
    Student student;
    double total;

public:
    Bill(const std::string &filename, const Student &student)
        : filename(filename), student(student), total(0.0) {}

    void addOrder(int quantity, const std::string &item, const std::string &shopName, double price)
    {
        total += price * quantity;

        std::ofstream file(filename, std::ios::app);

        if (file.is_open())
        {
            file << quantity << "\t" << item << "\t" << shopName << "\t" << price << "\n";
            file.close();
        }
        else
        {
            std::cout << "Unable to open file " << filename << "\n";
        }
    }

    void saveToFile()
    {
        std::ofstream file(filename, std::ios::app);

        if (file.is_open())
        {
            file << "Name: " << student.getName() << "\n";         // Assuming Student has a getName method
            file << "Phone No: " << student.getPhoneNo() << "\n";  // Assuming Student has a getPhoneNo method
            file << "Roll No: " << student.getRollNo() << "\n";    // Assuming Student has a getRollNo method
            file << "Location: " << student.getLocation() << "\n"; // Assuming Student has a getLocation method
            file << "----------------------------------------------------------------------------\n";
            file << "Total: " << total << "\n";
            file.close();
        }
        else
        {
            std::cout << "Unable to open file " << filename << "\n";
        }
    }
};
int main()
{
    cout << "Welcome to the FAST EATS APP!" << endl;
    cout << "Please select your role:" << endl;
    cout << "1. Student" << endl
         << "2. Faculty" << endl;
    int userchoice;
    cin >> userchoice;
    string name = "default";
    string buildingName;
    string floorName;
    int locationChoice;

    if (userchoice == 1)
    {

        Location::displayAllLocations();
        cout << "you want to order from the building or the other location: ";
        cin >> locationChoice;
        Building *building;
        Location *location;
        if (locationChoice == 1)
        {
            building = Building::selectLocation();
            if (building != nullptr)
            {
                string floorName = building->selectFloor();

                Student s(building);
                cout << "Enter the details:  " << endl;
                cin.ignore();
                cin >> s;

                s.describeUser();
                Shop::displayAllShops();
                int shopChoice = Shop::selectShop();

                Shop *shop = Shop::createShop(shopChoice);
                if (shop != nullptr)
                {
                    shop->processOrder(*location);
                }
                else
                {
                    cout << "Invalid shop choice......" << endl;
                }
                delete building;
            }
            else
            {
                cout << "Invalid location choice......" << endl;
            }
        }

        else if (locationChoice == 2)
        {
            location = Location::selectLocation();
            if (location != nullptr)
            {
                Student s;
                cout << "Enter the details:  " << endl;
                cin >> s;
                s.describeUser();
                Shop::displayAllShops();
                int shopChoice = Shop::selectShop();

                Shop *shop = Shop::createShop(shopChoice);
                if (shop != nullptr)
                {
                    shop->processOrder(*location);
                    delete location;
                }
                else
                {
                    cout << "Invalid shop choice......" << endl;
                    delete location;
                }
                // delete location; // Don't forget to delete the location pointer when you're done with it
            }
            else
            {
                cout << "Invalid location choice......" << endl;
            }
        }else
        {
            cout << "Invalid location choice......" << endl;
        }
    }
}