#include <iostream>

using namespace std;

void PozMaxNeg(int n, int x[],int &k, int P[]){
  int i=1;
  while(i<=n && x[i]>=0)
    i++;
  if(i<=n) {
    P[k=1]=i;          ///initializarea cu primul negativ
    for(int j=i+1;j<=n;j++){
        if(x[j]==x[P[1]]) P[++k]=j;
        else if(x[j]<0 && x[j]>x[P[1]]) P[k=1]=j;
   }
  }
  else k=0;
}

int main()
{  int n=9, x[10]={0,5,100,1,2,3,1,25,1,2};
   int k;
   int P[100];
   PozMaxNeg(n,x,k,P);
   if(k==0) cout<<"nu exista numere negative ";
   else
   { cout<<"val max negativa="<<x[P[1]]<<" se afla pe poz: ";
     for(int i=1;i<=k;i++)
        cout<<P[i]<<',';


   }
    cout << "\b \nProgram terminat" << endl;
    return 0;
}
