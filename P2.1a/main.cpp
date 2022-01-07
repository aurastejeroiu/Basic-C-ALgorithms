#include <iostream>

using namespace std;

void DivN(long n, int &m, long D[]){
  m=2;
  D[1]=1;D[2]=n;
  long d;
  for(d=2;d*d<n;d++)
     if(n%d==0) {
       D[++m]=d;
       D[++m]=n/d;
     }
  if(d*d==n) D[++m]=d;
}

void Afisare(int m, long D[]){
   cout<<"divizorii sunt:";
   for(int i=1;i<=m;i++)
     cout<<D[i]<<" ";

}
int main()
{   long n;
    int m;
    long D[1000];
    cout<<"da n:";
    cin >>n;
    DivN(n,m,D);
    Afisare(m,D);
    cout << "\nProgram terminat" << endl;
    return 0;
}
