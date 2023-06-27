#include <iostream>
#include <vector>

// Class to represent a Room
class Room {
public:
    int roomNumber;
    std::string type;
    bool isAvailable;

    Room(int number, std::string roomType) : roomNumber(number), type(std::move(roomType)), isAvailable(true) {}
};

// Class to represent a Customer
class Customer {
public:
    std::string name;
    std::string contactNumber;
    Room* bookedRoom;

    Customer(const std::string& customerName, const std::string& contact) : name(customerName), contactNumber(contact), bookedRoom(nullptr) {}
};

// Class to represent the Hotel
class Hotel {
private:
    std::vector<Room> rooms;
    std::vector<Customer> customers;

public:
    Hotel() {
        // Initialize the rooms
        rooms.emplace_back(Room(101, "Single"));
        rooms.emplace_back(Room(102, "Double"));
        rooms.emplace_back(Room(103, "Suite"));
    }

    // Method to display the available rooms
    void displayAvailableRooms() {
        std::cout << "Available Rooms:\n";
        for (const Room& room : rooms) {
            if (room.isAvailable) {
                std::cout << "Room Number: " << room.roomNumber << ", Type: " << room.type << "\n";
            }
        }
    }

    // Method to book a room for a customer
    void bookRoom(Customer& customer, int roomNumber) {
        for (Room& room : rooms) {
            if (room.roomNumber == roomNumber && room.isAvailable) {
                customer.bookedRoom = &room;
                room.isAvailable = false;
                std::cout << "Room " << roomNumber << " booked successfully for customer " << customer.name << ".\n";
                return;
            }
        }
        std::cout << "Room " << roomNumber << " is not available.\n";
    }

    // Method to display customer details
    void displayCustomerDetails() {
        std::cout << "Customer Details:\n";
        for (const Customer& customer : customers) {
            std::cout << "Name: " << customer.name << ", Contact: " << customer.contactNumber;
            if (customer.bookedRoom != nullptr) {
                std::cout << ", Room: " << customer.bookedRoom->roomNumber;
            }
            std::cout << "\n";
        }
    }

    // Method to add a customer to the hotel
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }
};

int main() {
    Hotel hotel;

    int choice;
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Display available rooms\n";
        std::cout << "2. Book a room\n";
        std::cout << "3. Display customer details\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            hotel.displayAvailableRooms();
        } else if (choice == 2) {
            std::string name, contact;
            int roomNumber;
            std::cout << "Enter customer name: ";
            std::cin >> name;
            std::cout << "Enter contact number: ";
            std::cin >> contact;
            std::cout << "Enter room number to book: ";
            std::cin >> roomNumber;
            Customer newCustomer(name, contact);
            hotel.bookRoom(newCustomer, roomNumber);
            hotel.addCustomer(newCustomer); // Add the customer to the hotel
        } else if (choice == 3) {
            hotel.displayCustomerDetails();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << "\n";
    }

    return 0;
}

