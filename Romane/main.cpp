#include <iostream>
#include <string>
using namespace std;

int main()
{   int n;
    string uni[10] ={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string zeci[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string sute[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string mii[4]  ={"","M","MM","MMM"};
    cout<<"da numarul arab:";cin>>n;
    cout<<mii[n/1000]<<sute[(n/100)%10]<<zeci[(n/10)%10]<<uni[n%10];
    return 0;
}
