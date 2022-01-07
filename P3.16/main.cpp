#include <iostream>

using namespace std;

void DinPinZece(long n, long p, long& Zece){
  Zece=0;
  int PutP=1;
  while(n){             ///PutP=1,p,p^2,p^3,...
    Zece+=(n%10)*PutP;  ///la Zece se aduna pe rand ultima cifra* p^i
    PutP*=p;
    n/=10;              ///scapam de ultima cifra
  }
}

void Din10InQ(long Zece, long q, long& InQ){
   long Put10=1;        ///Put10=1,10,100,1000,...
   InQ=0;
   while(Zece){
      InQ+=(Zece%q)*Put10;///la Inq se aduga restul Zece%q*10^i
      Zece/=q;          ///scapam de ultims cifra
      Put10*=10;
   }
}

int main()
{   long n=542;
    long Zece,InQ;
    long p=6,q=8;
    DinPinZece(n,p,Zece);
    cout<<Zece<<endl;
    Din10InQ  (Zece,q,InQ);

    cout<<InQ<<endl;

    cout << "Program terminat" << endl;
    return 0;
}
