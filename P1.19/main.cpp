#include <iostream>

using namespace std;


int main()
{   long s,i,k,a[8],SMon=0;
    cout<<"da suma:";
    cin >>s;
    a[1]=1;a[2]=3;a[3]=5;a[4]=10;a[5]=20;a[6]=50;a[7]=100;
    for(i=7;i>=1;i--)
       if(s>=a[i]){k=s/a[i];
                   SMon+=k;
                   s=s%a[i];
                   cout<<k<<'x'<<a[i]<<'\n';
                  }
    cout<<endl<<SMon<<" monezi in total"<<endl;
    return 0;
}
