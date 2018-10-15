#include <stdio.h>
#include <string.h>
//change by index
int Roll[6][6] = {{3,0,2,5,4,1}, {1,5,2,0,4,3}, {4,1,0,3,5,2}, {2,1,5,3,0,4}, {0,4,1,2,3,5}, {0,2,3,4,1,5}};

int move(char m, int *inp) {
    int index;
    if(m == 'F') index = 0;
    else if(m == 'B') index = 1;
    else if(m == 'L') index = 2;
    else if(m == 'R') index = 3;
    else if(m == 'C') index = 4;
    else index = 5;
    int temp[6];
    for (int i=0; i<6; i++){
        temp[i] = inp[Roll[index][i]];
    }
    for (int i=0; i<6; i++){
        inp[i] = temp[i];
    }

}
int main() {
    int n;
    char inp[1005];
    scanf("%d", &n);
    for (int i=0; i<n ;i++) {
        scanf("%s", inp);
        int dice[6] = {1,2,3,5,4,6};
        int len = strlen(inp);
        for(int j=0; j<len; j++){
            move(inp[j], dice);
        }
        printf("%d ",dice[1]);
    }
}