#include <iostream>

using namespace std;


void gama (int n){
  if(n>=3){
    for(int i=3;i<=n;i++)
        cout<<n<<" ";
    gama(n-3);
  }
}

int main()
{   gama(6);
    cout << "Hello world!" << endl;
    return 0;
}
