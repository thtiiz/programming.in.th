#include <stdio.h>
int Powof3[25], mod[25];
int main() {
    int n,i,temp,sum,len,num,weight;
    scanf("%d", &n);
    temp = n; i=0; // Initial
    while(temp>0){ //find base3
        mod[i]=temp%3;
        temp/=3;
        i++;
    }

    Powof3[0]=1;//Memory base3
    for(i=1; i<20; i++){
        Powof3[i] = Powof3[i-1]*3;
        if(Powof3[i] > n){
            len = i;
            break;
        }
    }

    for(i=0; i<20; i++){ //average mod[i] that >1 to mod[i+1]
        if(mod[i]==2) {
            mod[i]--;
            mod[i+1]++;
        }
        else if(mod[i]==3) {
            mod[i]=0;
            mod[i+1]++;
        }
    }
    sum=0, num=0, weight=0;
    for(i=len; i>=0; i--){
        if(mod[i]!=0) { 
            if(sum<n){ //select
                weight+=Powof3[i];
                sum+=Powof3[i];
            }
            else sum-=Powof3[i]; //not select
            num++;//count used weight
        }
    }
    printf("%d %d", num, weight);
}