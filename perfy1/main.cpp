#include <iostream>
using namespace std;
int main()
{   long long n,i,m;
    cout << " n : ";  cin >> n;
    long long  N[n+1];
    for (i=2; i<=n; i++) N[i]=i;
    for (i=2; i<=n; i++)
         if (N[i])
             for (m=2*i; m<=n; m+=i) N[m]=0;
    cout << " P = ";
    for (i=2; i<n; i++)
         if (N[i]) cout << i <<", ";
    long long Max=1;
    long long Pinf=2;
    long long Psup=3;
    for(i=2;i<n;i++)
        if(N[i]){
            long long j=i+1;
            while(j<n && N[j]==0) j++;
            long long  Dif=N[j]-N[i];
            ///cout<<N[j]<<endl;
            if(Dif>Max){
              Max=Dif;
              Pinf=N[i];
              Psup=N[j];
           }
        }
    cout<<endl<<Max<<"="<<Psup<<"-"<<Pinf<<endl;
    return 0;
}
