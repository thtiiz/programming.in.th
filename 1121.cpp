#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
char inp[100005];

int main() {
    int Q;
    scanf("%d", &Q);
    while(Q!=0) {
        vector<int> a;
        a.push_back(0);//initial
        scanf("%s", inp);
        int len = strlen(inp), i;
        for(i=0; i<len; i++) {
            if(inp[i]-a.back()<3 && inp[i]-a.back()>0) a.pop_back();
            else a.push_back(inp[i]);
        }
        if(a.back()==0)//check if only initial
            printf("yes\n");
        else printf("no\n");
        Q--;
    }
}