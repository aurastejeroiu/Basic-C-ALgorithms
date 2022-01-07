#include <iostream>
#include <math.h>

using namespace std;

void TripPit(int n)
{  int NPeRad2=n/sqrt(2.);
   for(int i=3;i<NPeRad2;i++)
        for(int j=i+1;j<=n-1;j++)
          { int SumPat=i*i+j*j;
            if(SumPat<=n*n)
                { int k=sqrt(SumPat);
                  if(k*k==SumPat) cout<<i<<" "<<j<<" "<<k<<endl;
                }
          }

}


int main()
{   TripPit(100);
    cout << "Hello world!" << endl;
    return 0;
}
