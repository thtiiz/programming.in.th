#include <stdio.h>
int floor[20][20];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n ;j++) {
            scanf("%d", &floor[i][j]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n ;j++) {
            int x = floor[i][j];
            if(i==1 && j==n) break;
            if(floor[i+1][j] == x && floor[i][j+1] && floor)
        }
        printf("\n");
    }
} 