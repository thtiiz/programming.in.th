#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int len, palin =1, dbpalin = 1, i;
    float mid;
    char str[205];
    scanf("%s", str);
    len = strlen(str);
    if(len%2 == 0) mid = len/2-0.5;
    else mid = len/2;
    for(i=0; i < mid; i++) {
        if(tolower(str[i]) != tolower(str[len-i-1])){
            dbpalin = 0;
            palin = 0;
            break;
        }
        if(len%2==0) {
            if(tolower(str[i]) != tolower(str[int(mid)-i]) || tolower(str[int(mid)+i+1]) != tolower(str[len-i-1]))
                dbpalin = 0;
        }
        else {
            if(tolower(str[i]) != tolower(str[int(mid)-i-1]) || tolower(str[int(mid)+i+1]) != tolower(str[len-i-1]))
                dbpalin = 0;
        }
    }
    if(dbpalin) printf("Double Palindrome");
    else if(palin) printf("Palindrome");
    else printf("No");
}