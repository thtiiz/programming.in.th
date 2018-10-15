#include<stdio.h>
char a[25][25];
int ground[21];
int main() {
    int n,m,brick[21];
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
            scanf("%s", a[i]);
    }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            if(ground[j] == 0 && a[i][j] == 'O'){
                ground[j] = i;
            }
            else if(i==n && ground[j]==0) {
                ground[j] = n+1;
            }
        }
    }
    int temp;
    for(int j=0; j<m; j++){
        scanf("%d", &brick[j]);
        temp = ground[j]-1;
        while(temp > 0 && brick[j] > 0) {
            a[temp][j] = '#' ;
            brick[j]--;
            temp--;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}
/*
5 5
OOOOO
.....
.....
.....
.....
*/