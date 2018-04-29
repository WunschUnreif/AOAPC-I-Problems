#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int kase = 0;
    char input[100];
    bool notend = true;
    while(notend) {
        kase++;
        string input[1000], in;
        int use = 0;
        while(true) {
            if(!(cin >> in)) {notend = false; break;}
            if(in[0] == '9') break;
            input[use++] = in;
        }
        if(!notend) break;
        sort(input, input + use);
        bool imme = true;
        for(int i = 0; i < use - 1; ++i) {
            string str2 = input[i + 1].substr(0, input[i].length());
            if(str2 == input[i]) {
                imme = false;
                break;
            }
        }
        if(imme) cout << "Set " << kase << " is immediately decodable" << endl;
        else cout << "Set " << kase << " is not immediately decodable" << endl;
    }
    return 0;
}
