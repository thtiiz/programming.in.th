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
/*
|x1 - x2| + |y1 - y2|

5
3 3
5 1
4 4
1 3
4 7

-(x1-x2) -(x1-x3) -(x1-x4) -(x1-x5) = -4x1+x2+x3+x4+x5
         -(x2-x3) -(x2-x4) -(x2-x5) = -3x2+x3+x4+x5            
                  -(x3-x4) -(x3-x5) = -2x3+x4+x5
                  	   -(x4-x5) = -x4+x5
	+Y                          = -4x1-2x2+0x3+2x4+4x5


3
1 1
2 3
4 4

-(x1-x2) -(x1-x3) = -2x1+x2+x3
	 -(x2-x3) = -1x2+x3
                  = -2x1+0x2+2x3
*/