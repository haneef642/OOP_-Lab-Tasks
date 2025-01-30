#include<iostream>

using namespace std;

int main(){
	
	int Customer_ID;
	string name;
	int Unit_Consumed;
	float charge;
	
	cout<<"Enter Customer ID "<<endl;
	cin>>Customer_ID;
	
	cout<<"Enter Customer name "<<endl;
	cin>>name;
	
	cout<<"Enter Unit Consumed by user "<<endl;
	cin>>Unit_Consumed;
	
	
	
	if(Unit_Consumed>=0 && Unit_Consumed<=199){
		
		charge=16.20;
		
		
	}else if(Unit_Consumed>=200 && Unit_Consumed<300){
		
		charge=20.10;
		
	}else if(Unit_Consumed>=300 && Unit_Consumed<500){
		
		charge=27.10;
		
	}else{
		
		charge=35.90;
	}
	
	float bill=Unit_Consumed*charge;
	float surcharge;
	
	if(bill>18000){
		
		surcharge=0.15*bill;
		bill=bill+surcharge;
	}
	
	cout<<"Customer ID is "<<Customer_ID<<endl;
	cout<<"Customer name is "<<name<<endl;
	cout<<"Unit Consumed are "<<Unit_Consumed<<endl;
	cout<<"Total bill is "<<bill<<endl;
	cout<<"surcharge is "<<surcharge<<endl;
	
	
	return 0;
}
