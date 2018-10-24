#include <stdio.h>
int DP[1005][1005]; //sum of row i in range (0, j)
int main() {
    int i,j,k,l,m,n,ans=-9999999,kksum=0;
    scanf("%d %d", &m, &n);
    scanf("%d", &k);
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d", &DP[i][j]);
            DP[i][j] += DP[i][j-1];
        }
    }
    for(i=1;i+k-1<=m;i++) {
        for(j=1;j+k-1<=n;j++) {
            l=0; kksum=0;
            while(l<k) {
                kksum += DP[i+l][j+k-1]-DP[i+l][j-1];
                l++;
            }
            if(kksum>ans) ans = kksum;
        }
    }
    /*--------------------------*/
    // printf("\n");
    // for(i=1;i<=m;i++) {
    //     for(j=1;j<=n;j++) {
    //         printf("%d ", DP[i][j]);
    //         // DP[i][j] += 
    //     }
    //     printf("\n");
    // }
    printf("%d", ans);
}