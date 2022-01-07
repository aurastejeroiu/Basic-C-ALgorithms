#include <iostream>

using namespace std;

void CreV(int n, int V[]){
    int N;          /// indice in sirul numerelor naturale;
    int k;          /// indice in vectorul V
    int i;          /// indice pentru sirul 1,2,...,N
    V[1]=N=k=1;
    while(k<n){
        N++;
        i=1;
        while(k<n && i<=N)
            V[++k]=i++;
    }

}

void AfisV(int n, int V[]){
      for(int i=1;i<=n;i++)
        cout<<V[i]<<" ";

}
int main()
{
    int n,V[1000];               ///n e lungimea lui  V
    cout<<"da n:"; cin>>n;
    CreV  (n,V);
    AfisV (n,V);
    return 0;
}
