#include <iostream>

using namespace std;

int n=5;
int main()
{   if(n>0) {n=n-1;
             cout<<n<<endl;
             return main();
            }

    cout << "Hello world!" << endl;
    return 0;
}
