#include <stdio.h>

int main() {
    int i,p,temp;
    scanf("%d", &p);
    int comboOdd=0, comboEven=0, hpOdd=p, hpEven=p;
    while(hpOdd>0 && hpEven>0) {
        scanf("%d", &temp);
        if(temp%2==0){
            comboEven++;
            comboOdd=0;
            if(comboEven>=3) {
                hpOdd-=3;
            }
            else hpOdd--;
        }
        else {
            comboOdd++;
            comboEven=0;
            if(comboOdd>=3) {
                hpEven-=3;
            }
            else hpEven--;
        }
        // printf("Odd:%d Even:%d |", hpOdd, hpEven);
    }
    if(hpEven<=0) printf("1\n");
    else printf("0\n");
    printf("%d", temp);
}