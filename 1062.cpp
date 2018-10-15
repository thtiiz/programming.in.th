#include <stdio.h>
#include <string.h>
char a[128], x[128], b[128];
char middle(char a, char x, char b) {
    if(a>=x && x>=b || b>=x && x>=a) return x;
    else if(x>=a && a>=b || b>=a && a>=x) return a;
    else return b;
}
int min(int x, int y) {
    if(x<y) return x;
    return y;
}
int main() {
    int L,K,head=0,tail;
    // printf("%c", middle('b','d','c'));
    scanf("%d %d", &L, &K);
    scanf("%s %s %s", a, b, x);
    tail = -K+1;
    int count;
    while(tail < L) {
        if(head<L && tail<0) {
            count = head;
            for(int i = K-1;count>=0; i--, count--) {
                x[i] = middle(a[count], x[i], b[count]);
                // printf("%c (%d %d): %d/",x[i], head, tail, count);
            }
            
        }
        else if(head<L && tail>=0) {
            
            count = head;
            
            for(int i = K-1;count-tail>=0; i--, count--) {
                x[i] = middle(a[count], x[i], b[count]);
                // printf("%c (%d %d): %d/",x[i], head, tail, count);
            }
        }

        else {
            count = L-1;
            // printf("*%d*", count);
            int realcount = min(L,K);
            for(int i = (K-(head-L+1)-1); realcount>0; i--, count--, realcount--){
                x[i] = middle(a[count], x[i], b[count]);
            }
        }
        head++;
        tail++;
    }
    printf("%s", x);
    // printf("%s %s %s",a ,x ,b);
}