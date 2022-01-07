#include <iostream>

using namespace std;
void rezolvare(int n,int V[])
{
    int nr_elem=0,div,ultim=-1,p=1;
    while(nr_elem<n)
    {
        V[++nr_elem]=p;                             /// punem numarul in sir
        ultim=-1;
        for(div=2;div<=p/2 && nr_elem<n;div++)      /// parcurgem divizorii proprii
            if(!(p%div))
            {
                ultim=div;                          /// retinem ultimul divizor
                V[++nr_elem]=div;
            }
        if(ultim!=-1)                                       /// daca are cel putin un divizor propriu
                for(int i=1;i<ultim && nr_elem<n;i++)       /// il punem in sir de d ori
                V[++nr_elem]=ultim;
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
