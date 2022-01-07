#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//P1.2. Sa se tipareasca toate tripletele (i,j,k) de numere naturale
//      care verifica conditiile:
//       i^2+j^2=k^2
//       i<j<k< =n (n dat)

int main()
{   long n,Cont=0;
    cout<<"da limita n="; cin>>n;
    for(long i=3;i<=n/sqrt(2);i++){
        long Pi=i*i;
        for(long j=i+1;j<=n-1;j++){
            long SPij=Pi+j*j;
             {long k=j+1;
              while(k<=n && SPij>k*k) k++;
              if(k<=n && SPij==k*k)
                    { Cont++;
                      cout<<Cont<<"."<<setw(5)<<i;
                      cout<<setw(5)<<j;
                      cout<<setw(5)<<k<<endl;
                    }
              }
            }
    }
    cout << "Program terminated" << endl;
    return 0;
}
