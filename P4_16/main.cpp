#include <iostream>

using namespace std;

struct MatriceMN{
      int m;    	//nr de linii
      int n;    	//nr de coloane
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
          cin >>A.elem[i][j];
      }
}

void AfisMat(MatriceMN A){
      for(int i=0;i<A.m;i++){
        for(int j=0;j<A.n;j++)
          cout<<A.elem[i][j]<<" ";
        cout<<endl;
      }
}

void Propor(MatriceMN A, int& l1, int& l2){
    int j,L1=0;
    while (L1<A.m-1 && (l1==-1 && l2==-1)){  //se poate testa doar una dintre l1 sau l2 cu -1
       int L2=L1+1;
       while (L2<A.m && (l1==-1 && l2==-1)) {
            j=0;
            while (j<A.n-1 && (A.elem[L1][j]*A.elem[L2][j+1])== (A.elem[L2][j]*A.elem[L1][j+1])) j++;
            if (j>=A.n-1) {
                    l1=L1;
                    l2=L2;
            }
            L2++;
          }
      L1++;
    }
}



int main()
{   MatriceMN A;
    CitireMat(A);
    int l1,l2;
    l1=l2=-1;
    Propor(A,l1,l2);
    AfisMat(A);
    if(l1==-1) cout<<"matricea nu are linii proportionale";
    else cout<<"liniile "<<l1<<" si " <<l2<<" sunt proportionale";
    cout << endl<<"Program terminat" << endl;
    return 0;
}
