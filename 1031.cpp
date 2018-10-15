#include <stdio.h>
#include <vector>
using namespace std;
vector<int> visitto[10010];
int floor[10010], visited[10010];

int main() {
    int k,n,m,from,to,temp,max=1, ladder, no;
    visited[1] = 1;
    scanf("%d %d %d", &k, &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &from, &to);
        visitto[from].push_back(to);
    }
    for(int i=1; i<=n; i++) {
        ladder = visitto[i].size();
        temp = floor[i] + 1;
        for(int j=0; j<ladder && visited[i] == 1; j++) {
            to = visitto[i][j];
            if(visited[to] == 0 || temp < floor[to]) floor[to] = temp;
            // if(visited[i] == 1)
            visited[to] = 1;
        }
    }
    for(int i=n; i>1; i--) {
        if(visited[i] == 1 && i>max && floor[i] <= k) max = i;
        // printf("floor%d:%d %d ",i, floor[i], visited[i]);
    }
    printf("%d", max);
}