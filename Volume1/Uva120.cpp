#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

bool inOrder(vector<int>& v) {
    for(int i = 0; i < v.size() - 1; ++i) {
        if(v[i] > v[i + 1]) return false;
    }
    return true;
}

void solve(string line) {
    vector<int> pancakes;
    stringstream ss(line);
    copy(istream_iterator<int>(ss), istream_iterator<int>(), back_inserter(pancakes));
    vector<int> order(pancakes);
    sort(order.rbegin(), order.rend());
    for(int i = 0; i < order.size() - 1; ++i) {
        if(inOrder(pancakes)) break;
        int orderPos = i + 1;
        int realPos = 0;
        for(int j = 0; j < pancakes.size(); ++j) {
            if(pancakes[j] == order[i]) {
                realPos = pancakes.size() - j;
                break;
            }
        }
        reverse(pancakes.begin(), pancakes.end() - realPos + 1);
        reverse(pancakes.begin(), pancakes.end() - orderPos + 1);
        cout << realPos << " " << orderPos << " ";
    }
    cout << 0 << endl;
}

int main() {
    string currLine;
    while(getline(cin, currLine)) {
        cout << currLine << endl;
        solve(currLine);
    }
}