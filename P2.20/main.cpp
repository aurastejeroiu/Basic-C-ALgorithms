#include <iostream>

using namespace std;

void CitireX(int& n, int x[])
{ cout<<"da lungimea sirului:";
  cin >>n;
  for(int i=1; i<=n;i++)
  {  cout<<"x["<<i<<"]=";
     cin >>x[i];
  }
}
void MediiPoz(int n, int x[], int& k, double v[]){
  int PozNeg[100];
  k=0;
  for(int i=1;i<=n;i++)         ///determinare vector pozitii negative
    if(x[i]<0) PozNeg[++k]=i;
  
  for(int i=1;i<k;i++){         /// determinare vector v de medii
    double S=0;
    for(int j=PozNeg[i]+1;j<PozNeg[i+1];j++)
        S+=x[j];
    int cnt=PozNeg[i+1]-PozNeg[i]-1;
    
    if(cnt>0) v[i]=S/cnt;
    else      v[i]=0.0;
  }
}

void Afisare(int k, double v[]){
  for(int i=1;i<k;i++)
    cout<<v[i]<<" ";
  cout<<endl;
}

int main()
{  int n,k, x[100];
   double v[100];
   CitireX (n,x);
   MediiPoz(n,x,k,v);
   Afisare (k,v);
   cout << "Program terminat" << endl;
   return 0;
}
