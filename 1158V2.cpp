#include <stdio.h>
int DP[1005][1005]; //sum of row i in range (0, j)
int DPkk[1005][1005]; //memorize of area k k
int main() {
    int i,j,k,l,m,n,ans=-9999999,kksum=0,row,col;
    scanf("%d %d", &m, &n);
    scanf("%d", &k);
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d", &DP[i][j]);
            DP[i][j] += DP[i][j-1]; //sum in range (0, j)
        }
    }
    m++; m-=k; //Optimize
    n++; n-=k;//Optimize
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            l=0; kksum=0;
            if(i!=1) { // use old memorize from DPkk 
                row=i-1;
                col=j-1;
                kksum = DPkk[i-1][j]-(DP[row][col+k]-DP[row][col])+DP[row+k][col+k]-DP[row+k][col];
                
            }
            else { //initial for DPkk
                while(l<k) {
                row=i+l;
                col=j-1;
                kksum += DP[row][col+k]-DP[row][col];
                l++;
                }
            }
            DPkk[i][j] = kksum; //memorize calculated area 
            if(kksum>ans) ans = kksum; //max area????
        }
    }
    printf("%d", ans);
}