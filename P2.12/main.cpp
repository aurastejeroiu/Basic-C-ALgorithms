#include <iostream>

using namespace std;

struct Y{
  int y;
  int fr;
};


void CreY(int n, int x[], int& m, int Y[100])
{for(int i=1;i<=n;i++)
      { int poz=ExistaInY(m,Y,x[i]);            //retur 0 sau pozitia
        if(poz==0) AdaugInY(m,Y,x[i])           //frecventa se pune pe 1
        else       Mareste Frecv(m,Y,poz);      //Y[poz].frecv++;
      }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
