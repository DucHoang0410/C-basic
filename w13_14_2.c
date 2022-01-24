#include <stdio.h>
#include <stdlib.h>
int bruteforce(char y[], char s[])
{
    int n=strlen(y);
    int m=strlen(s);
    int x,a=-1;
    for(int i=0;i<n+1-m;i++){
        x=1;
        for(int j=0;j<m;j++){
            if(y[i+j]!=s[j]){
                x=0;
                break;
            }
        }
        if(x==1){
            a=i;
        }
    }
    return a;
}

int main()
{
    printf("%d",bruteforce("nguyenduchoang","cho"));
    return 0;
}
