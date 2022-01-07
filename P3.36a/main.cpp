#include <iostream>

using namespace std;
bool functie(int F[],int m,int n)
{
    for(int i=1;i<=m;i++)
        if(F[i]<1 || F[i]>n) return false; /// verific daca e functie
    return true;
}
void compunere(int F[],int G[],int m,int n,int p)
{
    if(!(functie(F,m,n) && functie(G,n,p)))
        cout<<"functiile nu sunt corect definite "; /// verificam daca sunt functii
    else
        for(int i=1;i<=m;i++)
        cout<<"G compus cu F aplicat lui "<< i<< " este egal cu "<<G[F[i]]<<endl; ///aplicam compunerea functiilor

}
int main()
{
    int n,m,p,F[1000],G[1000];
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++) cin>>F[i];
    for(int i=1;i<=n;i++) cin>>G[i];
    compunere(F,G,m,n,p);
    return 0;
}
