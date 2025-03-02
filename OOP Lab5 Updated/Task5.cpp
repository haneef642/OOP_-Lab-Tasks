#include <iostream>

using namespace std;

class Car {
public:
    int engineHorsepower;
    int seatingCapacity;
    int noOfSpeakers;

    void setAttributes(int hp, int seats, int speakers) const {
        Car* nonConstThis = const_cast<Car*>(this);
        nonConstThis->engineHorsepower = hp;
        nonConstThis->seatingCapacity = seats;
        nonConstThis->noOfSpeakers = speakers;
    }

    void displayAttributes() const {
        cout << "Engine Horsepower: " << engineHorsepower << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Speakers: " << noOfSpeakers << endl;
    }
};

int main() {
    Car myCar;
    myCar.setAttributes(200, 5, 6);
    myCar.displayAttributes();
    return 0;
}

