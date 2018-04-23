#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char grid[100][100];
char tofind[100];
int m, n;
int dr[] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dc[] = { 0,  1, 1, 1, 0, -1, -1,  -1};

bool check(char* tofind, int r, int c, int dir) {
    if(!(*tofind)) return true;
    if(r < 0 || r >= m || c < 0 || c >= n) return false;
    if(*tofind != grid[r][c]) return false;
    return check(tofind + 1, r + dr[dir], c + dc[dir], dir);
}

void solve(int kase) {
    cin >> m >> n;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            grid[i][j] = tolower(c);
        }
    }
    int k;
    cin >> k;
    while(k--) {
        cin >> tofind;
        for(auto &i : tofind) {
            i = tolower(i);
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == *tofind) {
                    for(int dir = 0; dir < 8; ++dir) {
                        if(check(tofind, i, j, dir)) {
                            cout << i + 1 << ' ' << j + 1;
                            if(kase || k) cout << endl;
                            i = m; j = n;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        solve(kase);
    }
    return 0;
}
