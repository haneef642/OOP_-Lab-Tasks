#include<iostream>
using namespace std;

class Circles{
	
	double radius;
	
	public:
		
		Circles(int radius){
			this->radius=radius;
	
	}
		double getArea(){
		return 3.142*radius*radius;
		}
		
		double getPerimeter(){
			
			return(2*3.142*radius);
			
		}
};
int main(){
	
	int r;
	cout<<"Enter the radius of Circle "<<endl;
	cin>>r;
	Circles a(r);
	
	cout<<"Area of circle is "<<a.getArea()<<endl;
	cout<<"Perimeter of circle is "<<a.getPerimeter()<<endl;
	
	return 0;
}