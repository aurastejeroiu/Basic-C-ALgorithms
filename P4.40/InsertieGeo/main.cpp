#include <iostream>

using namespace std;

void Schimb(int& a, int& b){
   int aux=a;
       a=b;
       b=aux;
}

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
}
void ICresc(int n,int v[]){
    int comp=0, mut=0;
    for(int i=2;i<=n;i++){
        int aux=v[i];
        int j=i-1;
        comp++;
        while(j>0 && aux< v[j]){
            comp++;
            v[j+1]=v[j];
            j--;
            mut++;
        }
        v[j+1]=aux;
        cout<<"iterativu\':";Afis(n,v);
    }
   cout<<endl<<comp<<" comparari \"j>0 && aux< v[j]\"\ "<<endl;
   cout<<endl<<mut <<" mutari la dreapta"<<endl;
}

void IRecur(int n,int v[], int i, int j, int aux){  //apel primar
   if(i<=n)                                         //IRecur(n,v,i=2,j=1,aux=v[2])
      { if(j>0 && aux<v[j])  {
          v[j+1]=v[j];
          IRecur(n,v,i,j-1,aux);
        }
        else {v[j+1]=aux;
              Afis(n,v);
              IRecur(n,v,i+1,i,aux=v[i+1]);
            }
      }
}


void IDescr(int n,int v[]){
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(v[i]<v[j]) Schimb(v[i],v[j]);
    Afis(n,v);
}

int main()
{   int v[]={0,3,-9,123,17,-333,-56,7,27};
    int n=8,i,j,aux;
    bool ok;
    cout<<"before sorting:"<<endl;
    Afis (n,v);
    cout<<endl;
    //IRecur(n,v,i=2,j=1,aux=v[2]);
    ICresc(n,v);
    cout<<'\n';

    cout<<endl;

    //cout << "\nVectorul sortat descresc:";
    //Afis (n-1,v);

    cout<<endl;;
    cout << "\nVectorul sortat cresc:";
    Afis (n-1,v);

    return 0;
}
