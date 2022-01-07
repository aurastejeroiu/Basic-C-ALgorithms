#include <iostream>
#include <iomanip>
using namespace std;

void CreTrip(int n, int V[]){
  long i=0,p,q,r,S=12;    ///i indice pentru V
  while(i<=n)
    {  p=3;
       while(i<=n && p<=S/3)
         {q=p+1;
          while(i<=n && q<=(S-p)/2)
          { r=S-p-q;
            if(r*r==p*p+q*q)
            {  V[++i]=p;  ///cout<<V[i]<<endl;
               V[++i]=q;  ///cout<<V[i]<<endl;
               V[++i]=r;  ///cout<<V[i]<<endl;
            }
           q++;
          }
          p++; ///cout<<"p="<<p<<endl;
         }
       S++;
    }

}
void Afisare(int n, int V[]){
  for(int i=1;i<=n;i++)
    { cout<<setw(5)<<V[i];
      if(i%3==0) cout<<" .S="<<setw(7)<<V[i-2]+V[i-1]+V[i]<<endl;
    }
}
int main()
{   int n,V[1000];    ///i indice pentru V
    cout<<"da n(multiplu de 3):";
    cin >>n;
    CreTrip(n,V);
    Afisare(n,V);
    return 0;
}
