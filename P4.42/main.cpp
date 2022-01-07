#include <iostream>
#include <cmath>
using namespace std;
void citire(int& n,int x[]){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i];
}
void afisare(int A[100][100],int m)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<A[i][j]<<" ";
        cout<<'\n';
    }
}
int maximSir(int x[],int j,int i){
    int maxim=x[j];
    for(int k=j+1;k<=i;k++)
        if(x[k]>maxim) maxim=x[k];
    return maxim;
}
void rezolvare(int x[],int A[100][100],int m){
int indice=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(i<j)       A[i][j]=x[++indice];
            else if(i==j) A[i][j]=x[i*i];
            else          A[i][j]=maximSir(x,j,i);
}
int main()
{
    int n,m,x[100],A[100][100];
    citire(n,x);
    m=sqrt(n);
    rezolvare(x,A,m);
    afisare(A,m);
    return 0;
}
