#include <iostream>

using namespace std;
void citire(int A[100][100],int& m,int& n,int& l,int& k){
    cout<<"Da dimensiunile matricei: ";
    cin>>m>>n;
    cout<<'\n';
    cout<<"Da elementele matricei : ";
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    cout<<'\n';
    cout<<"Da l si k: ";
    cin>>l>>k;
    cout<<'\n';
}
void afisare(int m,int n,int A[100][100]){
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<'\n';
    }
}
void schimbare(int linie1,int linie2,int n,int A[100][100]){
    for(int i=1;i<=n;i++)
    {
        int aux=A[linie1][i];
        A[linie1][i]=A[linie2][i];
        A[linie2][i]=aux;
    }
}
void rezolvare(int m,int n,int A[100][100],int l,int k){
    for(int i=1;i<l;i++)
        for(int j=i+1;j<=l;j++)
            if(A[i][k]>A[j][k]) schimbare(i,j,n,A);
    for(int i=l+1;i<m;i++)
        for(int j=i+1;j<=m;j++)
            if(A[i][k]<A[j][k]) schimbare(i,j,n,A);
}
int main()
{
    int n,m,l,k,A[100][100];
    citire(A,m,n,l,k);
    rezolvare(m,n,A,l,k);
    afisare(m,n,A);
    return 0;
}
