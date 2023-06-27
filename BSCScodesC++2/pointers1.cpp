#include<iostream>
using namespace std;



void add(int *p){
	
	
}
void print_string(char *p){
	while(*p){
		cout<<*p++;
	}
}

void centimize(double *p){
	
	*p *=2.34;
}
int main(){
//	int arr[]= {1,2,3,4};
//	int *p;
//	p = arr;
//	cout<<*p++;
//	cout<<*p;

//char comment[] = "this is best";
//	cout<<comment;
//print_string(comment);

 int arr[]={1,2,3,4};
 
// for(int i = 0; i<4;i++)
// 	cout<<*(arr + i)<<endl;

 int *p;
 p = arr;
 
 for(int i = 0; i<4; i++)
 	cout<<*(p++);

 double  var = 10.0;
 cout<<"value of var is: "<<var<<endl;
  centimize(&var);
  cout<<"value of var is: "<<var;


}
