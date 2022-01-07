#include <iostream>

using namespace std;

int main()
{ int a,b,c,d;
  cout<<"citim coltu stanga jos"<<endl;
  cout<<"da abscisa:"; cin>>a;
  cout<<"da ordonata:";cin>>b;
  cout<<"citim coltu dreapta sus"<<endl;
  cout<<"da abscisa:"; cin>>c;
  cout<<"da ordonata:";cin>>d;
  for(int x=a;x<=c;x++)
    for(int y=b;y<=d;y++)
      cout<<"("<<x<<","<<y<<")"<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
