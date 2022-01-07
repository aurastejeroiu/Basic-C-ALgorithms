#include <iostream>
using namespace std;

void Citire(int &n, int X[]){
    cout<<"Da n:" ;      cin>>n;
    cout<<"Da sirul:\n";
    for(int i=1;i<=n;i++)
                        cin>>X[i];
}
void Afis(int n,int a[])
{   if(n==0) cout<<" este vid\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
bool asemenea(int n, int m){
    int VAp1[10]={0};
    int VAp2[10]={0};
    while(n){
        VAp1[n%10]=1;
        n/=10;
    }
    while(m){
        VAp2[m%10]=1;
        m/=10;
    }
    for(int i=0;i<=9;i++)
        if(VAp1[i]!=VAp2[i])     return false;   ///atunci cifra i e prezenta doar intr-un numar
    return true;
}

void puneR(int n,int x[],int st,int dr,int &m,int R[])
{ for(int i=st;i<=dr;i++)
    R[++m]=x[i];
}
void stergeunul(int &n,int X[],int i)
{  while(i<n)
    {  X[i]=X[i+1];
       i++;
    }
    n--;
}
void sterge(int &n,int X[],int st,int dr)
{   int d=dr-st+1;
    for(int i=1;i<=d;i++)
        stergeunul(n,X,st);
}
void DetSecv(int n,int X[],int i,int &dr)
{   dr=i;
    while(dr<n && asemenea(X[i],X[dr+1]))dr++;
}
void CreareR(int &n, int X[], int &m, int R[]){
    int i=1,dr=1;
    m=0;
    while(i<n)
    {   DetSecv(n,X,i,dr);
        if(dr>i)
        {   puneR(n,X,i,dr,m,R);
            sterge(n,X,i,dr);
        }
        else
            i++;
    }
}


int main()
{
    int n,X[100],m,R[100];
    Citire(n,X);
    CreareR(n,X,m,R);

    cout<<"sirul X:";
    Afis(n,X);
    cout<<"sirul R:";
    Afis(m,R);
    return 0;
}
