#include <iostream>

using namespace std;
//Sa se dea un subprogram recursiv pentru determinarea numarului cu cifre pare din  n


long Pare(long n)
{ if(n==0) return 0;
  else  if(n%2==0) return Pare(n/10)*10+n%10;
        else       return Pare(n/10);
}

int main()
{   long n;
    cout<<"da un natural:";     //citire n, fara validare
    cin >>n;
    cout<<Pare(n)<<endl;   //apel cu Oglinda(n,0)
    cout << "Program terminat" << endl;
    return 0;
}
