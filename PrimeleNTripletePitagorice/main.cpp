#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void PitN(long long n){
   long long i,j,k,p,limJ,cont;
   cont=0;
   i=3;
   while(cont<n){
     p=i/2;
     if(i%2==0) limJ=p*p-1;
     else       limJ=2*p*(p+1);
     j=i+1;
     while(cont<n && j<=limJ){
        k=sqrt(i*i+j*j);
        if(k*k==i*i+j*j)
            cout<<setw(5)<<++cont<<". "<<setw(10)<<i<<setw(10)<<j<<setw(10)<<k<<endl;
        j++;
     }
     i++;
   }
}

int main()
{   long long n;
    cout <<"da n:";
    cin  >>n;
    PitN(n);
    cout << "Program terminat" << endl;
    return 0;
}
