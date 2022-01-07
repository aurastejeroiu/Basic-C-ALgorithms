
#include <iostream>

using namespace std;
///solutiile intregi ale sistemului y<=x*x si y>= 2*x*x-16
int main()
{   int x,y,Cont=0;
    for(x=-4;x<=4;x++)
        for(y=-16;y<=16;y++)
          if((y<=x*x)&&(y>=(2*x*x-16)))
             { Cont++;
               cout<<Cont<<"."<<"("<<x<<" "<<y<<")"<<endl;
             }
    cout << "Program terminated" << endl;
    return 0;
}
