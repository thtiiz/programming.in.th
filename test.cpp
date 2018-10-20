#include <stdio.h>

int main() {
    int i,j,k,n,is_forward;
    scanf("%d %d", &n, &k);
    int person_number[200005], person_backward[200005], x, realk, ans, cur;
    for(i=0; i<n; i++) person_number[i]=i+1;
    for(i=1; i<=n; i++) person_backward[i]=n-i;
    person_number[n]=1; //1, 2, 3, ... n, 1
    person_backward[0]=1;//n, n-1, n-2, ... 1, n
    x=1; cur=0;//initial
    for(i=0; i<n; i++) {
        is_forward=1;
        k--;
        realk = k%(n-i);
        if(realk<=n/2) {
            for(j=0; j<realk; j++) {
                cur=x;
                x=person_number[x];
            }
        }
        else{//realk>n/2 half
            realk = (n-i)-realk;
            is_forward = 0;
            for(j=0; j<realk; j++){
                if(x!=1){ 
                    cur=n-x-i+1;
                    x=person_backward[cur];
                }
                else {cur=x;
                x=person_backward[x];
                }
            }
        }
        // if(is_forward) printf("fw:");
        // else printf("bw:");
        // printf("%d ",x);
        ans=x;
        if(is_forward == 0) {
            person_backward[cur] = person_backward[x-1];
            cur=n-i-cur;
        }
        person_number[cur] = person_number[x];
        x = person_number[x];
        k=ans;
    }
    printf("%d", ans);
}