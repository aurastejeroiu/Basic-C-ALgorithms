#include <iostream>

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

void AddCol(MatriceMN& A){
    int Max;
    for (int i=0;i<A.m; i++){
        int j=0;
        while (j<A.n && A.elem[i][j]>=0) j++;
        if(j>=A.n)
                A.elem[i][A.n]=10;
        else {
            Max=A.elem[i][j];
            for(int k=j;k<A.n;k++)
                if(A.elem[i][k]<0 && A.elem[i][k]>Max) Max=A.elem[i][k];
            A.elem[i][A.n]=Max;
        }
    }
    A.n++;
}



int main()
{   MatriceMN A;
    CitireMat(A);
    AfisMat(A);
    AddCol(A);
    cout<<endl;
    AfisMat(A);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

