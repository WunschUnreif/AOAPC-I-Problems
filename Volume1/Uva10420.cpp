#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> number;
    set<string> names;
    string _;
    int n;
    cin >> n;
    getline(cin, _);
    while(n--) {
        string ctry, name;
        cin >> ctry;
        getline(cin, name);
        number[ctry]++;
        names.insert(ctry);
    }
    for(auto &i : names) {
        cout << i << ' ' << number[i] << endl;
    }
    return 0;
}
