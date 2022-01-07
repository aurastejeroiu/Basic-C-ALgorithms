#include <iostream>

using namespace std;

int main()              //sume de numere consecutive sa dea n
{  long n;
   cout<<"da n:";
   cin >>n;
   for(long i=1;i<=n/2;i++)
   { long j=i;
     long S=i;
     while(S<n)
      { j++;
        S+=j;
      }
     if(S==n)
       {   cout<<S<<"=";
           for (long k=i;k<j;k++)
              cout<<k<<"+";
           cout<<j<<endl;
       }
   }
   return 0;
}
