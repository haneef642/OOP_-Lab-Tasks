#include <iostream>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int credits) = 0;
};

class GraduateStudent : public Student {
private:
    string topic;
public:
    void setTopic(string t) {
        topic = t;
    }

    string getTopic() {
        return topic;
    }

    double getTuition(string status, int credits) {
        if (status == "undergraduate") return 200 * credits;
        if (status == "graduate") return 300 * credits;
        if (status == "doctoral") return 400 * credits;
        return 0;
    }
};

int main() {
    GraduateStudent g;
    g.setTopic("Machine Learning");
    cout << g.getTuition("graduate", 10) << "\n";
    cout << g.getTopic() << "\n";
}
