#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	
	float weight;
	cout<<"Enter weight in kilograms"<<endl;
	cin>>weight;
	
	float pounds=weight*2.2;
	
	cout<< fixed <<setprecision(2)<<"In pounds "<<pounds<<endl;
	
}
