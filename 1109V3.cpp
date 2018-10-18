#include <stdio.h>
double sum=0;
double dp[100005];
void merge(double a[], int l, int m, int r){
    int i, j, k, n1, n2, mul=0,temp=0;
    n1 = m-l+1;
    n2 = r-m;
    double L[n1], R[n2];
    for(i=0; i<n1; i++){
        L[i] = a[l+i];
        dp[i+1] = dp[i]+L[i];
    }
    for(i=0; i<n2; i++)
        R[i] = a[m+i+1];
    i=0; j=0; k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            sum += R[j]*(n1-i);
            sum += dp[n1]-dp[i];
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
}

void mergesort(double a[], int l, int r) {
    if(l<r){
        int mid = (l+r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int n, i, j, b;
    double a;
    scanf("%d", &n);
    double pair[100005];
    for(i=0; i<n; i++) {
        scanf("%lf %d", &a, &b);
        pair[b-1] = a;
    }
    mergesort(pair, 0, n-1);
    printf("%0.lf", sum);
}