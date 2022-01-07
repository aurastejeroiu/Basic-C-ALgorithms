#include <string.h>
#include <iostream>

using namespace std;

int main()
{   char sir[]="copiii*sunt*la***zoo******si*la*boo";
    cout<<sir<<endl;
    int p=0;
    while(p<strlen(sir))
    {   if(sir[p]==sir[p+1] && sir[p]!='*') cout<<sir[p]<<sir[p]<<endl;
        p++;
    }

    cout << "Hello world!" << endl;
    return 0;
}
