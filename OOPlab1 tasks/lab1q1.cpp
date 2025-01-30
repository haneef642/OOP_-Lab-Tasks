#include<iostream>

using namespace std;

int main(){
	
	float arr[20];
	float *ptr = arr;
	
	cout<<"Enter 20 elements "<<endl;
	for(int i=0;i<20;i++){
		
		cin >> *(ptr + i);
	}
	
	float max=*ptr;
	

	
	for(int i=1 ;i<20;i++){
		
		if(*(ptr+i)>max){
			max = *(ptr+i);
		}
	}
	
	float Smax=-1e9;
	
	for(int i=1;i<20;i++){
		
		if(*(ptr+i)<max && *(ptr+i)>Smax){
			Smax=*(ptr+i);
	
			
		}
	}
	cout<<"Second maximum number is "<<Smax<<endl;
	
}
