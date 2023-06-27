#include<iostream>
using namespace std;


class Player{
	private:
		int health;
		string name;
	public:
		// automatic initialization
		Player():health(0), name("\0")
		{
			
		}
		// argument constructor
		Player(int h, string n):health(h), name(n)
		{
			
		}
		void display_details(){
			cout<<"Player Name: "<<name<<endl;
			cout<<"Health: "<<health<<endl;
		}
};

class Shooter: public Player{
	private:
		int ammo;
	public:
		Shooter():ammo(0){
			
		}
		Shooter(int h, string n, int m):Player(h,n)
		{
			ammo = m;
		}
		
		void display_details(){
			Player::display_details();
			cout<<"Number of Ammos: "<<ammo<<endl;
		}
		
		
};



int main(){
	Shooter s1(100, "Victor", 200);
	s1.display_details();
	
}
