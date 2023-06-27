#include<iostream>
using namespace std;
class functionoverloading{
	private:
		int id;
		string name, fatherNAme;
		
	public:
//		functionoverloading(int _id , string _name , string _fathername):id(_id) , name(_name) , fatherName(_fatherName)  {
//			cout<<"i am parametrized constructor"<<Endl;
//		}
		void display(){
			cout<<"i am first display"<<endl;
		}
			void display(int _id ,string _name){
			cout<<"i am second display"<<_name<<" : "<<_id<<endl;
		}
			void display(string _name , int _id ){
			cout<<"i am third display"<<_name<<" : "<<_id<<endl;
		}
			void display(string _name , int _id , string _fatherName){
			cout<<"i am fourth display"<<_name<<" : "<<_id<<" : "<<_fatherName<<endl;
		}
			void display(int _id ,string _name , string _fatherName){
			cout<<"i am last display"<<_name<<" : "<<_id<<" : "<<" : "<<_fatherName<<endl;
		}
};
int main(){
	functionoverloading func;
}

