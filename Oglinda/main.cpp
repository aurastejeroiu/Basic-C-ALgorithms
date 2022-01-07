#include <iostream>

using namespace std;

long Oglinda(long x, long og)
{ if(x<10) return og*10+x;
           return Oglinda((x/10),og*10+x%10);
}

int main()
{   long n;
    cout<<"da un natural:";
    cin >>n;
    cout<<Oglinda(n,0)<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
