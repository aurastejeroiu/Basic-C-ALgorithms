#include <iostream>
#include <math.h>
using namespace std;

struct MatriceMN{
      int m;    //nr de linii
      int n;    //nr de coloane
      int elem[10][10];
};

void CitireMat(MatriceMN &A){
      cout<<"da numarul de linii:";
      cin >>A.m;
      cout<<"da numarul de coloane:";
      cin >>A.n;
      for(int i=0;i<A.m;i++)
        for(int j=0;j<A.n;j++){
          cout<<"Mat["<<i<<"]["<<j<<"]=";
          cin >>A.elem[i][j];               //se citesc doar 0 si 1
      }
}

void AfisMat(MatriceMN A){
      for(int i=0;i<A.m;i++){
        for(int j=0;j<A.n;j++)
          cout<<A.elem[i][j]<<" ";
        cout<<endl;
      }
}

int CalculBi (int i, MatriceMN A)
{   int S=0,Doi=1;
    for (int j=A.n-1;j>=0;j--){
        S+=A.elem[i][j]*Doi;
        Doi*=2;
    }
    return S;
}

void Trans10(MatriceMN A, int B[]){
    for (int i=0;i<A.m; i++){
        B[i]=CalculBi(i,A);
    }
}

void AfisVect(int l, int B[]){
   cout<<"numerele binare sunt:";
   for(int i=0;i<l;i++)
      cout<<B[i]<<" ";
   cout<<endl;
}


int main()
{   MatriceMN A;
    int BB[100];
    //CitireMat(A);
    int B[3][7]={{0,1,1,0,1,1,1},{1,1,1,1,0,1,0},{0,1,1,1,1,0,1}};
    int m=3;
    int n=7;
    A.m=m;
    A.n=n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          A.elem[i][j]=B[i][j];

    AfisMat(A);
    Trans10(A,BB);
    AfisVect(A.m,BB);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

