#include <iostream>
#include <cstring>
using namespace std;


int main()
{   int n,y,z;
    string sapt[]={"duminica","luni","marti","miercuri","joi","vineri","sambata"};
    cout<<"da pozitia in saptamana a zilei de 1 ianuarie:";
    cin >>z;
    cout<<"da numar de zile:";
    cin >>n;
    cout<<endl<<n<<endl;
    ///cout<<z+n<<endl;
    y=(z-1+n)%7;          //se aduna la z-1, nr de ordine al zilei din an
                          //unde n este nr de ordine al zilei de 1 ian din cadrul saptamanii
    cout<<y<<endl;
    cout<<sapt[y];
    return 0;
}
