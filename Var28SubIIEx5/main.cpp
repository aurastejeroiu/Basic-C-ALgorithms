#include <string.h>
#include <iostream>

using namespace std;

int main()
{   char sir1[100]="informatica";
    int strL=strlen(sir1);
    char sir2[100];
    char v[]="aeiou";
    int j;
    int p=0;
    while(p<strlen(v)){
        int i=0;
        strcpy(sir2,sir1);
        while(i<strlen(sir2)){
           if(sir2[i]==v[p])
               strcpy(sir2+i,sir2+i+1);
           else i++;
        }
        ///cout<<sir2<<endl;
        if(strL>strlen(sir2)) cout<<sir2<<endl;
        p++;
    }

    return 0;
}
