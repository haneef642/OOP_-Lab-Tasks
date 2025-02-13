#include<iostream>
using namespace std;

class Date{
	
	private:
		int month;
		int day;
		int year;
		
		
	public:
		void setData(int m, int d, int y){
			
			month=m;
			day=d;
			year=y;
		}
		void displayDate(){
			cout<<" "<<month<< " / "<<day<<" / "<<year<<endl;
		}
};

int main(){
	
	Date d1;
	d1.setData(3,18,2007);
	d1.displayDate();
	
	return 0;
	
}
