#include <iostream>

using namespace std;
void rezolv (int n,int V[])
{
    int nr_elem=0,nr=1;
    while(nr_elem<n)
    {
        V[++nr_elem]=nr;
        for(int i=2;i<=nr/2 && nr_elem<n;i++)
        {
            if(nr%i==0) V[++nr_elem]=i;

        }
        nr++;
    }
}
void Afisare(int n,int V[])
{
    for(int i=1;i<=n;i++)
        cout<<V[i]<<" ";
}
int main()
{
    int n,V[1000];
    cin>>n;
    rezolv(n,V);
    Afisare(n,V);
    return 0;
}
