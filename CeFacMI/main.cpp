#include <iostream>

using namespace std;

long CeFace(long n, long p){
  if(n>0) {
      if((n%10)%3==0) return CeFace(n/10,p*10) + (9-n%10)*p;
      else            return CeFace(n/10,p);
  }
  else                return 0;
}

long CeFaceA(long n, long z, long p){
  if(n>0) {
      if((n%10)%3==0) return CeFaceA(n/10, z+(9-n%10)*p, p*10);
      else            return CeFaceA(n/10,z,p);
  }
  else                return z;
}




int main()

{   cout<<CeFace(12345,10)<<endl;
    cout<<CeFace(123456,10)<<endl;
    cout<<CeFace(1234567,10)<<endl;
    cout<<CeFace(123456789,10)<<endl;

    //cout<<CeFaceA(12345,1,10)<<endl;
    //cout<<CeFaceA(123456,2,10)<<endl;;
    //cout<<CeFaceA(1234567,3,10)<<endl;;
    //cout<<CeFaceA(123456789,4,10)<<endl;;
    //cout<<endl<<CeFaceA(123453,5,1);
    cout << "Hello world!" << endl;
    return 0;
}
