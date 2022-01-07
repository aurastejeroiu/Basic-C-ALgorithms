#include <iostream>

using namespace std;

int Prim(long n, long d)
{ if(n<2)     return 0;
  if(d*d<=n){
    if(n%d==0)  return 0;
      if(d==2)  return Prim(n,d+1);
                return Prim(n,d+2);
  }
  return 1;
}

int main()
{   long n;
    cout<<"da n=";
    cin >>n;

    for(long i =2 ;i<=n;i++)
        if(Prim(i,2)) cout<<i<<" ";
    cout << "\nHello world!" << endl;

    return 0;
}
