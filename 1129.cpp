#include <stdio.h>
int f[10000];
int main() {
    int n, k, i, j, cur, realk;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) f[i]=i+1;
    f[n]=1; // present for cycle
    int x=1;
    k--; // นับเพิ่มอีก k-1 ครั้ง
    cur=0; //init !!! case realk=0
    for(i=0; i<n; i++) {
        realk=k%(n-i);          // i: 0 1 2 ...n-1
        for(j=0; j<realk; j++){ //x->|1|2|3|...|n|
            cur=x;
            x = f[x]; //ex. x==1 -> x=f[1]=2;
        }
        printf("%d\n", x);
        f[cur]=f[x];
        x=f[x];
    }
}