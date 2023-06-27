#include <iostream>
using namespace std;
class MyClass {
private:
    int* data;
    int** size;

public:
    // Default constructor
    MyClass(int* s) : size(&s) {
        data = new int[*(*size)];
    }

    // Copy constructor
    MyClass(const MyClass& other) : size(other.size) {
        data = new int[*(*size)];
        cout << *(*size);
//        for (int i = 0; i < *(*size); i++) {
//           data[i] = other.data[i];
//           cout<<"i am working"<<endl;
//           cout<<data[i]<<endl;
//        }
    }
    void assign(){
		for(int i =0; i < *(*size); i++){
			cin >> data[i];
		}
	}
	void display(){
		for(int i =0; i < *(*size); i++){
			cout << data[i] << endl;
		}
	}
	void deletE(){
		delete[] data;
	}
	
    // Destructor
    ~MyClass() {
    }
};

int main() {
	int a=5;
    MyClass obj1(&a);  // Copy constructor invoked for deep copy
	obj1.assign();
	obj1.display();
//	MyClass obj2(obj1);
	obj1.deletE();
	obj1.display();
    return 0;
}

