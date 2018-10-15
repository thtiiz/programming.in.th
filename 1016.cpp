#include <stdio.h>
#include <math.h>
#include <string.h>
double direction[8][2] = {
    {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
    /*N แทน ทิศเหนือ
NE แทน ทิศตะวันออกเฉียงเหนือ
E	แทน ทิศตะวันออก
SE	แทน ทิศตะวันออกเฉียงใต้
S แทน ทิศใต้
SW แทน ทิศตะวันตกเฉียงใต้
W	แทน ทิศตะวันตก
NW	แทน ทิศตะวันตกเฉียงเหนือ
*/
int main() {
    char inp[60];
    double v[] = {0.0, 0.0};
    while(1) {
        scanf("%s", inp);
        if(inp[0] == '*') break;
        int i=0, j=0, choose;
        double scalar=0;
        int len = strlen(inp), lendirect=0;
        char direct[5];
        while(len-1-i>=0) {
            if(inp[len-1-i] < 65) {
                scalar += (inp[len-1-i]-48)*pow(10, j);
                j++;
            }
            else{
                direct[i] = inp[len-1-i];
                lendirect++;
            }
            i++;
        }
        if(lendirect == 1){
            if(direct[0] == 'N') choose = 0;
            else if(direct[0] == 'E') choose = 2;
            else if(direct[0] == 'S') choose = 4;
            else  choose = 6;
        }
        else {
            scalar*=(sqrt(2)/2);
            if(direct[0] == 'E' && direct[1] == 'N') choose = 1;
            else if(direct[0] == 'E' && direct[1] == 'S') choose = 3;
            else if(direct[0] == 'W' && direct[1] == 'S') choose = 5;
            else choose = 7;
        }
        v[0] += scalar*direction[choose][0];
        v[1] += scalar*direction[choose][1];  
    }
    printf("%.3f %.3f\n", v[0], v[1]);
    printf("%.3f", sqrt(pow(v[0], 2) + pow(v[1], 2)));
}
/*3N 1E 1N 3E 2S 1W * 	

3.000 2.000
3.606*/