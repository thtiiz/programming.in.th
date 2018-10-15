#include <stdio.h>
// k>half ==> small -> big
// k<=halk ==> big -> small
int car[2000005];
int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    //best Algor (Redix sort) O(n) in this O(n/2)
    int temp,count=0;
    for(i=0 ;i<n; i++) {
        scanf("%d", &temp);
        car[temp]++;
    }
    if(k<n/2) {
        for(i = 2000000; i>0 && count!=k; i--){
            if(car[i] == 1) count++;
        }
        printf("%d", ++i);
    }
    else {
        for(i=0; i<= 2000000 && count!=n-k+1; i++){
            if(car[i] == 1) count++;
        }
        printf("%d", --i);
    }
    //Algor 1 (bubble sort) O(n^2)
    // for(i=0; i<n; i++) {
    //    scanf("%d", &car[i]);
    // }
    // if(k<n/2) {//bubble sort K รอบ 
    //     int temp,max=-999999,last=n;   
    //     for(i=0;i<k;i++) {
    //         for(j=0; j<last-1; j++) {
    //             if(car[j]>car[j+1]){
    //                 temp = car[j+1];
    //                 car[j+1] = car[j];
    //                 car[j] = temp;
    //             }
    //         }
    //         last--;
    //     }
    //     printf("%d", car[n-k]);
    // }
    //     else {
    //     int temp,min=-9999999,last=0;   
    //     for(i=0;i<n-k+1;i++) {
    //         for(j=n-1; j>last; j--) {
    //             if(car[j]<car[j-1]){
    //                 temp = car[j-1];
    //                 car[j-1] = car[j];
    //                 car[j] = temp;
    //             }
    //         }
    //         last++;
    //     }
    //     printf("%d", car[n-k]);
    // }
}