#include <iostream>

using namespace std;

void A(int m, int X[],  int& I1, int& lung, int& I2){
  for(int i=1;i<=m;i++){
    for (int j=i+1;j<=m;j++) {
      int k=0;
      while ((i+k<=m) && (j+k<=m) && (X[i+k]==X[j+k]))
            	k++;
      if (k>lung)
           { I1  =i;
             lung=k;
             I2  =j;
         }//end if
    }//end for
  }//end for
}//end A

int main() {
    int n=8;
    int V[]={0,1,1,2,1,1,1,1,2};
    int I1,I2,lung;
    I1=I2=lung=0;
    A(n,V,I1,lung,I2);
    cout<<"Secventa data:";
    for(int i=1;i<=n;i++)
        cout<<V[i]<<", ";
    if(lung==0) cout <<"\nnu exista nici macar element care se repeta";
    else{ cout<<"\nsecventa:";
          for(int k=I1;k<=lung;k++)
            cout<<V[k]<<", ";
          cout<<"\nprima  pozitie:"<<I1<<endl;
          cout<<"a doua pozitie:"<<I2<<endl;
    }
    cout << "\n Program terminat" << endl;
    return 0;
}
