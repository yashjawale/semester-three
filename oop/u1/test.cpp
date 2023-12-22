#include <iostream>
using namespace std;

class fan {
    private:
        int c;
    public:
        int sun(int a, int b) {
            cout << a+b+c;
            return 0;
        }
};

int main() {
    int a=12;
    int b=4;
    fan go;
    go.sun(a,b);
    return 0;
}