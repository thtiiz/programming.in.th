#include <stdio.h>
int fac[1010], cdf[1010], facof2, facof3, dif=99999;

int main() {
    int n;
    scanf("%d" ,&n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &fac[i]);
        cdf[i] = fac[i]+cdf[i-1];
    }
    // for(int j=1;j<=n;j++)printf("%d ",cdf[j]);;
    int son1, son2, son3, max, min;
    for(int i=1; i<=n-2; i++) {
        for(int j=i+1; j<=n-1; j++){
            max = -9999999; min = 9999999;
            son1 = cdf[i];
            if(son1 > max) max = son1;
            if(son1 < min) min = son1;

            son2 = cdf[j] - cdf[i];
            if(son2 > max) max = son2;
            if(son2 < min) min = son2;

            son3 = cdf[n] - cdf[j];
            if(son3 > max) max = son3;
            if(son3 < min) min = son3;
            
            if(max-min < dif) {
                dif = max-min;
                facof2 = i+1;
                facof3 = j+1;
            }
            // printf("son1:%d son2:%d son3:%d max:%d min:%d\n", son1, son2, son3,max,min);
        }
    }
    printf("%d %d", facof2, facof3);
    
}