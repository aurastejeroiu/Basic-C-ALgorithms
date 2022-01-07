#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

void Heron(long long n){
   long long i,j,k,rad,cont=0;
   for(long i=3;i<n;i++)
    for(long j=i;j<n;j++)
      for(long k=j+1;k<=n;k++){
                                    ///verifcarea ca e trinughi
          if(i>k-j)
                                    ///verificare arie numar intreg;
                { double p=(i+j+k)/2.0;			///p=double((i+j+k)/2); asa nu
                  double ALaPatrat=p*(p-i)*(p-j)*(p-k);
                  ///cout<<ALaPatra<<endl;
                  rad    =sqrt(ALaPatrat);
                  ///cout<<rad<<endl;
                  if(rad*rad==ALaPatrat) cout<<setw(5)<<++cont<<". "<<setw(5)<<i<<setw(5)<<j<<setw(5)<<k<<" Aria="<<setw(5)<<rad<<endl;
                }
      }
}


int main()
{   long long n;
    cout <<"da n:";
    cin  >>n;
    Heron(n);
    cout << "Program terminat" << endl;
    return 0;
}
