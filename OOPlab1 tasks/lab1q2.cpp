#include<iostream>

using namespace std;

int main(){
	
	float arr[10];
	
	float *ptr=arr;
	int sum=0;
	
	cout<<"Enter 10 Elements "<<endl;
	
	for(int i=0;i<10;i++){
		
		cin>>*(ptr+i);
		
		sum =sum+ *(ptr+i);
	}
	
	cout<<"The sum is "<<sum<<endl;
	
	
	
	return 0;
}
