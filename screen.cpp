#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int szelesseg = 80;
const int magassag = 24;

class DVDScreensaver {
private:
    int x, y;
    int x2, y2;


    void Mozgatas() {
        x += x2;
        y += y2;

        if (x <= 0 || x >= szelesseg - 1) {
            x2 *= -1;
        }
        if (y <= 0 || y >= magassag - 1) {
            y2 *= -1;
        }
    }

public:
    DVDScreensaver() {
        x = szelesseg / 2;
        y = magassag / 2;
        x2 = 1;
        y2 = 1;
    }

    void Futtatas(int steps) {
        for (int i = 0; i < steps; ++i) {
            Mozgatas();
            Kiir();
            Sleep(50);
        }
    }

    void Kiir() {
        system("clear");

        for (int i = 0; i < magassag; ++i) {
            for (int j = 0; j < szelesseg; ++j) {
                if (i == y && j == x) {
                    cout << "O";
                } else {
                    cout << " "; 
                }
            }
            cout << endl;
        }
    }

    void Sleep(int milliseconds) {
        ::usleep(milliseconds * 5000);
    }
};

int main() {
    DVDScreensaver screensaver;
    screensaver.Futtatas(1000);

    return 0;
}