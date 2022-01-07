#include <iostream>
#include <iomanip>
using namespace std;

long Comb(long n, long k){
   if(k>n) return 0;
   if(k==0 || k==n) return 1;
   if(k==1) return n;
       return n*Comb(n-1,k)/(n-k);

}


void AfisPascal (long n){
   long P[n+1];
   for(int i=0; i<n; i++)
     {for(int j=0;j<=i/2;j++)
        P[j]=P[i-j]=Comb(i,j);
      for(int j=0;j<=i;j++)
        cout<<setw(6)<<P[j];
      cout<<endl;
     }


}


int main()
{   long n;
    cout<<"da n=";
    cin >>n;
    AfisPascal(n);
    cout << "Program Terminat" << endl;
    return 0;
}
