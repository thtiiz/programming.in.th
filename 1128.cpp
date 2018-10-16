#include <stdio.h>
unsigned long long a[1000005];
int main() {
    int n, i;
    unsigned long long val = 0; 
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%llu", &a[i]);
    for(i=0; i<n; i++) {
        val += (a[i]*(n-i)*(n-i+1)/2)%2553;
    }
    printf("%llu", val%2553);
}
/*val = 0
for i = 0 to N-1
     for j = 0 to i
          for k = 0 to j
              val += a[k]
val %= 2553
return val

n=1
0 0 0

n=2
0 0 0

1 0 0
1 1 0
1 1 1

n=3
0 0 0

1 0 0
1 1 0
1 1 1

2 0 0
2 1 0
2 1 1
2 2 0
2 2 1
2 2 2

n=4
0 0 0

1 0 0
1 1 0
1 1 1

2 0 0
2 1 0
2 1 1
2 2 0
2 2 1
2 2 2

3 0 0
3 1 0
3 1 1
3 2 0
3 2 1
3 2 2
3 3 0
3 3 1
3 3 2
3 3 3
*/