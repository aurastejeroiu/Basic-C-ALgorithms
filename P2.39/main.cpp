#include <iostream>
using namespace std;
void citire(int n, int X[]){
    for(int i=1;i<=n;i++)       cin>>X[i];
}
void afisare(int n, int X[]){
    for(int i=1;i<=n;i++)       cout<<X[i]<<" ";
}
void sirNou(int n,int X[],int Y[],int C[], int &k){
    k=0;
    for(int i=1;i<=n;i++)
        if(X[i]==Y[i])          C[++k]=i;

}
int main()
{   int  n,k=0;
    int  X[100],Y[100],C[100];
    cin>>n;
    citire(n,X);
    citire(n,Y);
    sirNou(n,X,Y,C,k);
    afisare(k,C);
    return 0;
}

