#include <iostream>

using namespace std;

void DetData(int n, int a)
{ int vect[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  int i=1;
  if(a%4==0) vect[2]=29;
  while(n>vect[i])
  {  n-=vect[i];
     i++;
  }
  cout<<n<<"."<<i<<"."<<a;

}
int main()
{   int n,a;
    cout<<"da nr de ordina al zilei:";cin>>n;
    cout<<"da anul:";cin>>a;
    DetData(n,a);
    cout<<endl<< "Program terminat" << endl;
    return 0;
}
