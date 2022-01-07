#include <iostream>

using namespace std;

int CMMDC(int n, int k){
  int rest;
  int cont=0;
  do{
    rest=n%k;
    n   =k;
    k   =rest;
    cont++;
  }
  while(rest);
  cout <<"ciclari: "<<cont<<endl;
  return n;
}

void Reclame1(int n, int k, int &Nr){
    Nr= n-n/CMMDC(n,k);
}


int main()
{   int     n,k,Nr;
    cout    <<"da n:";
    cin     >>n;
    cout    <<"da k:";
    cin     >>k;
    Reclame1(n,k,Nr);
    cout    <<"nu primesc: "<<Nr<<" copii"<<endl;
    cout    << "Program terminated" << endl;
    return 0;
}
