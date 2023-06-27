#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Room class represents a hotel room
class Room {
private:
    int roomNumber;
    int pricePerNight;
    bool availability;
    char typeOfRoom[9];

public:
    Room() : roomNumber(0), availability(true), pricePerNight(0) {}
    
    Room(int _roomNumber, bool _availability, int _pricePerNight, string& roomType) :
	roomNumber(_roomNumber), availability(_availability), pricePerNight(_pricePerNight){
		size_t length = roomType.size();
		length = (length < 9 ? length : 8);
		typeOfRoom[length] = '\0';
		roomType.copy(typeOfRoom, length);
	}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool isAvailable() const {
        return availability;
    }

    void setAvailability(bool _availability) {
        availability = _availability;
    }

    void display() const {
        cout << setw(20) << left << "Room Number: " << setw(10) << left << roomNumber << endl;
        cout << setw(20) << left << "Availability: " << setw(10) << left << (availability ? "Available" : "Booked") << endl;
        cout << setw(20) << left << "Price of the Room: " << setw(10) << left << pricePerNight << endl;
        cout << setw(20) << left << "Room Type: " << setw(10) << left << typeOfRoom << endl;
    }
};

// Customer class represents a hotel customer
class Customer {
private:
    char nameOfCustomer[20];
    int roomNumber;
    char CNIC[14];
    
public:
	Customer(){
	}
    Customer(const string& customerName, int roomNum, string& _CNIC) :
	roomNumber(roomNum) {
		size_t lengthOfName = customerName.size();
		lengthOfName = (lengthOfName < 20 ? lengthOfName : 19);
		nameOfCustomer[lengthOfName] = '\0';
		customerName.copy(nameOfCustomer, lengthOfName);
		
		size_t lengthOfID = _CNIC.size();
		lengthOfID = (lengthOfID < 14 ? lengthOfID : 13);
		CNIC[lengthOfID] = '\0';
		_CNIC.copy(CNIC, lengthOfID);
	}

    string getName() const {
        return nameOfCustomer;
    }

    int getRoomNumber() const {
        return roomNumber;
    }

    void display() const {
        cout << setw(16) << left << "Name: " << setw(20) << left << nameOfCustomer << endl;
        cout << setw(16) << left << "Room Number: " << setw(10) << left << roomNumber << endl;
        cout << setw(16) << left << "Customer ID: " << setw(10) << left << CNIC << endl;
    }
};

// Hotel class manages the hotel rooms and customers
class Hotel {
private:
    string FILENAME = "rooms.dat";
    static const int MAX_ROOMS = 100;

    Room rooms[MAX_ROOMS];
    int numRooms;

public:
    Hotel() : numRooms(0) {}

    void loadRooms() {
        ifstream inFile(FILENAME, ios::binary);
        if (!inFile) {
            cout << "Error opening file." << endl;
            return;
        }

        inFile.read(reinterpret_cast<char*>(&numRooms), sizeof(numRooms));
        inFile.read(reinterpret_cast<char*>(rooms), sizeof(rooms));

        inFile.close();
    }

    void saveRooms() {
        ofstream outFile(FILENAME, ios::binary);
        if (!outFile) {
            cout << "Error opening file." << endl;
            return;
        }

        outFile.write(reinterpret_cast<const char*>(&numRooms), sizeof(numRooms));
        outFile.write(reinterpret_cast<const char*>(rooms), sizeof(rooms));

        outFile.close();
    }

    void addRoom(int roomNumber, string roomType, int pricePerNight) {
        if (numRooms >= MAX_ROOMS) {
            cout << "Cannot add more rooms. Maximum capacity reached." << endl;
            system("pause");
            return;
        }

        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].getRoomNumber() == roomNumber) {
                cout << "Room number already exists." << endl;
                system("pause");
				return;
            }
        }
        
        	
		rooms[numRooms] = Room(roomNumber, true, pricePerNight, roomType);
        numRooms++;

        saveRooms();
        cout << "Room added successfully." << endl;
        system("pause");
    }

    void deleteRoom(int roomNumber) {
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].getRoomNumber() == roomNumber) {
                if (!rooms[i].isAvailable()) {
                    cout << "Cannot delete a booked room." << endl;
                    system("pause");
                    return;
                }

                rooms[i] = rooms[numRooms - 1];
                numRooms--;
                saveRooms();
                cout << "Room deleted successfully." << endl;
                system("pause");
                return;
            }
        }

        cout << "Room Doesn't Exist in our Records." << endl;
        system("pause");
    }

    void displayAllRooms() const {
    	system("cls");
        cout << "All Rooms:" << endl;
        for (int i = 0; i < numRooms; i++) {
            rooms[i].display();
            cout << endl;
        }
        system("pause");
    }

    void bookRoom(const string& customerName, int roomNumber, string customerCNIC) {
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].getRoomNumber() == roomNumber) {
                if (!rooms[i].isAvailable()) {
                    cout << "Room is already Booked by Someone else." << endl;
                    system("pause");
					return;
                }

                rooms[i].setAvailability(false);
                saveRooms();

                Customer customer(customerName, roomNumber, customerCNIC);
                saveCustomer(customer);

                cout << "Room has been Booked Successfully." << endl;
                system("pause");
				return;
            }
        }

        cout << "Room Doesn't Exist in our Records." << endl;
        system("pause");
    }

    void checkoutRoom(int roomNumber) {
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i].getRoomNumber() == roomNumber) {
                if (rooms[i].isAvailable()) {
                    cout << "Room is already Available and not Booked by Anyone." << endl;
                    system("pause");
                    return;
                }

                rooms[i].setAvailability(true);
                saveRooms();

                deleteCustomer(roomNumber);
                cout << "Room has Been Checked out Successfully." << endl;
                system("pause");
				return;
            }
        }

        cout << "Room doesn't Exist in our Records." << endl;
        system("pause");
    }

    void displayAllCustomers() const {
    	system("cls");
        ifstream inFile("customers.dat", ios::binary);
        if (!inFile) {
            cout << "Currently No Customers Exist in our Records." << endl;
            system("pause");
            return;
        }

        Customer customer;
        while (inFile.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
            customer.display();
            cout << endl;
        }

        inFile.close();
        system("pause");
    }

    void saveCustomer(const Customer& customer) {
        ofstream outFile("customers.dat", ios::binary | ios::app);
        if (!outFile) {
            cout << "Error Opening File." << endl;
            system("pause");
			return;
        }

        outFile.write(reinterpret_cast<const char*>(&customer), sizeof(Customer));
        outFile.close();
    }

    void deleteCustomer(int roomNumber) {
        ifstream inFile("customers.dat", ios::binary);
        if (!inFile) {
            cout << "Currently No Customers exist in our records." << endl;
            system("pause");
			return;
        }

        ofstream outFile("temp.dat", ios::binary);
        if (!outFile) {
            cout << "Error opening file." << endl;
            inFile.close();
            system("pause");
            return;
        }

        Customer customer;
        bool found = false;
        while (inFile.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
            if (customer.getRoomNumber() == roomNumber) {
                found = true;
            }
            else {
                outFile.write(reinterpret_cast<const char*>(&customer), sizeof(Customer));
            }
        }

        inFile.close();
        outFile.close();

        remove("customers.dat");
        rename("temp.dat", "customers.dat");

        if (!found) {
            cout << "Customer don't Exist in our Records." << endl;
        }
        system("pause");
    }
};

//Validation Functions

bool isValidCNIC(string& cnic){
	if( cnic.length() != 13 )
	return false;
	
	for(int i = 0; i < 13; i++){
		if(!isdigit(cnic[i]))
		return false;
	}
	return true;
}


int inputValidation(int lRange = 0, int uRange = 99){
	int x;
	while(true){
		if(cin.good()){
			cin >> x;
			if(x >= lRange && x <= uRange)	
			break;
		}
		cin.clear();
		cout << "Invalid Input!\nPlease Select Valid Number From the Menu!\nEnter Your Choice: ";
		cin.ignore(123, '\n');
	}
	return x;
}

// Function to display the menu and handle user input
int showMenu() {
    int choice;
    system("cls");
    cout << "=====================" << endl;
    cout << "Hotel Room Management" << endl;
    cout << "=====================" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Delete Room" << endl;
    cout << "3. Display All Rooms" << endl;
    cout << "4. Book Room" << endl;
    cout << "5. Checkout Room" << endl;
    cout << "6. Display All Customers" << endl;
    cout << "7. Quit" << endl;
    cout << "Enter your choice: ";
    choice = inputValidation(1,7);
    cout << endl;
    return choice;
}

int main() {
    Hotel hotel;
    hotel.loadRooms();

    int choice;
    do {
        choice = showMenu();

        switch (choice) {
            case 1: {
            	system("cls");
                int roomNumber, priceOfRoom;
                string roomType;
                cout << "Enter room number: ";
                roomNumber = inputValidation(1,101);
                cout << "Room Type? Enter\nStandard for Standard Room\nLuxury for Luxury Room\nSuite for Suite\n";
                while(true)
                {
                	cin >> roomType;
                	if(roomType == "Standard" || roomType == "standard"){
                		roomType[0] = 'S';
                		break;
					}
					else if(roomType == "Luxury" || roomType == "luxury"){
						roomType[0] = 'L';
						break;
					}
					else if(roomType == "Suite" || roomType == "suite"){
						roomType[0] = 'S';
						break;
					}
					else{
						cout << "Please Enter Correct Room Type: " << endl;
					}
				}
                cout << "Enter Price of Room For One Night: ";
                priceOfRoom = inputValidation(500,1500);
                hotel.addRoom(roomNumber, roomType, priceOfRoom);
                break;
            }
            case 2: {
            	system("cls");
                int roomNumber;
                cout << "Enter room number: ";
                roomNumber = inputValidation(1,101);
                hotel.deleteRoom(roomNumber);
                break;
            }
            case 3:{
                hotel.displayAllRooms();
                break;
        	}
            case 4: {
                string customerName, cnicOfCustomer;
                int roomNumber;
                system("cls");
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, customerName);
                cout << "Enter room number: ";
                roomNumber = inputValidation(1,101);
                cout << "Enter CNIC Number: ";
                cin.ignore();
				getline(cin, cnicOfCustomer);
				if(!isValidCNIC(cnicOfCustomer)){
					bool flag = true;
					while(flag){
						cout << "Please Enter Valid CNIC Number: " << endl;
						getline(cin, cnicOfCustomer);
						if(isValidCNIC(cnicOfCustomer)){
							flag = false;
						}
					}
				}
                hotel.bookRoom(customerName, roomNumber, cnicOfCustomer);
                break;
            }
            case 5: {
                int roomNumber;
                cout << "Enter room number: ";
                roomNumber = inputValidation(1,101);
                hotel.checkoutRoom(roomNumber);
                break;
            }
            case 6:{
                hotel.displayAllCustomers();
                break;
            }
            case 7:{
                cout << "Exiting program." << endl;
                system("pause");
				break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}

