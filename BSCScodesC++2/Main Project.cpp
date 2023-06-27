#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Hotel{
	int noOfRooms;
	//Default Constructor
	public:
		Hotel(){
		}
		Hotel(int _noOfRooms):noOfRooms(_noOfRooms) {
		}
		void setNoRooms(int _n){
			noOfRooms = _n;
		}
		int getNoRooms(){
			return noOfRooms;
		}
	
};

class Room: public Hotel{

	int roomNumber;
	string roomType;
	int rentOfRoom;
	public:
		Room(){
		
		}
		Room(int _roomNumber , string _roomType , int _rentOfRoom):roomNumber(_roomNumber) , roomType(_roomType) , rentOfRoom(_rentOfRoom){
		
		}
		void setRoomNumber(int _roomNumber){
			roomNumber=_roomNumber;
		}
		int getRoomNumber(){
			return roomNumber;
		}
		void setRoomType(string _roomType){
			roomType=_roomType;
		}
		string getRoomType(){
			return roomType;
		}
		void setRentOfRoom(int _rentOfRoom){
			rentOfRoom=_rentOfRoom;
		}
		int getRentOfRoom(){
			return rentOfRoom;
		}
};

class Customer: public Hotel, public Room{

	string customerName;
	int customerID;
	string checkIn;
	string checkOut;
	public:
		Customer(){
		
		}
		Customer(string _customerName , int _customerID , string _checkIn ,string _checkOut): customerName(_customerName) , customerID(_customerID) , checkIn(_checkIn) , checkOut(_checkOut){
		
		}
		void setCustomerName(string _customerName){
			customerName = _customerName;
		}
		string getCustomerName(){
			return customerName;
		}
		void setCustomerID(int _customerID){
			customerID = _customerID;
		}
		int getCustomerID(){
			return customerID;
		}
		void setCheckIn(string _checkIn){
			checkIn = _checkIn;
		}
		string getCheckIn(){
			return checkIn;
		}
		void setCheckOut(string _checkOut){
			checkOut = _checkOut;
		}
		string getCheckOut(){
		return checkOut;
		}
};

int main(){
	menu:
	cout << "\n\n";
	cout << setw(71) << setfill('~') << " Hotel Management System ";
	cout << setw(49) << setfill('~') << "~";
	while(true){
		cout << "MENU" << endl;
		cout << "1: Show Available Rooms" << endl;
		cout << "2: Book a Room" << endl;
		cout << "3: Rooms Details" << endl;
		cout << "4: Customers Details" << endl;
		cout << "5: Delete a Booking" << endl;
		cout << "6: Exit" << endl;
		int choice;
		cin >> choice;
		if( choice == 1 ){
			cout << "1";
			system("pause");
			system("cls");
			goto menu;
		}
		else if( choice == 2 ){
			cout << "Book Room";
			system("pause");
			system("cls");
			goto menu;
		}
		else if( choice == 3 ){
			cout << "Booking";
			system("pause");
			system("cls");
			goto menu;
		}
		else if( choice == 4 ){
			cout << "Booking";
			system("pause");
			system("cls");
			goto menu;
		}
		else if( choice == 5 ){
			cout << "Booking";
			system("pause");
			system("cls");
			goto menu;
		}
		else if( choice == 6 ){
			break;
			goto menu;
		}
		else{
			cout << "Invalid Input Please Try Again!" << endl;
			system("pause");
			system("cls");
			goto menu;
		}
	}
	cout << "Thank You For Using!";
}
