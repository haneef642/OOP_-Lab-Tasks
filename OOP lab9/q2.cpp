#include <iostream>
using namespace std;

class Logger {
private:
    string logs[1000];
    int count;

    void addLog(string msg) {
        if (count >= 1000) return;
        logs[count++] = msg;
    }

public:
    Logger() : count(0) {}

    void log(string type, string msg) {
        addLog("[" + type + "] " + msg);
    }

    string* getLogs(string auth) {
        if (auth == "admin") return logs;
        return NULL;
    }

    int getLogCount() {
        return count;
    }
};

int main() {
    Logger logger;
    logger.log("INFO", "Network started");
    logger.log("ERROR", "Database failure");

    string* logs = logger.getLogs("admin");
    for (int i = 0; i < logger.getLogCount(); i++) {
        cout << logs[i] << endl;
    }

    return 0;
}
