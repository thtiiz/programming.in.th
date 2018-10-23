#include <stdio.h>
// Dynamic programming
int dp[10005], sum[10005];
int main() {
    int n, k, i, j, l;
    scanf("%d %d", &n, &k);
    for(i=0;i<=k;i++) sum[i]=1;
    dp[0]=1; //initial
    for(i=2; i<=n; i++) {
        /* for debug
         printf("DP: "); for(l=0;l<=k;l++) printf("%d ", dp[l]); printf("\n");
         printf("Sum: "); for(l=0;l<=k;l++) printf("%d ", sum[l]); printf("\n");
         */
        for(j=1; j<=k; j++) {
            sum[j] = (sum[j-1]+dp[j]);
            if(i>j) dp[j] = sum[j]%2012;
            else dp[j] = (sum[j]-sum[j-i])%2012;
            
        }
        // printf("\n");
    }
    /* for debug
    printf("DP: "); for(l=0;l<=k;l++) printf("%d ", dp[l]); printf("\n");
    printf("Sum: "); for(l=0;l<=k;l++) printf("%d ", sum[l]); printf("\n");
    */
    printf("%d",dp[k]);
}