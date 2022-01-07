#include <iostream>

using namespace std;

int ValPol(int n, int P[], int x) {
   int i,Val=0;
   for(i=0;i<=n;i++)
        Val=Val*x+P[i];
   return Val;
}

int VPRec(int n, int P[], int x){
   if(n==0) return P[0];
   else     return VPRec(n-1, P, x)*x +P[n];
}


int main()
{   int P[10];
    int n=2;
    P[0]=1;P[1]=2;P[2]=1;
    cout<<ValPol(n,P,-1)<<endl;
    cout<<VPRec(n,P,-1)<<endl;
    cout << "Program terminat!" << endl;
    return 0;
}
