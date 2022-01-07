#include <iostream>

using namespace std;

int main()
{ int cont=0;
  for(int x=-4;x<=4;x++)
    for(int y=-16;y<=16;y++)
      if(y<=x*x && y>=(2*x*x-16) )
        cout<<++cont<<". "<<x<<" "<<y<<endl;

    cout << "Program terminat" << endl;
    return 0;
}
