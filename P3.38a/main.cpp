#include <iostream>

using namespace std;
bool identica(int F[],int n)
{
    for(int i=1;i<=n;i++)
        if(F[i]!=i) return false;
    return true;                    /// verificam daca permutarea e identica
}
int ordin (int n,int F[])
{
    int G[1000],k=1,Z[1000];
    for(int i=1;i<=n;i++) G[i]=F[i];
    while(!identica(G,n))               ///cream o permutare ajutatoare cat timp nu e
    {                                   /// identica si vom inmulti permutarea G cu
        for(int i=1;i<=n;i++)           /// permutarea P si o stocam intr un sir auxiliar
            Z[i]=G[F[i]];               /// copiem continutul sau in G si crestem
        for(int i=1;i<=n;i++)           /// pe k
            G[i]=Z[i];
        k++;
    }
    return k;
}
int main()
{
    int n,F[1000];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>F[i];
    cout<< ordin(n,F);
    return 0;
}
