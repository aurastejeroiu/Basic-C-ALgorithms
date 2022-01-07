#include <iostream>

using namespace std;


long Produs(long x, long y, int b){
   long xx;
   long p1=1;
   long put10=1;
   long p=1;
   long UCy, UCx, T;
   while(y>0){
     UCy=y%10;
     put10=p1;
     T=0;
     xx=x;
     while(xx>0){
        UCx=xx%10;
        long prod=UCy*UCx+T;
        p=p*(prod%b)*put10;
        T=prod/b;
        put10*=10;
        xx/=10;
     }
     y/=10;
     p1*=10;
   }
   if(T>0) p=p+p1*T;
  return p;
}

int main()
{
    cout <<Produs(542,6,8) << endl;
    return 0;
}
