#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

struct tree {
    int a, b, c;
} trees[10000];

int distance(tree &a, tree &b) {
    int x = a.a - b.a, y = a.b - b.b, z = a.c - b.c;
    return sqrt(x * x + y * y + z * z);
}

int main() {
    int count[10];
    memset(count, 0, sizeof(count));
    int number = 0;
    int a, b, c;
    while(cin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) break;
        trees[number].a = a;
        trees[number].b = b;
        trees[number].c = c;
        number++;
    }  
    for(int i = 0; i < number; ++i) {
        int minDist = 0x3f3f3f3f;
        for(int j = 0; j < number; ++j) {
            if(i == j) continue;
            int dis = distance(trees[i], trees[j]);
            if(dis < minDist) minDist = dis;
        }
        if(minDist < 10) count[minDist]++;
    }
    for(int i = 0; i < 10; ++i) {
        printf("%4d", count[i]);
    }
    cout << endl;
    return 0;
}