#include<stdio.h>
int loblike[1001];
int main(){
    int n, max=-1;
    int temp[1001], count=0;;
     
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        int num;
        scanf("%d", &num);
        loblike[num]++;
        // printf("i:%d num:%d stack:%d\n", i, num, loblike[num]);
        if(loblike[num] > max){
            count = 1;
            temp[0] = num;
            max=loblike[num];
        }
        else if(loblike[num] == max) {
            // printf("\n---%d---\n", num);
            int j;
            for(j=0; j<count; j++){
                if(temp[j] == num) break;
            }
            if(j==count){
                temp[count] = num;
                count++;
            }
        }
    }

    for(int i = 0; i<count; i++) {
        printf("%d ",temp[i]);
    }
    // printf("%d", max);

}