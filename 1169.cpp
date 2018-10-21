#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int main() {
    char inp[500];
    int len, i;
    vector<int> mystack;
    scanf("%s", inp);
    len = strlen(inp);
    mystack.push_back(0); //initial
    for(i=0; i<len; i++) {
        if(inp[i]-mystack.back() == 1 && inp[i]-mystack.back() != 0) mystack.pop_back();
        else mystack.push_back(inp[i]);
    }
    printf("%d",mystack.size()-1);
}