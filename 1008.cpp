#include <stdio.h>
int skyline[4000];
int main() {
    int n, li, hi, ri, j, start=99999, end=-99999;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &li, &hi, &ri);
        if(li < start) start = li;
        if(ri > end) end = ri;
        j = li;
        while(j != ri){
            if(skyline[j] < hi)
                skyline[j] = hi;
            j++;
        }
    }
    int lasthi = 0;
    for(int i=start; i<=end; i++) {
        if(skyline[i] != lasthi) {
            printf("%d ", i);
            printf("%d ",skyline[i]);
            lasthi = skyline[i];
        }
    }
}