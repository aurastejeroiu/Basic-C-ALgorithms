#include <iostream>

using namespace std;

void Schimb(int& a, int& b){
   int aux=a;
       a=b;
       b=aux;
}

void Citire(int n, int v[]){
 cout<<"n=";cin>>n;;
 for(int i=1;i<=n;i++)
    cin>>v[i];
}

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
}
void InsertCresc(int n,int v[]){
    int cont=0, mut=0;
    for(int i=2;i<=n;i++){
        int aux=v[i];
        int j=i-1;
        cont++;
        while(j>0 && aux< v[j]){
            cont++;
            v[j+1]=v[j];
            j--;
            mut++;
        }
        v[j+1]=aux;
        Afis(n,v);
    }
   cout<<endl<<cont<<" comparari \"j>0 && aux< v[j]\"\ "<<endl;
   cout<<endl<<mut <<" mutari la dreapta"<<endl;
}

void InsertDesc(int n,int v[]){
    int cont=0, mut=0;
    for(int i=2;i<=n;i++){
        int aux=v[i];
        int j=i-1;
        cont++;
        while(j>0 && aux>v[j]){
            cont++;
            v[j+1]=v[j];
            j--;
            mut++;
        }
        v[j+1]=aux;
        Afis(n,v);
    }
   cout<<endl<<cont<<" comparari \"j>0 && aux< v[j]\"\ "<<endl;
   cout<<endl<<mut <<" mutari la dreapta"<<endl;
}

void IRecurCresc(int n,int v[], int i, int j, int aux){  //apel primar
   if(i<=n)                                         //IRecur(n,v,i=2,j=1,aux=v[2])
      { if(j>0 && aux<v[j])  {
          v[j+1]=v[j];
          IRecurCresc(n,v,i,j-1,aux);
        }
        else {v[j+1]=aux;
              Afis(n,v);
              IRecurCresc(n,v,i+1,i,aux=v[i+1]);
            }
      }
}

void IRecurDesc(int n,int v[], int i, int j, int aux){  //apel primar
   if(i<=n)                                         //IRecur(n,v,i=2,j=1,aux=v[2])
      { if(j>0 && aux>v[j])  {
          v[j+1]=v[j];
          IRecurDesc(n,v,i,j-1,aux);
        }
        else {v[j+1]=aux;
              Afis(n,v);
              IRecurDesc(n,v,i+1,i,aux=v[i+1]);
            }
      }
}



int main()
{   int v[100];
    int n,i,j,aux;
    bool ok;
    Citire(n,v);
    cout<<"before sorting:"<<endl;
    Afis (n-1,v);
    cout<<endl;
    //InsertCresc(n-1,v);
    //InsertDesc(n-1,v);
    //IRecurCresc(n-1,v,i=2,j=1,aux=v[2]);
    //IRecurDesc(n-1,v,i=2,j=1,aux=v[2]);
    //ICresc(n-1,v);
    //IDesc(n-1,v);

    cout<<endl;

    //cout << "\nVectorul sortat descresc:";
    //Afis (n-1,v);
    cout<<endl;;
    cout << "\nVectorul sortat cresc:";
    Afis (n-1,v);

    return 0;
}
