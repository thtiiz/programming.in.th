#include <stdio.h>
int sum=0;
int merge(int a[], int l, int m, int r){
    int i, j, k, n1, n2;
    n1 = m-l+1;
    n2 = r-m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++){
        L[i] = a[l+i];
    }
    for(i=0; i<n2; i++)
        R[i] = a[m+i+1];
    i=0; j=0; k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
            sum+=L[i]+R[j];
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

}

int mergesort(int a[],int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int a[]={2,3,9,18,5,7};
    mergesort(a,0,6-1);
    // for(int i=0; i<6; i++) printf("%d", a[i]);
    printf(" %d", sum);
}