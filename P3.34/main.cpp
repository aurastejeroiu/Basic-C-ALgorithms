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
    cin >>F[i];
  }
}

bool EsteFunctie(int m,int F[], int n){
  for(int i=1;i<=m;i++)
     if(F[i]<0 || F[i]>n) return false;
  return true;
}

bool Injectiva(int m, int F[], int n)
{   if(!EsteFunctie(m,F,n)) return false;
    if(m>n) return false;
    for(int i=1;i<m;i++)
        for(int j=i+1; j<=m;j++)
          if(F[i]==F[j]) return false;
    return true;

}

bool Exista(int m, int F[], int val)
{  for(int i=1;i<=m; i++)
     if(val==F[i]) return true;
   return false;
}

bool Surjectiva(int m, int F[], int n)
{   if(!EsteFunctie(m,F,n)) return false;
    if(m<n) return false;
    for(int i=1; i<=n;i++)
        if(!Exista(m,F,i)) return false;
    return true;
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
