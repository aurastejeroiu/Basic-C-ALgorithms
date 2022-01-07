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
          cout<<setw(5)<<A.elem[i][j];
        cout<<endl;
      }
}

int MaxJ(int j, MatriceMN A)
{   int Max=A.elem[0][j];
    for(int i=1;i<A.m;i++)
        if(A.elem[i][j]>Max)
            Max=A.elem[i][j];
    return Max;
}

int MinI(int i, MatriceMN A)
{
    int Min=A.elem[i][0];
    for(int j=1;j<A.n;j++)
        if(A.elem[i][j]<Min)
            Min=A.elem[i][j];
    return Min;
}
void VerfSa(MatriceMN A)
{
    int cnt=0;
    for(int i=0;i<A.m;i++)
    {   int Min=MinI(i,A);
        for(int j=0;j<A.n;j++)
            if(Min==MaxJ(j,A))
            {   cout<<endl<<A.elem[i][j]<<" este sa"<<endl;
                cnt++;
            }
    }
    if(cnt==0)
        cout<<"nu exista numere sa";
}
int main()
{   MatriceMN A;
    ///CitireMat(A);
    int B[5][3]={{1,2,3},{-1,4,5},{6,7,8},{12,13,14},{-9,10,11}};
    int m=5;
    int n=3;
    A.m=m;
    A.n=n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          A.elem[i][j]=B[i][j];
    cout<<"Matricea data:\n";
    AfisMat(A);
    VerfSa(A);
    cout << endl<<"Program terminat" << endl;
    return 0;
}

