#include <stdio.h>
#include <vector>
using namespace std;
vector<int> ans;
int a[105][45],m,n,t,stop;

int main() {
    scanf("%d %d %d", &m, &n, &t);
    int i,j,temp;
    for(i=1; i<=t; i++) {
        for(j=1; j<=m; j++){
            scanf("%d", &temp);
            temp++;
            a[i][j]=temp;
        }
    }
    for(j=1;j<=m;j++){
        if(a[t][j]==1){
            stop=j;
            break;
        }
    }
    a[0][n]=3;
    for(i=1;i<=t;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==1)
                if(a[i-1][j-1]==3 || a[i-1][j]==3 || a[i-1][j+1]==3) a[i][j]=3;
        }
    }
    i=t; j=stop;
    while(i){
        if(a[i-1][j-1]==3){
            ans.push_back(2);
            j--;
        }
        else if(a[i-1][j]==3){
            ans.push_back(3);
            // printf("3\n");
        }
        else if(a[i-1][j+1]==3){
            ans.push_back(1);
            j++;
        }
        i--;
    }
    for(i=t-1;i>=0;i--) printf("%d\n", ans[i]);
}