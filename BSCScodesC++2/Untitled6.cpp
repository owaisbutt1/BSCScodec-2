#include<iostream>
using namespace std;
class students{
	private:
		string name,father;
		int id;
		public:
			void set(){
				
				cout<<"i am ok SSSSSss"<<endl;
			}
	
};
class parents{
	private:
		string Pname,Pfather;
		int Pid;
		public:
			void Pset(){
				
				cout<<"i am ok PPPPPPPP"<<endl;
			}
	
};
class rehmat: public parents{
	private:
		string Rname,Rfather;
		int Rid;
		public:
			void Rset(){
			
				cout<<"i am ok RRRRR"<<endl;
			}
	
};

int main(){
	
rehmat rb;
rb.Rset();
}
