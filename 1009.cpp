#include <stdio.h>
char a[5][50], b[5][50];

int main() {
    int n, m, i, j,temp;
    int numa[20], numb[20];
    scanf("%d %d", &n, &m);
    for(i=0; i<3; i++) {
        scanf("%c", &temp);
        gets(a[i]);
    }
    // for(i=0; i<3; i++) {
    //     fgets(b[i], m, stdin);
    // }
    // for(i=0, j=0; i<n; i++, j+=3){
    //     if(a[0][j+1] == ' ' && a[1][j+1] == ' ' && a[2][j+1] == ' ')
    //         numa[i] = 1;
    //     else if(a[0][j] == ' ' && a[1][j] == ' ' && a[2][j] == '|')
    //         numa[i] = 2;
    //     else if(a[1][j] == ' ' && a[2][j] == ' ' && a[2][j+1] == '_')
    //         numa[i] = 3;
    //     else if(a[1][j] == '|' && a[2][j] == ' ' && a[2][j+1] == ' ')
    //         numa[i] = 4;
    //     else if(a[1][j+2] == ' ' && a[2][j] == ' ')
    //         numa[i] = 5;
    //     else if(a[1][j+2] == ' ')
    //         numa[i] = 6;
    //     else if(a[0][j+1] == '_' && a[1][j+1] == ' ' && a[2][j+1] == ' ')
    //         numa[i] = 7;
    //     else if(a[1][j+1] == '_' && a[2][j] == '|' && a[0][j+2] == '|')
    //         numa[i] = 8;
    //     else if(a[2][j] == ' ')
    //         numa[i] = 9;
    //     else numa[i] = 0;
    // }
    for(i =0;i<3;i++){
        for(j=0; j<6; j++){
            printf(".%c", a[i][j]);
        }
        printf("\n");
    }
    
}