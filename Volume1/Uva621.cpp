#include <iostream>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        string s;
        cin >> s;
        if(s == "1" || s == "4" || s == "78") cout << "+";
        else if(s.substr(s.length() - 2, 2) == "35") cout << "-";
        else if(s[0] == '9' && s[s.length() - 1] == '4') cout << "*";
        else cout << "?";
        cout << endl;
    }
    return 0;
}
