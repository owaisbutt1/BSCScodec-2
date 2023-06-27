#include<iostream>
using namespace std;

int main(){
  double numerator, denominator;
  bool check = false;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

	try{
		
		if(denominator == 0)
			throw 0;
	}
	catch(int a){
		check = true;
		cout<<"you have a division errorl"<<endl;
	}
	
	if(check)
		cout<<"there is error";
}
