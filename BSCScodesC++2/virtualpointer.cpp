#include <iostream>
using namespace std;
class Base //base class
{
public:
virtual void show()
{ cout << "Base\n"; }
};
class Derv1 : public Base //derived class 1
{
public:
void show()
{ cout << "Derv1\n"; }
};
class Derv2 : public Base //derived class 2
{
public:
void show()
{ cout << "Derv2\n"; }
};
class Derv3 //derived class 2
{
public:
void show()
{ cout << "Derv2\n"; }
};

int main()
{
Derv1 dv1; //object of derived class 1
dv1.show();
Derv2 dv2; //object of derived class 2
dv2.show();
Derv3 d3;
Base b1;
b1.show();
Base* ptr; //pointer to base class
ptr = &dv1; //put address of dv1 in pointer
ptr->show(); //execute show()
Base *ptr1 = new Derv1;
*ptr1 = new Derv2;
ptr = &dv2; //put address of dv2 in pointer
ptr->show(); //execute show()
return 0;
}
