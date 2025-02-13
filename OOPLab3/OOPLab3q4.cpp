#include <iostream>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
	
    Employee(string fName, string lName, double salary) {
    	
        firstName = fName;
        lastName = lName;
        
        if (salary > 0) {
            monthlySalary = salary;
            
        } else {
            monthlySalary = 0;
        }
    }

    double getYearlySalary() {
        return monthlySalary * 12;
    }

    void giveRaise(double percentage) {
        if (percentage > 0) {
            monthlySalary += monthlySalary * (percentage / 100);
        }
    }

    void display() {
        cout << firstName << " " << lastName << "'s Yearly Salary: $" << getYearlySalary() << endl;
    }
};

int main() {
    Employee emp1("Muhammad", "Haneef", 3000);
    Employee emp2("Danish", "Ahmed", -20);

    emp1.display();
    emp2.display();

    emp1.giveRaise(10);
    emp2.giveRaise(10);

    cout << "After extra rupees "<<endl;
    
    emp1.display();
    emp2.display();

    return 0;
}

