#include<iostream>
using namespace std;

class Invoice{
	
	string partNumber;
	string description;
	int quantity;
	double price;
	
	public:
	Invoice(string partNumber, string description, int quantity, double price){
		
		this->partNumber=partNumber;
		this->description=description;
		this->quantity=quantity;
		this->price=price;
		
		if(quantity<0){
			quantity=0;
		}
		if(price<0){
			price=0;
		}
	}
	
	
	
	
	
	double getInvoiceAmount(){
		return quantity*price;
	}
	
	
};

int main(){
	
	string partNumber, description;
    int quantity;
    double price;
    
	cout << "Enter part number: ";
    cin >> partNumber;
    cin.ignore(); 

    cout << "Enter part description: ";
    getline(cin, description);

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter price per item: ";
    cin >> price;

    
    Invoice invoice(partNumber, description, quantity, price);

    
    cout << "\nInvoice Details:" << endl;
    cout << "Part Number: " << partNumber << endl;
    cout << "Description: " << description << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price per Item: $" << price<< endl;
    cout << "Total Invoice Amount: $" << invoice.getInvoiceAmount()<< endl;
}

