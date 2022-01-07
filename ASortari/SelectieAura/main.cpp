#include <iostream>

using namespace std;

void Schimb(int& a, int& b){
   int aux=a;
       a=b;
       b=aux;
}
void Citire (int &n, int v[]){
 cout<<"n=";cin>>n;
 for(int i=1;i<=n;i++)
    cin>>v[i];
 cout<<endl;
}

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
}
void S1Cresc(int n,int v[]){
    int cont=0, sch=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cont++;
            if(v[i]>v[j]) {Schimb(v[i],v[j]);sch++;}
        }
        Afis(n,v);
    }
   cout<<endl<<cont<<" comparari S1"<<endl;
   cout<<endl<<sch<<" interschimbari S2"<<endl;
}

void S1Desc(int n,int v[]){
    int cont=0, sch=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cont++;
            if(v[i]<v[j]) {Schimb(v[i],v[j]);sch++;}
        }
        Afis(n,v);
    }
   cout<<endl<<cont<<" comparari S1"<<endl;
   cout<<endl<<sch<<" interschimbari S2"<<endl;
}


void S1RecurCresc(int n, int v[],int i, int j){  ///apelul primar S1RecurCresc(n,v,i=1,j=2)
   if(i<n){
        if(j<=n){
            if(v[i]>v[j]) Schimb(v[i],v[j]);
            S1RecurCresc(n,v,i,j+1);
        }
        else{Afis(n,v);
             S1RecurCresc(n,v,i+1,i+2);
            }
   }
}

void S1RecurDesc(int n, int v[],int i, int j){  ///apelul primar S1RecurDesc(n,v,i=1,j=2)
   if(i<n){
        if(j<=n){
            if(v[i]>v[j]) Schimb(v[i],v[j]);
            S1RecurDesc(n,v,i,j+1);
        }
        else{Afis(n,v);
             S1RecurDesc(n,v,i+1,i+2);
            }
   }
}

   void S2Cresc(int n,int v[]){
    int cont=0, sch=0;
    for(int i=1;i<n;i++){
        int pMin=i;
        for(int j=i+1;j<=n;j++){
            cont++;
            if(v[j]<v[pMin]) {pMin=j;}
        }
        Schimb(v[i],v[pMin]);
        sch++;
        Afis(n,v);
    }
   cout<<endl<<cont<<" comparari S2"<<endl;
   cout<<endl<<sch<<" interschimbari S2"<<endl;
}

 void S2Desc(int n,int v[]){
    int cont=0, sch=0;
    for(int i=1;i<n;i++){
        int pMin=i;
        for(int j=i+1;j<=n;j++){
            cont++;
            if(v[j]>v[pMin]) {pMin=j;}
        }
        Schimb(v[i],v[pMin]);
        sch++;
        Afis(n,v);
    }
   cout<<endl<<cont<<" comparari S2"<<endl;
   cout<<endl<<sch<<" interschimbari S2"<<endl;
}


                                        ///apel primar S2RecurCresc(n,v,i=1,j=2,pMin=1)
void S2RecurCresc(int n, int v[], int i, int j, int pMin){
  if(i<n){
        if(j<=n){
            if(v[j]<v[pMin]) pMin=j;
            S2RecurCresc(n,v,i,j+1,pMin);
        }
        else{Schimb(v[i],v[pMin]);
             Afis(n,v);
             S2RecurCresc(n,v,i+1,i+2,i+1);
            }
   }
}

                                        ///apel primar S2RecurDesc(n,v,i=1,j=2,pMin=1)
void S2RecurDesc(int n, int v[], int i, int j, int pMin){
  if(i<n){
        if(j<=n){
            if(v[j]>v[pMin]) pMin=j;
            S2RecurDesc(n,v,i,j+1,pMin);
        }
        else{Schimb(v[i],v[pMin]);
             Afis(n,v);
             S2RecurDesc(n,v,i+1,i+2,i+1);
            }
   }
}


int main()
{   int v[]={0,3,-99,-123,17,-333,56,7,27,-100};
    int n=10,i,j;
    int pMin;
    bool ok;
    Citire(n,v);
    cout<<"\nVectorul initial este:";
    Afis(n-1,v);

    //S1Cres(n-1,v);
    //S1Desc(n-1,v);
    //S1RecurCresc(n,v,i=1,j=2);
    //S1RecurDesc(n,v,i=1,j=2);
    //S2Cres(n-1,v);
    //S2Desc(n-1,v);
    //S2RecurCresc(n,v,i=1,j=2,pMin=1)
    //S2RecurDesc(n,v,i=1,j=2,pMin=1)
    cout<<endl;


    cout<<endl;;
    cout << "\nVectorul sortat :";
    Afis (n-1,v);

    return 0;
}
