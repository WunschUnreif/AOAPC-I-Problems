#include <iostream>
using namespace std;

int main() {
    long long a, b;
    while(cin >> a >> b) {
        cout << ((b - a) > 0 ? b - a : a - b) << endl;
    }
    return 0;
}