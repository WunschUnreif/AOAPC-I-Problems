#include <iostream>
#include <cstring>
using namespace std;

const int DISH = 40;
char popu[] = " .xW";
int today[DISH];
int tomorrow[DISH];

void show() {
    for(int i = 0; i < DISH; ++i) {
        cout << popu[today[i]];
    }
    cout << endl;
}

void solve(int kase) {
    int dna[10];
    for(int i = 0; i < 10; ++i) {
        cin >> dna[i];
    }
    for(int day = 0; day < 49; ++day) {
        show();
        for(int i = 0; i < DISH; ++i) {
            int sum = today[i];
            if(i == 0) sum += today[i+1];
            else if(i == DISH - 1) sum += today[i-1];
            else sum += today[i-1] + today[i+1];
            tomorrow[i] = dna[sum];
        }
        for(int i = 0; i < DISH; ++i) {
            today[i] = tomorrow[i];
        }
    }
    show();
    if(kase)
        cout << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        memset(today, 0, sizeof(today));
        memset(tomorrow, 0, sizeof(tomorrow));
        today[19] = 1;
        solve(kase);
    }
    return 0;
}
