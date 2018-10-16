#include <stdio.h>
#include<algorithm>
using namespace std;
long long x[500005], y[500005];

int main(){
    int n,i;
    long long ans=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    sort(x, x+n);
    sort(y, y+n);
    for(i=0; i<n; i++) {
        ans += (x[i]+y[i])*(-(n-1)+2*i);
    }
    printf("%lld", ans);
}