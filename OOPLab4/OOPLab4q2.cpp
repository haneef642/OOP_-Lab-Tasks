#include<iostream>
using namespace std;

class Account{

  double balance;
  
  public:
  	
  	Account(){
  		balance=0;
  		
	  }
  
  void setBalance(double balance){
  	if(balance>0){
  		
  		this->balance=balance;
	  }else{
	  	
	  	cout<<"Error"<<endl;
	  }
  }
  
  void credit(double amount){
  	if(amount>0){
	  
  	balance+=amount;
  	cout<<"Deposited Successfully...!"<<endl;
  }else{
  	cout<<"You have to deposit positive rupees"<<endl;
  } 
}
  
  void debit(double amount){
  	if(balance<amount){
  		cout<<"Transiction Unsuccessful. Unsufficient Funds"<<endl;
	  }else{
	  	
	  	balance-=amount;
	  cout<<"Transcition Successefull . Your withdrawn "<<amount<<endl;
  	
  }
}
  
  double getBalance(){
  	return balance;
  }
  
	
};
	
	int main(){
		
		Account a;
		int n;
		double amount;
		
		
		
		while(true){
			cout<<"   WELCOME TO OUR BANK SERVICE... !"<<endl;
			cout<<" 1. Deposit "<<endl;
			cout<<" 2. Withdraw  "<<endl;
			cout<<" 3. Check Balance "<<endl;
			cout<<" 4 . Exit "<<endl;
			cout<<"Choose an option"<<endl;
			cin>>n;
			
			if(n==1){
				cout<<"Enter your deposit amount "<<endl;
				cin>>amount;
				a.credit(amount);
				
			}else if(n==2){
				cout<<"Enter your withdrawn amount "<<endl;
				cin>>amount;
				a.debit(amount);
				
			}else if(n==3){
				cout<<"Your balance is "<<a.getBalance()<<endl;
			}
			else if(n==4){
				
				cout<<"Exiting.. Thank you for using our services "<<endl;
				break;
			}else{
				
				cout<<"Invalid Input Try agian.."<<endl;
			}
		}
		
		return 0;
	}
	