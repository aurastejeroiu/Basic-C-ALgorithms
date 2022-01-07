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

int MaxDiagP(MatriceMN A)
{
    int Max=A.elem[A.n][1];
    cout<<"Max init:"<<Max<<endl;
    int i,j,k,s;
    for(i=A.n-1;i>=2;i--)
    {   s=0;k=i;
        for(j=1;j<=A.n-i+1;j++)
        {  s+=A.elem[k][j];
           k++;
        }
        cout<<s<<endl;
        if(s>Max)  Max=s;
    }

    for(j=2;j<=A.n;j++)
     { s=0;k=j;
       for(i=1;i<=A.n-j+1;i++)
        { s+=A.elem[i][k];
          k++;
        }
        cout<<s<<endl;
        if(s>Max)  Max=s;
    }
    return Max;
}
int main()
{   MatriceMN A;
    CitireMat(A);
    AfisMat(A);
    cout<<MaxDiagP(A);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

