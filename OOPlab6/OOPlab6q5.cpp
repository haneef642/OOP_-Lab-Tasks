#include <iostream>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}

    virtual void displayDetails() {
        cout << "Price: $" << price << endl;
    }

    virtual ~Vehicles() {}
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;
public:
    Car(double p, int seat, int doors, string fuel) : Vehicles(p), seatingCapacity(seat), numberOfDoors(doors), fuelType(fuel) {}

    void displayDetails() override {
        Vehicles::displayDetails();
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;
public:
    Motorcycle(double p, int cyl, int gears, int wheels) : Vehicles(p), numberOfCylinders(cyl), numberOfGears(gears), numberOfWheels(wheels) {}

    void displayDetails() override {
        Vehicles::displayDetails();
        cout << "Number of Cylinders: " << numberOfCylinders << endl;
        cout << "Number of Gears: " << numberOfGears << endl;
        cout << "Number of Wheels: " << numberOfWheels << endl;
    }
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int seat, int doors, string fuel, string model) : Car(p, seat, doors, fuel), modelType(model) {}

    void displayDetails() override {
        Car::displayDetails();
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int cyl, int gears, int wheels, string make) : Motorcycle(p, cyl, gears, wheels), makeType(make) {}

    void displayDetails() override {
        Motorcycle::displayDetails();
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi audiCar(50000, 5, 4, "Petrol", "Audi A6");
    Yamaha yamahaBike(15000, 2, 6, 2, "YZF-R1");

    cout << "--- Audi Car Details ---" << endl;
    audiCar.displayDetails();
    cout << "------------------------" << endl;

    cout << "--- Yamaha Motorcycle Details ---" << endl;
    yamahaBike.displayDetails();
    cout << "------------------------" << endl;

    return 0;
}
