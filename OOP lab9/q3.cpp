#include <iostream>
using namespace std;

class PatientRecord {
private:
    string name;
    int id;
    string dob;
    string medicalHistory;
    string billingInfo;

    friend class Doctor;
    friend class Billing;

public:
    PatientRecord(string n, int i, string d) : name(n), id(i), dob(d) {}

    string getPublicData() {
        return name + " " + dob;
    }

    string getMedicalData(string role) {
        if (role == "doctor") return medicalHistory;
        return "Access Denied";
    }

    void addBilling(string info) {
        billingInfo = info;
    }
};

class Doctor {
public:
    void updateMedicalHistory(PatientRecord& p, string history) {
        p.medicalHistory = history;
    }
};

class Billing {
public:
    void addBillingDetails(PatientRecord& p, string info) {
        p.billingInfo = info;
    }
};

int main() {
    PatientRecord p("Ahmed", 1, "01-01-2000");
    Doctor d;
    Billing b;

    d.updateMedicalHistory(p, "Diabetes");
    b.addBillingDetails(p, "5000");

    cout << p.getPublicData() << endl;
    cout << p.getMedicalData("receptionist") << endl;

    return 0;
}
