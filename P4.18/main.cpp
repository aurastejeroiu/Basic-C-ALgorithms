#include <iostream>
#include <iomanip>

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
          cout<<setw(4)<<A.elem[i][j];
        cout<<endl;
      }
}
int suma( int i , MatriceMN A)
{   int nr=0,j;
    for(j=0;j<A.n;j++)
        nr+=A.elem[i][j];
    return nr;
}
void OrdSuma(MatriceMN &A){
    int i,j,k,aux;
    for(i=0;i<A.m-1;i++)
        for(k=i+1;k<A.m;k++)
           if(suma(i, A)<suma(k,A))
            { for(j=0;j<A.n;j++)
                {aux=A.elem[i][j];
                 A.elem[i][j]=A.elem[k][j];
                 A.elem[k][j]=aux;
                }

            }

}


int main()
{   MatriceMN A;
    //CitireMat(A);
    int B[5][3]={{1,2,3},{-1,4,5},{6,7,8},{12,13,14},{-9,10,11}};
    int m=5;
    int n=3;
    A.m=m;
    A.n=n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          A.elem[i][j]=B[i][j];
    cout<<"Matricea inainte de sortare:\n";
    AfisMat(A);
    OrdSuma(A);
    cout<<"Matricea dupa sortare:\n";
    AfisMat(A);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

