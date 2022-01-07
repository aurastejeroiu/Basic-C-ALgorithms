#include <iostream>

using namespace std;


void CitValFunc(int &m,int F[],int &n)  //m= card(Dom) , n=card(CoDom)
{ cout<<"da dim Domeniu:";
  cin >>m;
  cout<<"da dim CoDomeniu:";
  cin >>n;
  for(int i=1;i<=m;i++)
  { int aux;
    cout<<"f["<<i<<"]=";
    cin >>aux;
    while(aux<1 || aux>n)
    {  cout<<" da valori intre 1 si " <<n<<endl;
       cout<<"f["<<i<<"]=";
       cin >>aux;
    }
    F[i]=aux;
  }
}

int Injectiva(int m, int F[], int n)
{
    if(m>n) return 0;
    for(int i=1;i<=m-1;i++)
        for(int j=i+1; j<=m;j++)
          if(F[i]==F[j]) return 0;
    return 1;

}

int Exista(int m, int F[], int val)
{  int i=1;
   while (i<=m && F[i]!=val) i++;
   if(i>m) return 0;
   else    return 1;

}
int Surjectiva(int m, int F[], int n)
{
    if(m<n) return 0;
    for(int i=1; i<=n;i++)
        if(!Exista(m,F,i)) return 0;
    return 1;
}

void AfisF(int m, int F[])
{
    cout<<"valorile functiei:";
    for(int i =1;i<=m;i++) cout<<F[i]<<" ";
    cout<<endl;



}


int main()
{   int m,n,F[100];
    CitValFunc(m,F,n);
    AfisF(m, F);
    if(Injectiva(m,F,n)) cout<<"f este injectiva";
    else                 cout<<"f nu este injectiva";
    cout<<endl;
    if(Surjectiva(m,F,n)) cout<<"f este surjectiva";
    else                  cout<<"f nu este surjectiva";

    cout<<"\nprogram terminat";
    return 0;
}
