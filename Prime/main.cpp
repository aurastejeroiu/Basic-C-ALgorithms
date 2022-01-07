#include <iostream>

using namespace std;

int Prim(long n, long d)
{ if(n<2)    return 0;
  if(d*d>n)  return 1;
  if(n%d==0) return 0;
  else       return Prim(n,d+1);
}

int main()
{   long n,d=2;
    cout<<"da un natural:";
    cin >> n;
    if(Prim(n,d)==1) cout<<"e prim"<<endl;
    else             cout<<"nu e prim"<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
