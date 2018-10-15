#include <stdio.h>
int table[110][110], num[110], run, goal, check=1;
int runsamegoal(){
    if(run == goal) return 1;
    check = 0;
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n && check == 1; i++) {
        run = 0;
        for(int j=1; j<=n; j++){
            scanf("%d", &table[i][j]);
            if(table[i][j]<=0 || table[i][j] > n*n || num[table[i][j]] == 1) {
                check = 0;
                break;
            }
            num[table[i][j]] = 1;
            if(i==1) goal += table[i][j];
            run += table[i][j];
        }
        if(!runsamegoal()) break;
    }

    for(int j=1; j<=n && check == 1; j++) {
        run = 0;
        for(int i=1; i<=n; i++){
            run += table[i][j];    
        }
        if(!runsamegoal()) break;
    }

    int i=1, j=1;
    run=0;
    while(i<=n && j<=n){
        run += table[i][j];
        i++;
        j++;
    }
    if(runsamegoal()) {
        run=0,i=1,j=n;
        while(i<=n && j>=1){
            run += table[i][j];
            i++;
            j--;
        }
    }
    if(runsamegoal()) printf("Yes");
    else printf("No");
}