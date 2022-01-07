#include <iostream>

using namespace std;
bool prim(int x)
{   if(x<2) return 0;
    if(x%2==0 && x>2) return 0;        ///verificare daca un numar e prim
    for(int i=3; i*i<=x; i=i+2)
        if(x%i==0) return 0;
    return 1;
}
void rezolvare(int n,int V[])
{
    int nr_elem=0,p=1,div;
    while(nr_elem<n)
    {
            V[++nr_elem]=p;
        if(prim(p))                     /// verificam daca p e compus sau nu
            V[++nr_elem]=p;
        else
            for(div=2;div<=p/2 && nr_elem<n;div++)
                if(p%div==0) V[++nr_elem]=div;      /// daca e compus punem in sir divizorii lui proprii
            p++;
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
    cout<<"n= ";
    cin>>n;
    rezolvare(n,V);
    Afisare(n,V);
    return 0;
}
