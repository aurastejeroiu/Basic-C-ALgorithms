#include <iostream>

using namespace std;

void Zecimale (long m, long D, long n){
   if(n>0){
     D*=10;
     cout<<D/m;
     Zecimale(m,D%m,n-1);
   }
}


int main()
{   long k,m,n;
    cout<<"da numaratorul:";
    cin >>k;
    cout<<"da numitorul:";
    cin >>m;

    cout<<"da numarul de zecimale:";
    cin >>n;
    cout<<"0.";
    Zecimale(m,k,n);
    cout <<endl<< "Program terminat" << endl;
    return 0;
}
