#include <stdio.h>
#include <vector>
using namespace std;
int dp[100005];
int main() {
    int n, i, j, x, y, w;
    vector< pair<int, int> > capital[100005];
    vector< pair<int, int> > capitalrev[100005];
    scanf("%d", &n);
    for(i=0; i<n-1; i++) {
        scanf("%d %d %d", &x, &y, &w);
        capital[x].push_back(make_pair(y, w));
        capitalrev[y].push_back(make_pair(x, w));
    }
    for(i=1; i<=n; i++) {
        for(j=0; j<capital[i].size(); j++){
            printf("%d -> %d:%d\n",i, capital[i][j].first, capital[i][j].second);
            x=i; //from
            y=capital[i][j].first; //to
            w=capital[i][j].second ;
            if(x<y) {
                if(dp[y] < w) dp[i]=capital[i][j].second;
            }
        }
    }
    // printf("%d", capital[1].size());
}