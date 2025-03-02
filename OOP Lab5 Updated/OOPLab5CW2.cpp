#include <iostream>

using namespace std;

class Engine {
private:
    bool isRunning;
public:
    Engine() : isRunning(false) {}
    void start() {
        isRunning = true;
        cout << "Engine started" << endl;
    }
    void stop() {
        isRunning = false;
        cout << "Engine stopped" << endl;
    }
};

class Car {
private:
    Engine engine;
    string name;
    int id;
public:
    Car(string n, int i) : name(n), id(i) {}
    void startCar() {
        engine.start();
    }
    void stopCar() {
        engine.stop();
    }
    string getName() const {
        return name;
    }
    int getId() const {
        return id;
    }
};

class Garage {
private:
    Car* cars[10];
    int carCount;
public:
    Garage() : carCount(0) {}
    void parkCar(Car* car) {
        if (carCount < 10) {
            cars[carCount++] = car;
        }
    }
    void listCars() {
        for (int i = 0; i < carCount; i++) {
            cout << "Car ID: " << cars[i]->getId() << ", Name: " << cars[i]->getName() << endl;
        }
    }
};

int main() {
    Car car1("Toyota", 1);
    Car car2("Honda", 2);
    Car car3("Ford", 3);

    Garage garage;
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    cout << "Cars in the garage:" << endl;
    garage.listCars();
    
    return 0;
}

