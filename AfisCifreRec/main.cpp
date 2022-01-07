#include <iostream>
using namespace std;

void AfisR1(long n){
   if(n>0){
       AfisR1(n/10);
       cout<<n%10<<" ";
   }
}

void AfisR2(long n){
   if(n>0){
       cout<<n%10<<" ";
       AfisR2(n/10);
   }
}

int main()
{   AfisR1(12345);
    cout<<endl;
    AfisR2(12345);
    cout << "Program terminat" << endl;
    return 0;
}
