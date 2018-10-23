#include <stdio.h>
int k,ans=0, n;
int merge(int a[],int l, int mid, int r, int count){
    int i,j,k,n1,n2;
    n1=mid-l+1;
    n2=r-mid;
    int L[n1], R[n2];
    for(i=0; i<n1; i++) L[i]=a[l+i];
    for(i=0; i<n2; i++) R[i]=a[mid+i+1];
    i=0; j=0; k=l;
    while(i<n1 && j<n2){
        if(R[j] <= L[i]) {
            a[k] = L[i];
            i++;
        }
        else {//R[j]>L[i]
            printf("%d ", count);
            count++; //????
            if(count==k) ans+=mid-i;
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    return count;
}

int backward_mergesort(int a[],int l, int r,int countL,int countR){
    int count =0;
    if(l<r){
        int mid = (l+r)/2;
        countL=backward_mergesort(a, l, mid, countL, countR);
        countR=backward_mergesort(a, mid+1, r, countL, countR);
        count=merge(a, l, mid, r, countL+countR);
    }
    return count;
}

int main() {
    int i,data[10005];
    scanf("%d %d", &n, &k);
    i=0;
    for(i=0;i<n;i++) data[i]=i+1;
    backward_mergesort(data, 0, n-1, 0, 0);
    printf("==%d", ans);
}