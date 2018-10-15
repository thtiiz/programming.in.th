#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[40][40], tofind[40];
int n, m, x=9999, y=9999, Rx=999, Ry=999;

char find(int i, int j, int pi, int pj,int countLR,int countRL, int len) {
    if(i<0 || i>=m || j<0 || j>=n) return 0;
    if(tolower(str[i][j]) == tolower(tofind[countLR])) countLR++;
    if(tolower(str[i][j]) == tolower(tofind[len-countRL-1])) {
        // printf("%d %d", i, len-j-1);
        countRL++;
    }
    if(countLR == len) {
        int tempx, tempy;
        tempx = i-pi*(countLR-1);
        tempy = j-pj*(countLR-1);
        if((tempx < x || (tempx == x && tempy < y)) ){
            x = tempx;
            y = tempy;
        }
        return 1;
    }
    return find(i+pi, j+pj, pi, pj, countLR, countRL, len);
}

void pre(int len) {
    x = y = Rx = Ry = 999;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){//only first
            find(i, j, -1, -1, 0, 0, len);
            find(i, j, 0, -1, 0, 0, len);
            find(i, j, 1, -1, 0, 0, len);
            find(i, j, -1, 0, 0, 0, len);
            find(i, j, 1, 0, 0, 0, len);
            find(i, j, -1, 1, 0, 0, len);
            find(i, j, 0, 1, 0, 0, len);
            find(i, j, 1, 1, 0, 0, len);
            // if(find(i, j, -1, -1, 0, 0, len)) return; //up left
            // if(find(i, j, 0, -1, 0, 0, len)) return; //up
            // if(find(i, j, 1, -1, 0, 0, len)) return; //up right
            // if(find(i, j, -1, 0, 0, 0, len)) return; //left
            // if(find(i, j, 1, 0, 0, 0, len)) return; //right
            // if(find(i, j, -1, 1, 0, 0, len)) return; //down left
            // if(find(i, j, 0, 1, 0, 0, len)) return; //down
            // if(find(i, j, 1, 1, 0, 0, len)) return; //down right
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++){
        scanf("%s", str[i]);
    }
    int numfind;
    scanf("%d", &numfind);
    for(int i=0; i<numfind; i++){
        scanf(" %s", tofind); 
        pre(strlen(tofind));
        // if(x<Rx || (x==Rx && y<Ry))
            printf("%d %d\n", x, y);
        // else
        //     printf("%d %d\n", Rx, Ry);
    }
}