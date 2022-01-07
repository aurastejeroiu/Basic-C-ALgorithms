#include <iostream>

using namespace std;

void Schimb(int& a, int& b){
   int aux=a;
       a=b;
       b=aux;
}

void Citire (int &n, int v[]){
 cout<<"n=";cin>>n;
 for(int i=1;i<=n;i++)
    cin>>v[i];
 cout<<endl;
}

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
}
void NCresc(int n,int v[]){
    int Nr[n+1],Aux[n+1];
    for(int i=1;i<=n;i++)
        Nr[i]=1;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
          if(v[i]<v[j]) Nr[j]++;
          else          Nr[i]++;

    Afis(n,Nr);
    for(int i=1;i<=n;i++)
        Aux[Nr[i]]=v[i];
    Afis(n,Aux);

    for(int i=1;i<=n;i++)
        v[i]=Aux[i];
    Afis(n,v);
}


void NDesc(int n,int v[]){
    int Nr[n+1],Aux[n+1];
    for(int i=1;i<=n;i++)
        Nr[i]=1;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
          if(v[i]>v[j]) Nr[j]++;
          else          Nr[i]++;

    Afis(n,Nr);
    for(int i=1;i<=n;i++)
        Aux[Nr[i]]=v[i];
    Afis(n,Aux);

    for(int i=1;i<=n;i++)
        v[i]=Aux[i];
    Afis(n,v);
}


int main()
{   int v[100];
    int n,i,j,aux;
    bool ok;
    Citire(n,v);
     Afis(n,v);

    //NCresc(n-1,v);
    //NDesc (n-1,v);


    cout<<endl;


    cout << "\nVectorul sortat cresc:";
    Afis (n-1,v);

    return 0;
}
