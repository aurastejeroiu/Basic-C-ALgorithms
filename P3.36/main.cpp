#include <iostream>
using namespace std;

void Comp(int n, int F[], int G[], int GF[])
{   for(int i=1;i<=n;i++)
        GF[i]=G[F[i]];
}
void CitesteF(int &m, int F[], int &n){
  cout<<"cardDomF=";cin>>m;
  cout<<"cardCodDomF=";cin>>n;
  for(int i=1;i<=m;i++){
    cout<<"F["<<i<<"]=";
    cin >>F[i];
  }
}
void CitesteG(int n, int G[], int &p){
  cout<<"cardCodDomG=";cin>>p;
  for(int i=1;i<=n;i++){
    cout<<"G["<<i<<"]=";
    cin >>G[i];
  }
}
int main()
{   int F[100], G[100], GoF[100];
    int n,m,p;
    CitesteF(m,F,n);
    CitesteG(n,G,p);
    Comp(m,F,G,GoF);
    for(int i=1;i<=m;i++)
        cout<<GoF[i]<<",";
    cout<<endl;
    cout<<"Hello world!" << endl;
    return 0;
}
