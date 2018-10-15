#include <stdio.h>

int main() {
    int year=0;
    while(1) {
        scanf("%d", &year);
        if(year == -1) break;
        int w=1, s=0, prew=0, pres=0;
        while(year>0) {
            pres = w;
            prew = w+s+1;
            w = prew;
            s = pres;
            year --;
        }
        printf("%d %d\n",w , w+s+1);
    }
}