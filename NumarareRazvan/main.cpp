#include <iostream>

using namespace std;

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
}

void NCresc(int n,int v[]){
    int Nr[n+1],Aux[n+1];           //vectorul Nr numara pozitia finala
                                    //vectorul aux pentru procedura intermediara
    for(int i=1;i<=n;i++)           //initializarea cu 1 a lui Nr
        Nr[i]=1;
    Afis(n,Nr);

    for(int i=1;i<n;i++)            //determinarea vectorului Nr
        for(int j=i+1;j<=n;j++)
          if(v[i]>v[j]) Nr[i]++;
          else          Nr[j]++;

    Afis(n,Nr);

    for(int i=1;i<=n;i++)           //crearea vectorului Aux
        Aux[Nr[i]]=v[i];

    Afis(n,Aux);

    for(int i=1;i<=n;i++)           //copiere lui Aux in v

        v[i]=Aux[i];

    Afis(n,v);
}



void NDescr(int n,int v[]){

}

int main()
{   int v[]={0,3,-99,-123,17,-333,56,7,27};
    int n=8,i,j,aux;
    bool ok;
    Afis(n,v);
    NCresc(n,v);



    cout<<endl;


    cout << "\nVectorul sortat cresc:";
    Afis (n,v);

    return 0;
}
