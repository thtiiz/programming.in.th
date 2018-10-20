#include <stdio.h>

int main() {
    int i,j,k,n;
    scanf("%d %d", &n, &k);
    int person_number[200005], person_backward[200005], x, realk, ans, cur;
    for(i=0; i<n; i++) person_number[i]=i+1;
    for(i=0; i<n; i++) person_backward[i]=n-i;
    person_number[n]=1; //1, 2, 3, ... n, 1
    person_backward[n]=n;//n, n-1, n-2, ... 1, n
    x=1; cur=0; //initial
    for(i=0; i<n; i++){
        k--;
        realk = k%(n-i);
        printf("realk:%d ",realk);
        if(realk<(n-i)/2){
            for(j=0; j<realk; j++) {
                cur=x;
                x=person_number[x];
            }
            ans=x;
            printf("%d\n",x);
            person_number[cur] = person_number[x];
            person_backward[n-cur] = person_number[x];
            x = person_number[x];
            k=ans;
            k--;
        }   
        else {
            realk = n-i-realk;
            realk--;
            for(j=0; j<realk; j++) {
                cur=x;
                x=person_backward[x];
            }
            ans=x;
            printf("%d\n",x);
            person_backward[cur] = person_backward[x];
            person_number[n-cur] = person_backward[x];
            x = person_backward[x];
            k=ans;
            k--;
        }
        // printf("%d ",x);

    }
    printf("%d", ans);
}