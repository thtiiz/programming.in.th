#include<stdio.h>
#include<string.h>
int main() {
    char n[1500000];
    scanf("%s", n);
    int count = 0,temp=0;
    long long a=0,b=0, len=strlen(n);
    for(int i=len-1; i>=0; i--) {
        a = (n[i]-48+a)%3;
        if(count == 0) temp += (n[i]-48);
        else{
            temp += (n[i]-48)*10;
            b += temp % 11;
            temp = 0;
            count = -1;
        }
        count ++;
    }
    b = (b+temp)%11;
    printf("%ld %ld", a, b);
}