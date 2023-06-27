using namespace std;

class student{
	private:
		//string name;
		//string phone;
		//string dob;
		int sap;
		static int count;
		public:
			student() 
			{
				cout<<"DEFAULT CONSTRUCTOR"<<endl;
			}
//			student (string a , int b , string c , string d)
//			{
//			     name = a;
//			     sap = b;
//			     phone = c;
//			     dob = d;
//				cout<<"PERAMETERIZED COUNSTRUCTOR"<<endl;
//			}
			student (string i , string j , int k , string l)
			{
			     name = i;
			     phone = j;
			     sap = k;
			     dob = l;
				cout<<"PERAMETERIZED COUNSTRUCTOR"<<endl;
			}
			void get_data()
			{
				cout<<"ENTER NAME: ";
				cin>>name;
				cout<<"ENTER SAP: ";
				cin>>sap;
				cout<<"ENTER PHONE: ";
				cin>>phone;
				cout<<"ENTER DOB: ";
				cin>>dob;	
			}
			void display_data()
			{
				cout<<"DATA OF THE STUDENT";
				cout<<"NAEM: "<<name<<endl;
				cout<<"SAP ID: "<<sap<<endl;
				cout<<"PHONE #: "<<phone<<endl;
				cout<<"DATE OF BIRTH: "<<dob<<endl;
			}
		~student(){
			cout<<"DEDULT DISTROCTOR"<<count<<endl;
			count++;
		}
		};
		int student:: count=0;
		int main()
		{
			student s1,s2("atta",1234,"09876543","1-2-3"),s3("qwer","123456",1234,"1-1-1");	
		//	s1.get_data();
		//	s1.display_data();
		//	s1.~student()
			s2.display_data();
			s3.display_data();
		}
