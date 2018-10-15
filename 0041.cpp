#include<stdio.h>
#include<math.h>

int main() {
    int n;
    double ans;
    scanf("%d", &n);
    if(n <=2 ) ans = 2;
    else if(n == 3) ans = 2 + sqrt(3);
    else if(n%2 == 0) ans = n;
    else {
        ans += n-3+2*sqrt(3);
    }
    printf("%lf", ans);
    return 0;
}