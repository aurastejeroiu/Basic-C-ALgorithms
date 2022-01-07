#include <iostream>
#include <iomanip>
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
      for(int i=1;i<=A.m;i++)
        for(int j=1;j<=A.n;j++){
          cout<<"Mat["<<i<<"]["<<j<<"]=";
          cin >>A.elem[i][j];               //se citesc doar 0 si 1
      }
}

void AfisMat(MatriceMN A){
      for(int i=1;i<=A.m;i++){
        for(int j=1;j<=A.n;j++)
          cout<<setw(3)<<A.elem[i][j];
        cout<<endl;
      }
}

void Inter(MatriceMN &A){
   int i,j,aux;
   for(i=1;i<=A.n;i++){
      j = A.n-i+1;
      aux          =  A.elem[i][i];
      A.elem[i][i] =  A.elem[i][j];
      A.elem[i][j] =aux;

   }


}

int main()
{   MatriceMN A;
    CitireMat(A);
    AfisMat(A);
    Inter(A);
    AfisMat(A);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

