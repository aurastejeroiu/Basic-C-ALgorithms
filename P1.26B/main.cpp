#include <iostream>

using namespace std;

int main()              //Produs de numere consecutive sa dea n
{  long n;
   cout<<"da n:";
   cin >>n;
   for(long i=1;i<=n/2;i++)
   { long j=i;
     long P=i;
     while(P<n)
      { j++;
        P*=j;
      }
     if(P==n)
       {   cout<<P<<"=";
           for (long k=i;k<j;k++)
              cout<<k<<"*";
           cout<<j<<endl;
       }
   }
   return 0;
}
