#include<iostream>
using namespace std;

class User{
	
	public:
		int age;
		string name;
};

 int main(){
 	
 	User u1;
 	u1.name="Toe";
 	u1.age=24;
 	
 	cout<<"My name is "<<u1.name<<" and I'm "<<u1.age<<" Years old"<<endl;
 }
