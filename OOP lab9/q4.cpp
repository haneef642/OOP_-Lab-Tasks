#include <iostream>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int booked;

public:
    Flight(string fn, string dep, string arr, int cap) : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), booked(0) {}

    bool bookSeat() {
        if (booked >= capacity) return false;
        booked++;
        return true;
    }

    bool cancelSeat() {
        if (booked <= 0) return false;
        booked--;
        return true;
    }

    bool upgradeSeat() {
        return true;
    }

    int availableSeats() {
        return capacity - booked;
    }
};

class Passenger {
private:
    int id;
    string name;

public:
    Passenger(int i, string n) : id(i), name(n) {}

    bool requestBooking(Flight& f) {
        return f.bookSeat();
    }

    bool requestCancel(Flight& f) {
        return f.cancelSeat();
    }
};

int main() {
    Flight f1("PK123", "Karachi", "Lahore", 2);
    Passenger p1(1, "Ahsan");
    Passenger p2(2, "Usman");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p1.requestBooking(f1);

    cout << f1.availableSeats() << endl;

    return 0;
}
