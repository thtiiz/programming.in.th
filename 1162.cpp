#include <stdio.h>
#include <vector>
using namespace std;
vector<int> ans;
int a[105][45],m,n,t,stop;

int drive(int i, int j, int turn){
    if(i==t && j==stop) return 1;
    else if(a[i][j]==1){
        if(drive(i+1,j-1,1)==1){
            // printf("%d\n", 1);
            ans.push_back(1);
            return 1;
        }
        else if(drive(i+1,j,3)==1){
            // printf("%d\n", 3);
            ans.push_back(3);
            return 1;
        }
        else if(drive(i+1,j+1,2)==1){
            // printf("%d\n", 2);
            ans.push_back(2);
            return 1;
        }
    }
    else return 0;
}

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
    a[0][n]=1;//initial
    drive(0, n, 1);
    for(i=t-1;i>=0;i--){
        printf("%d\n", ans[i]);
    }
}