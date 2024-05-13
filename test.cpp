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
    virtual ~Location() {}
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
    string getBuildingName()
    {
        return buildingName;
    }
    void setFloorName(string floorName)
    {
        floor.setFloorName(floorName);
    }
    string getBuildingFloorName()
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
                do{
        cout << "Select the floor: ";
        cin >> floorChoice;
        if (floorChoice != 0 && floorChoice != 1 && floorChoice != 2){
            cout << "Invalid choice\nAgain" ;
        } 
    }while (floorChoice != 0 && floorChoice != 1 && floorChoice != 2);
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
    void describe(){
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
    string getBuildingName()
    {
        return buildingName;
    }
    void setFloorName(string floorName)
    {
        floor.setFloorName(floorName);
    }
    string getBuildingFloorName()
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
                do{
        cout << "Select the floor: ";
        cin >> floorChoice;
        if (floorChoice != 0 && floorChoice != 1 && floorChoice != 2 && floorChoice != 3 && floorChoice != 4){
            cout << "Invalid choice\nAgain" ;
        } 
    }while (floorChoice != 0 && floorChoice != 1 && floorChoice != 2 && floorChoice != 3 && floorChoice != 4);
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
    void describe()
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
    string getBuildingName()
    {
        return buildingName;
    }
    void setFloorName(string floorName)
    {
        floor.setFloorName(floorName);
    }
    string getBuildingFloorName()
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
class SportsArea : public Location
{
public:
    void describe() override
    {
        cout << " sports area." << endl;
    }
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class User
{
protected:
    string name;
    Location *location;

public:
    User() {} 
    User(const string &name):name(name) {} 
    User(const string &name, Location *location) : name(name), location(location) {}
    virtual void describeUser() = 0;
    virtual ~User() {}
friend ostream &operator<<( ostream &os, const Student &e );
friend istream &operator>>( istream &is, Student &e );
};

class Student : public User
{
    double phoneNumber;
public:
    Student(){}
    Student(const string &name, Location *location, double phoneNumber) : User(name, location) ,phoneNumber(phoneNumber) {}
    void describeUser() override
    {
        cout << "Student " << name << " placing an order from ";
        location->describe();
    }
friend ostream &operator<<( ostream &os, const Student &e );
friend istream &operator>>( istream &is, Student &e );

};

ostream& operator<<(ostream& os, const Student& e) //Overloading << operator
{
    os <<"Student's name :" << e.name;
    os <<"Student's Phone Number"<< e.phoneNumber;
    os <<"Student's Location" << e.location;
return os;
}
istream &operator>>(istream &is, Student &e) {
    cout << "Enter student's name: ";
    getline(is, e.name);
    cout << "Enter student's phone number: ";
    is >> e.phoneNumber;
}
class Faculty : public User
{
    int extentionNumber;
    string officeLocation;

public:
    Faculty(const string &name, int extensionNumber,string officeLocation) :extentionNumber(extentionNumber),officeLocation(officeLocation) ,User(name) {}
    void describeUser() override
    {
        cout << "Faculty " << name << " placing an order from ";
        location->describe();
    }
friend ostream &operator<<( ostream &os, const Faculty &e );
friend istream &operator>>( istream &is, Faculty &e );

};

ostream& operator<<(ostream& os, const Faculty& e) //Overloading << operator
{
    os <<"Teacher's name :" << e.name;
    os <<"Teacher's Extension Number"<< e.extentionNumber;
    os <<"Teacher's Office location" << e.officeLocation;
return os;
}
istream &operator>>(istream &is, Faculty &e) {
    cout << "Enter Teacher's name: ";
    getline(is, e.name);
    cout << "Enter Teacher's Extention number: ";
    is >> e.extentionNumber;
    cout << "Enter Teacher's Location: ";
    getline(is, e.officeLocation);
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
        int choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        do
        {
        cout << "Enter the number of the item you want to order: " <<endl;
        cin >> choice;
        if (choice <= 0 || choice > menuSize)
        {
            cout << "Invalid Input!\nAgain";
        }
        
        } while (choice <= 0 || choice > menuSize);
        cout << "Order placed for " << menu->getItem(choice - 1) << " at Shawarma Shop" << endl
                 << "Thank you for ordering!" << endl;
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
        int choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        do
        {
        cout << "Enter the number of the item you want to order: " <<endl;
        cin >> choice;
        if (choice <= 0 || choice > menuSize)
        {
            cout << "Invalid Input!\nAgain";
        }
        
        } while (choice <= 0 || choice > menuSize);
        cout << "Order placed for " << menu->getItem(choice - 1) << " at Pizza Fast" << endl
                 << "Thank you for ordering!" << endl;
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
        int choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        do
        {
        cout << "Enter the number of the item you want to order: " <<endl;
        cin >> choice;
        if (choice <= 0 || choice > menuSize)
        {
            cout << "Invalid Input!\nAgain";
        }
        
        } while (choice <= 0 || choice > menuSize);
        cout << "Order placed for " << menu->getItem(choice - 1) << " at Dhaba" << endl
                 << "Thank you for ordering!" << endl;
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
        int choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        do
        {
        cout << "Enter the number of the item you want to order: " <<endl;
        cin >> choice;
        if (choice <= 0 || choice > menuSize)
        {
            cout << "Invalid Input!\nAgain";
        }
        
        } while (choice <= 0 || choice > menuSize);
        cout << "Order placed for " << menu->getItem(choice - 1) << " at juics Shop" << endl
                 << "Thank you for ordering!" << endl;
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
        int choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        do
        {
        cout << "Enter the number of the item you want to order: " <<endl;
        cin >> choice;
        if (choice <= 0 || choice > menuSize)
        {
            cout << "Invalid Input!\nAgain";
        }
        
        } while (choice <= 0 || choice > menuSize);
        cout << "Order placed for " << menu->getItem(choice - 1) << " at Soda Shop" << endl
                 << "Thank you for ordering!" << endl;
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
        int choice;
        const int menuSize = menu->getSize(); // Use the getter for size
        do
        {
        cout << "Enter the number of the item you want to order: " <<endl;
        cin >> choice;
        if (choice <= 0 || choice > menuSize)
        {
            cout << "Invalid Input!\nAgain";
        }
        
        } while (choice <= 0 || choice > menuSize);
        cout << "Order placed for " << menu->getItem(choice - 1) << " at Cafeteria" << endl
                 << "Thank you for ordering!" << endl;
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
void checkShopChoice(int shopchoice)
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "Welcome to the FAST EATS APP!" << endl;

    string name;
    string buildingName;
    string floorName;
    int locationChoice;
    int shopchoice;
    int userchoice;

    do
    {
        cout << "Please select your role:" << endl;
        cout << "1. Student" << endl
             << "2. Faculty" << endl;
        cin >> userchoice;
        if (userchoice != 1 && userchoice != 2)
        {
            cout << "Invalid choice\nAgain" << endl;
        }
    } while (userchoice != 1 && userchoice != 2);

    if (userchoice == 1)
    {
        // cout << "Enter your Name: ";
        //  getline(cin, name);
        do
        {

            cout << "Select Location i.e{1,2,3,4,5,6}: " << endl;
            cout << "1. CS Building" << endl
                 << "2. EE Building " << endl
                 << "3. Multipurpose Building" << endl
                 << "4. Sports Area" << endl
                 << "5. Auditoriam" << endl
                 << "6. Common Room" << endl;
            cin >> locationChoice;
            if (locationChoice != 1 && locationChoice != 2 && locationChoice != 3 && locationChoice != 4 && locationChoice != 5 && locationChoice != 6)
            {
                cout << "Invalid choice\nAgain" << endl;
            }
        } while (locationChoice != 1 && locationChoice != 2 && locationChoice != 3 && locationChoice != 4 && locationChoice != 5 && locationChoice != 6);

        if (locationChoice == 1)
        {
            CSBuilding cs;
            string floorName = cs.selectFloor();
            cs.setBuildingName("CS Building");
            cs.setFloorName(floorName);
            Student s;
            cin >> s;
            s.describeUser();
            do
            {
                cout << "Enter the Shop Choice i.e{1,2,3,4,5,6}: " << endl;
                cout << "1. Shawarma Shop" << endl
                     << "2. Pizza Fast" << endl
                     << "3. Dhaba" << endl
                     << "4. Juice Shop" << endl
                     << "5. Soda Shop" << endl
                     << "6. Cafeteria" << endl;
                cin >> shopchoice;
                if (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6)
                {
                    cout << "Invalid choice\nAgain" << endl;
                }
            } while (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6);

            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                cs.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                cs.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                cs.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
                js.placeOrder();
                cs.describe();
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
                double menuPrices[] = {30, 40, 50, 20, 25};
                SodaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                cs.describe();
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
                double menuPrices[] = {20, 30, 40, 50};
                Cafeteria c(menuItems, menuPrices, 4);
                c.placeOrder();
                cs.describe();
            }
        }
        else if (locationChoice == 2)
        {
            EEBuilding ee;
            string floorName = ee.selectFloor();
            ee.setBuildingName("EE Building");
            ee.setFloorName(floorName);
            Student s;
            cin >> s;
            s.describeUser();
            do
            {
                cout << "Enter the Shop Choice i.e{1,2,3,4,5,6}: " << endl;
                cout << "1. Shawarma Shop" << endl
                     << "2. Pizza Fast" << endl
                     << "3. Dhaba" << endl
                     << "4. Juice Shop" << endl
                     << "5. Soda Shop" << endl
                     << "6. Cafeteria" << endl;
                cin >> shopchoice;
                if (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6)
                {
                    cout << "Invalid choice\nAgain" << endl;
                }
            } while (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6);
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                ee.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                ee.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                ee.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
                js.placeOrder();
                ee.describe();
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
                double menuPrices[] = {30, 40, 50, 20, 25};
                SodaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                ee.describe();
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
                double menuPrices[] = {20, 30, 40, 50};
                Cafeteria c(menuItems, menuPrices, 4);
                c.placeOrder();
                ee.describe();
            }
        }
        else if (locationChoice == 3)
        {
            MultipurposeBuilding mp;
            string floorName = mp.selectFloor();
            mp.setBuildingName("Multipurpose Building");
            mp.setFloorName(floorName);
            Student s;
            cin >> s;
            s.describeUser();
            do
            {
                cout << "Enter the Shop Choice i.e{1,2,3,4,5,6}: " << endl;
                cout << "1. Shawarma Shop" << endl
                     << "2. Pizza Fast" << endl
                     << "3. Dhaba" << endl
                     << "4. Juice Shop" << endl
                     << "5. Soda Shop" << endl
                     << "6. Cafeteria" << endl;
                cin >> shopchoice;
                if (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6)
                {
                    cout << "Invalid choice\nAgain" << endl;
                }
            } while (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6);
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                mp.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                mp.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                mp.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
                js.placeOrder();
                mp.describe();
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
                double menuPrices[] = {30, 40, 50, 20, 25};
                SodaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                mp.describe();
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
                double menuPrices[] = {20, 30, 40, 50};
                Cafeteria c(menuItems, menuPrices, 4);
                c.placeOrder();
                mp.describe();
            }
        }
        else if (locationChoice == 4)
        {
            SportsArea sa;
            Student s;
            cin >> s;
            s.describeUser();
            do
            {
                cout << "Enter the Shop Choice i.e{1,2,3,4,5,6}: " << endl;
                cout << "1. Shawarma Shop" << endl
                     << "2. Pizza Fast" << endl
                     << "3. Dhaba" << endl
                     << "4. Juice Shop" << endl
                     << "5. Soda Shop" << endl
                     << "6. Cafeteria" << endl;
                cin >> shopchoice;
                if (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6)
                {
                    cout << "Invalid choice\nAgain" << endl;
                }
            } while (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6);
            cin >> shopchoice;
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                sa.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                sa.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                sa.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
                double menuPrices[] = {30, 40, 50, 20, 25};
                SodaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                sa.describe();
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
                double menuPrices[] = {20, 30, 40, 50};
                Cafeteria c(menuItems, menuPrices, 4);
            }
        }
        else if (locationChoice == 5)
        {
            Auditorium a;
            Student s;
            cin >> s;
            s.describeUser();
            do
            {
                cout << "Enter the Shop Choice i.e{1,2,3,4,5,6}: " << endl;
                cout << "1. Shawarma Shop" << endl
                     << "2. Pizza Fast" << endl
                     << "3. Dhaba" << endl
                     << "4. Juice Shop" << endl
                     << "5. Soda Shop" << endl
                     << "6. Cafeteria" << endl;
                cin >> shopchoice;
                if (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6)
                {
                    cout << "Invalid choice\nAgain" << endl;
                }
            } while (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6);
            cin >> shopchoice;
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                a.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                a.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                a.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
            }
        }
        else if (locationChoice == 6)
        {
            CommonRoom cr;
            Student s;
            cin >> s;
            s.describeUser();
            do
            {
                cout << "Enter the Shop Choice i.e{1,2,3,4,5,6}: " << endl;
                cout << "1. Shawarma Shop" << endl
                     << "2. Pizza Fast" << endl
                     << "3. Dhaba" << endl
                     << "4. Juice Shop" << endl
                     << "5. Soda Shop" << endl
                     << "6. Cafeteria" << endl;
                cin >> shopchoice;
                if (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6)
                {
                    cout << "Invalid choice\nAgain" << endl;
                }
            } while (shopchoice != 1 && shopchoice != 2 && shopchoice != 3 && shopchoice != 4 && shopchoice != 5 && shopchoice != 6);
            if (shopchoice == 1)
            {
                string menuItems[] = {"chicken Shawarma", "Zinger Shawarma", "Zinger Cheese Shawarma", "Chicken Mayo Shawarma", "Chicken Cheese Shawarma"};
                double menuPrices[] = {150, 200, 250, 160, 170};
                ShawarmaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                cr.describe();
            }
            else if (shopchoice == 2)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Box Patties", "Samosa", "Shami Burger", "Spring Roll", "Cold Drinks", "Juice", "Water Bottle"};
                double menuPrices[] = {50, 100, 70, 10, 100, 50, 80, 60, 50};
                PizzaFast pf(menuItems, menuPrices, 9);
                pf.placeOrder();
                cr.describe(); // Assuming you want to describe the CSBuilding again
            }
            else if (shopchoice == 3)
            {
                string menuItems[] = {"Fries(small)", "Fries(regular)", "Chicken Biryani", "Beef Biryani", "Veg Biryani", "Mutton Biryani"};
                double menuPrices[] = {50, 100, 150, 180, 120, 200};
                Dhaba d(menuItems, menuPrices, 6);
                d.placeOrder();
                cr.describe();
            }
            else if (shopchoice == 4)
            {
                string menuItems[] = {"Apple Juice", "Peach Juice", "Blue Berry", "Orange Juice", "Mango Juice", "Strawberry Juice", "Pineapple Juice", "Watermelon Juice", "Banana Juice"};
                double menuPrices[] = {50, 60, 70, 40, 80, 90, 100, 30, 20};
                JuiceShop js(menuItems, menuPrices, 9);
                js.placeOrder();
                cr.describe();
            }
            else if (shopchoice == 5)
            {
                string menuItems[] = {"Soda", "Coke", "Pepsi", "Sprite", "Fanta"};
                double menuPrices[] = {30, 40, 50, 20, 25};
                SodaShop ss(menuItems, menuPrices, 5);
                ss.placeOrder();
                cr.describe();
            }
            else if (shopchoice == 6)
            {
                string menuItems[] = {"Lemonade", "Hot Coffee", "Cold Coffee", "Lemonade+FizzUp"};
                double menuPrices[] = {20, 30, 40, 50};
                Cafeteria c(menuItems, menuPrices, 4);
                c.placeOrder();
                cr.describe();
            }
        }
    }
}
