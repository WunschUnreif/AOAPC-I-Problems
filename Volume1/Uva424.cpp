#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char sum[110];
int jinwei = 0;

int main() {
    memset(sum, 0, sizeof(sum));
    char curr[110];
    while(cin.getline(curr, 110)) {
        if(strlen(curr) == 1 && curr[0] == '0') break;
        int len = strlen(curr);
        jinwei = 0;
        for(int i = len - 1; i >= 0; --i) {
            int j = len - i - 1;
            int currSum = sum[j] + (curr[i] - '0') + jinwei;
            sum[j] = currSum % 10;
            jinwei = currSum / 10;
        }
        if(jinwei) {
            int m = len;
            while(sum[m] == 9) {
                sum[m] = 0;
                m++;
            }
            sum[m] += 1;
        }
    }
    bool start = false;
    for(int i = 110; i >= 0; --i) {
        if(sum[i] != 0) start = true;
        if(start) cout << (int)sum[i];
    }
    cout << endl;
    return 0;
}