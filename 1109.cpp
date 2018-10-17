#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, i, j;
    double a, b, sum=0;
    scanf("%d ", &n);
    vector<pair<double, double> > pairab;
    for(i=0; i<n; i++) {
        scanf("%lf %lf", &a, &b);
        pairab.push_back(make_pair(a, b));
    }
    sort(pairab.begin(), pairab.end());
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++) {
            if(pairab[i].first!=pairab[j].first && pairab[i].second > pairab[j].second)
                sum += pairab[i].first+pairab[j].first;
        }
    }
    printf("%.0lf", sum);
}