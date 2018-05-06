#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    while(~scanf("%lf%lf", &a, &b)) {
        printf("%.0lf\n", pow(b, 1 / a));
    }
    return 0;
}