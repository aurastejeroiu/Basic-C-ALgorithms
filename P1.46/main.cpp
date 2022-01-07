#include <iostream>

using namespace std;

void DetData(int n, int a)
{ int luni[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  if(a%4==0) luni[2]=29;
  if(a%400!=0 && a%100==0) luni[2]=28;
  int i=1;
  while(n>luni[i])          ///se scad din n nr de zile ale lunilor, cat timp n>luni[i]
  {  n-=luni[i];
     i++;
  }                         ///n ramas va reprezenta ziua din luna iar i va fi luna obtinuta
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
