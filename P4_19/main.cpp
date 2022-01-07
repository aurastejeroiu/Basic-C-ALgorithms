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
int Pow (int b, int exp)
{   int Put=1;
    for (int i=0;i<exp;i++)
        Put=Put*b;
    return Put;
}

void Trans10(MatriceMN A){
    int Zece;
    for (int i=0;i<A.m; i++){
        Zece=0;
        for (int j=A.n-1; j>=0; j--)
            Zece=Zece + A.elem[i][j]*pow(2,A.n-1-j);
        cout<<Zece<<endl;
    }
}



int main()
{   MatriceMN A;
    CitireMat(A);
    AfisMat(A);
    Trans10(A);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

