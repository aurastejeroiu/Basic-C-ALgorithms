#include <iostream>

using namespace std;

int Prim(long long n){
    if(n<2) return 0;
    long long d=2;
    while (d*d<=n && n%d!=0)
        if(d==2)    d=3;
        else        d+=2;
    if(d*d>n)   return 1;
                return 0;
}

int main()
{   long long i,j,n;
    cout <<"da n:"; cin>>n;
    long long Pinf, Psup, Dif,Max;
    Pinf=2;
    Psup=3;
    Max =1;
    for (i=3; i<=n;i++)
        if(Prim(i)){
          j=i+2;
          while(!Prim(j)) j+=2;
          Dif=j-i;
          if(Dif>Max){
                Pinf=i;
                Psup=j;
                Max =Dif;
          }
        }
    cout<<endl<<Psup<<"-"<<Pinf<<"="<<Max<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
