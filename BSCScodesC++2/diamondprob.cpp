#include<iostream>
using namespace std;
class grandParent{
	public:
		void display(){
			cout<<"i am grand parent"<<endl;
			
		}
};
class Parent1: public grandParent{
	public:
		void  show(){
			cout<<" i am here"<<endl;
		}
	
};
class Parent2: public grandParent{
	public:
		void  show(){
		cout<<" i am there"<<endl;
		}
	
	
};
class child: public Parent1 , public Parent2{
	public:
		void shown(){
			cout<<"daddy mommy i am here"<<endl;
		}
};
int main(){
	child c1;
c1.Parent1::display();

	
	
}
