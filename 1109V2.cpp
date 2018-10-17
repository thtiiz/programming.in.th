#include <stdio.h>
#include <vector>
double pair[100005];
int main() {
    int n, i, j, a;
    scanf("%d", &n);
    double b, sum=0;
    for(i=0 ;i<n; i++) {
        scanf("%d %lf", &a, &b);
        pair[a] = b;
    }
    for(i=1; i<100000; i++) {
        if(pair[i]!=0) {
            for(j=i+1; j<100000; j++) {
                if(pair[j]!=0)
                    if(pair[i]>pair[j]) sum+= i+j;
            }
        }
    }
    printf("%.0lf", sum);
}