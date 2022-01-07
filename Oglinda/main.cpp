#include <iostream>

using namespace std;
//Sa se dea un subprogram recursiv pentru determinarea numarului oglinda a lui X


long Oglinda(long X, long Og)
{ if(X==0) return Og;
           return Oglinda(X/10,Og*10+X%10);
}

int main()
{   long n;
    cout<<"da un natural:";     //citire n, fara validare
    cin >>n;
    cout<<Oglinda(n,0)<<endl;   //apel cu Oglinda(n,0)
    cout << "Program terminat" << endl;
    return 0;
}
