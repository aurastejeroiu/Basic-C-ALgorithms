#include <iostream>

using namespace std;

long SumaDiv(long n, long d)
{ if(d*d>n) return 1+n;
  if(n%d==0)
          if(d==n/d) return d+SumaDiv(n,d+1);
          else       return d+n/d+SumaDiv(n,d+1);
  else               return SumaDiv(n,d+1);
}

int main()
{   long n, d=2;
    cout<<"da un natural:";
    cin >>n;
    cout<<"Suma div="<<SumaDiv(n,2);
    cout<<endl<<"Program terminat" << endl;
    return 0;
}
