#include <iostream>

using namespace std;

int a=5;

int main()
{   int a=10;
    cout <<  a << endl;      //afiseaza valoarea variabilei locale
    cout <<::a << endl;  //afiseaza val variabilei globale
    return 0;
}
