#include <stdio.h>
int prefix[15];

int update(int i, int value){
    i++;
    while(i<12){
        prefix[i] += value;
        i += (i&-i);
    }
}

int prefixsum(int i){
    i++;
    int sum = 0;
    while(i!=0){
        sum += prefix[i];
        i -= (i&-i);
    }
    return sum;
}

int main() {
    int a[] = {3,2,-1,6,5,4,-3,3,7,2,3};
    for(int i=0; i<11; i++) {
        update(i, a[i]);
    }
    for(int i=0; i<11; i++) {
        printf("%d ", prefix[i]);
    }
    printf("\nsum:%d", prefixsum(4));     
}