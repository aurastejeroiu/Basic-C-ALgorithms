#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    char sir[20]="mare  frig rosu";
    cout<<sir<<endl;
    sir[0]=sir[0]-32;
    ///cout<<sir[0];
    int p=1;
    while(p<strlen(sir))
    {   if(sir[p]==' ' && sir[p+1]!=' ') sir[p+1]-=32;
        p++;
    }

    cout<<sir<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
