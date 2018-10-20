#include <stdio.h>
#include <math.h>
long long student[100005];
int main() {
    int n, i, j, temp;
    long long pair = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &temp);
        student[temp]++;
    }
    int digit[3], compare[3]; //ex. 103 = [1,0,3]
    for(i=0 ;i<1000; i++){
        if(student[i] > 0){
            // mulI = student[i];
            digit[2] = i%10;
            digit[1] = ((i-digit[2])/10)%10;
            digit[0] = (((i-digit[2])/10-digit[1])/10)%10;
            if(student[i] > 1)
                pair += student[i]*(student[i]-1)/2; // NC2(combination) 
                // printf("choose2pair+: %lld (%d)\n",pair, i);
            for(j=i+1; j<1000; j++) { //หน่วย
                if(student[j] > 0) {
                    compare[2] = j%10;
                    compare[1] = ((j-compare[2])/10)%10;
                    compare[0] = (((j-compare[2])/10-compare[1])/10)%10;
                    if(compare[0] == digit[0] || compare[1] == digit[1] || compare[2] == digit[2]){
                        pair += student[i] * student[j];
                        // printf("pair+:%lld (%d, %d)\n",pair, i, j);
                    }
                }
            }
        }
    }
    printf("%lld", pair);
}