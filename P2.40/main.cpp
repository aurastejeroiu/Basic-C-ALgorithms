#include <iostream>

using namespace std;

void Citire(int n, int X[], char sir){
    for (int i=1;i<=n;i++)      //citeste elementele sirului X
    { cout<<sir<<"["<<i<<"]=";
      cin >>X[i];
    }
}

void ConstructZ(int n, int X[], int Y[],  int Z[]){
    for(int i=1;i<=n;i++){
        if(X[i]<=0){
            if(X[i]>Y[i])   Z[i]=X[i];
            else            Z[i]=Y[i];
         }
        else{
            if(X[i]<Y[i])   Z[i]=X[i];
            else            Z[i]=Y[i];
        }
    }
}

void Afisare(int n, int Z[]){
    cout<<"Sirul Z este:";
    for(int i=1;i<=n;i++)cout<<Z[i]<<" ";
    cout<<endl;
}

int main()
{   int X[100], Y[100], Z[100];
    int n;
    cout<<"cate numere dai:";
    cin >>n;                    //citeste dimensiunea sirurilor
    Citire      (n,X,'X');
    Citire      (n,Y,'Y');
    ConstructZ  (n,X,Y,Z);
    Afisare     (n,Z);
    return 0;
}
