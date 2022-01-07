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
void S1Cresc(int n,int v[]){
    int comp=0, sch=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            comp++;
            if(v[i]>v[j]) {Schimb(v[i],v[j]);sch++;}
        }
        Afis(n,v);
    }
   cout<<endl<<comp<<" comparari S1"<<endl;
   cout<<endl<<sch<<" interschimbari S1"<<endl;
}
void S1Recur(int n, int v[],int i, int j){  ///apelul primar S1recur(n,v,i=1,j=2)
   if(i<n){
        if(j<=n){
            if(v[i]>v[j]) Schimb(v[i],v[j]);
            S1Recur(n,v,i,j+1);
        }
        else{Afis(n,v);
             S1Recur(n,v,i+1,i+2);
            }
   }
}
                                        ///apel primar S2Recur(n,v,i=1,j=2,pMin=1)
void S2Recur(int n, int v[], int i, int j, int pMin){
  if(i<n){
        if(j<=n){
            if(v[j]<v[pMin]) pMin=j;
            S2Recur(n,v,i,j+1,pMin);
        }
        else{cout<<"pMin="<<pMin;
             Schimb(v[i],v[pMin]);
             Afis(n,v);
             S2Recur(n,v,i+1,i+2,i+1);
            }
   }
}

void S2Cresc(int n,int v[]){
    int comp=0, sch=0;
    for(int i=1;i<n;i++){
        int pMin=i;
        for(int j=i+1;j<=n;j++){
            comp++;
            if(v[j]<v[pMin]) {pMin=j;}
        }
        Schimb(v[i],v[pMin]);
        sch++;
        Afis(n,v);
    }
   cout<<endl<<comp<<" comparari S2"<<endl;
   cout<<endl<<sch<<" interschimbari S2"<<endl;
}




void S1descr(int n,int v[]){
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(v[i]<v[j]) Schimb(v[i],v[j]);
    Afis(n,v);
}

int main()
{   int v[]={0,3,-9,123,17,-333,-56,7,27};
    int n=8,i,j;
    int pMin;
    bool ok;
    cout<<"vectorul inainte de sortare";
    Afis (n,v);
    cout<<"\nvectorul in timpul sortarii\n";
    //S1Cresc(n,v);
    S2Cresc(n,v);
    //S1Recur(n,v,i=1,j=2);
    //S2Recur(n,v,i=1,j=2,pMin=1);
    cout<<'\n';
    //S2Cresc(n,v);

    cout<<endl;

    //cout << "\nVectorul sortat descresc:";
    //Afis (n,v);
    //B2Cresc(n,v);
    cout<<endl;;
    cout << "\nVectorul sortat cresc:";
    Afis (n,v);

    return 0;
}
