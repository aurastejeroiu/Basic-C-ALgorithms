#include <iostream>

using namespace std;
bool prim(int x)
{
    if(x<2) return 0;
    if(x%2==0 && x>2) return 0;        ///verificare daca un numar e prim
    for(int i=3; i*i<=x; i=i+2)
        if(x%i==0) return 0;
    return 1;
}
void rezolvare(int n,int V[])
{
    int nr_elem=0,p=1;
    while(nr_elem<n)
    {
        if(prim(p))                                /// daca p e prim adaugam in sir
            for(int i=1;i<=p && nr_elem<n;i++)     /// nr de la 1 la p
                V[++nr_elem]=i;
        else
        for(int i=1;i<=p && nr_elem<n;i++)         /// altfel adaugam de p ori numarul
            V[++nr_elem]=p;                        /// p in sir
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
