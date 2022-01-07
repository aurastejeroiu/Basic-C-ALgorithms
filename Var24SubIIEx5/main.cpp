#include <string.h>
#include <iostream>

using namespace std;

int main()
{   char sir1[]="marina";
    char sir2[]="motorina";
    int p1=strlen(sir1)-1;
    int p2=strlen(sir2)-1;
    while(p1>=0 && p2>=0 && sir1[p1]==sir2[p2]){
        p1--;
        p2--;
    }
    cout<<"cel mai lung sufix: ";
    if(p1==strlen(sir1)-1)
      cout<<" nu exista";
    else  cout<<sir1+p1+1<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
