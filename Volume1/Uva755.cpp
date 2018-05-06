#include <iostream>
#include <map>
#include <set>
using namespace std;

char getAlpha(char alp) {
    if(alp < 'Q') return (alp - 'A') / 3 + '2';
    else return (alp - 'Q') / 3 + '7';
}

string getPhone() {
    string line;
    getline(cin, line);
    char phoneNum[10];
    int use = 0;
    for(auto c : line) {
        if(c >= 'A' && c <= 'Z') {
            phoneNum[use++] = getAlpha(c);
        } else if(isdigit(c)) phoneNum[use++] = c;
    }
    phoneNum[use] = 0;
    return string(phoneNum);
}

void solve() {
    int n;
    cin >> n;
    set<string> phoneNumbers;
    map<string, int> phoneCnt;
    string _; getline(cin, _);
    while(n--) {
        string num = getPhone();
        phoneNumbers.insert(num);
        phoneCnt[num]++;
    }
    bool output = false;
    for(auto i : phoneNumbers) {
        if(phoneCnt[i] > 1) {
            output = true;
            for(int j = 0; j < 7; ++j) {
                cout << i[j];
                if(j == 2) cout << '-';
            }
            cout << ' ' << phoneCnt[i]<< endl;
        }
    }
    if(!output) {
        cout << "No duplicates." << endl;;
    }
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        solve();
        if(kase) cout << endl;
    }
}