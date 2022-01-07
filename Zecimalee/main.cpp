#include <iostream>

using namespace std;

int main()
{   long m,n,k,i;
    cout<<"da k:"; cin>>k;
    cout<<"da m:"; cin>>m;
    cout<<"da nr de zecimale:"; cin>>n;
    cout<<"0.";
    i=1;
    while(i<=n){
        long Cat=k*10/m;
        cout <<Cat;
        k=k*10-Cat*m;
        i++;
    }
    cout << "Hello world!" << endl;
    return 0;
}
