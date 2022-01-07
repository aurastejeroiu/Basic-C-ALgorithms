#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
///Se dau a,b cu  a<b din N si un sir X de n elemente intregi.
///Sa se elimine din sirul X, elementele dn intervalul [a,b]


int Distanta(int n, int X[],int Y[])
{   int d=0;
    int  i;
    for(i=1;i<=n;i++)
      { if ((X[i]-Y[i])>0) d+=X[i]-Y[i];  ///trebuie adunate |x[i]-y[i]| in d
        else               d+=Y[i]-X[i];
      }
    return d;
}

void Citire(int&n,  int X[], int Y[]){
    cout<<"cate numere dai:";
    cin >>n;                    ///citeste dimensiunea sirului
    for (int i=1;i<=n;i++)      ///citeste elementele sirului X
    { cout<<"X["<<i<<"]=";
      cin >>X[i];
    }
    for (int i=1;i<=n;i++)      ///citeste elementele sirului Y
    { cout<<"Y["<<i<<"]=";
      cin >>Y[i];
    }
}
int MaxMin(int n, int X[],int Y[]){
    int Max;
    if(X[1]<Y[1]) Max=X[1];
    else          Max=Y[1];
    for(int i=2;i<=n;i++)
    { int min;
      if(X[i]<Y[i]) min=X[i];
      else          min=Y[i];
      if(min>Max) Max=min;
    }
    return Max;
}

int main(){
    int     X[100],Y[100];
    int     n;
    Citire (n,X,Y);         ///apel citire date
    cout    <<"d="<< Distanta(n,X,Y)<<endl;
    cout    << " max din minime este: "<<MaxMin(n,X,Y);     ///apel si afisare max din minime
    return  0;
}


