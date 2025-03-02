#include <iostream>

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Mix juice" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Stirring" << endl;
        }
        cout << "Juice ready" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Crushing juice" << endl;
        for (int i = 0; i < 5; i++);
        cout << "Juice done" << endl;
    }
};

class JuiceMaker {
    Blend blender;
    Grind grinder;
public:
    void makeJuice() {
        blender.blendJuice();
        grinder.grindJuice();
    }
};

int main() {
    JuiceMaker jm;
    jm.makeJuice();
    return 0;
}

