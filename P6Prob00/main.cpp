#include <iostream>

using namespace std;

int Prim(long n){
    if(n<2)     return 0;
    long d=2;
    while(d*d<=n && n %d !=0)
        if(d==2) d=3;
        else     d+=2;
    if(d*d>n)   return 1;  /// n e prim
                return 0;
}
void AflaGemeneMari(long n){
   long p,q;
   if(n%2==0){
        p=n+1;
        q=n+3;
   }
   else{
        p=n+2;
        q=n+4;
   }
   while((!Prim(p)) || (!Prim(q)) ){
        p=q;
        q+=2;
   }
   cout<<p<<" si "<<q<<" sunt gemene\n";
}

int main()
{   long n;
    cout <<"da n:"; cin >> n;
    AflaGemeneMari(n);
    cout << "program terminat" << endl;
    return 0;
}
