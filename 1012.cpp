#include <stdio.h>
#include <math.h>

int cake[10];
int main() {
    int n, temp[10], count = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
        for(int j=0; j<5; j++) cake[j] += temp[j];
    }
    // for (int i=0; i<5; i++) printf("cake(%d):%d ", i,cake[i]);
    // printf("\n");
    int temp_cake4 = 0;
    count += cake[0];//count
    if(cake[4]%2 != 0){//change 1/8 into 1/4
        cake[4]-=1;
        temp_cake4 = 1;
    }
    cake[3] += cake[4]/2;

    count += cake[1];//count
    if(cake[1] > cake[3]) {//share 1/4 from 3/4 into cake[3])(1/4)
        cake[1] -= cake[3];
        cake[3] = 0;
    }
    else {
        cake[3] -= cake[1];
        cake[1] = 0;
    } 

    count += cake[2]/2;//count
    cake[2] = cake[2]%2;//2/4+2/4
    count += cake[2];//2/4

    if(cake[3]>0) {//share 2/4 to 1/4
        if(cake[2]*2 > cake[3]) {
            cake[2] -= cake[3]*2;
            cake[3] = 0;
        }
        else {
            cake[3] -= cake[2]*2;
            cake[2] = 0;
        }
    }

    if(temp_cake4 > 0){//check remain of cake[4] (1/8) and share from the other
        if(cake[1]!=0 || cake[2]!=0 || (cake[3]%4) != 0){
            temp_cake4--;
        }
    }
    count = count+temp_cake4+ceil(float(cake[3])/4); // count remain
    printf("%d", count);
    // for (int i=0; i<5; i++) printf("cake(%d):%d ", i,cake[i]);
    // printf(" temp:%d count:%d\n",temp_cake4, count);
}