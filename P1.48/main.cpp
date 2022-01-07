#include <iostream>

using namespace std;

int main(){
    int z, an,n,y;
    string sapt[]={"duminica","luni","marti","miercuri","joi","vineri","sambata"};
    cout<<"da ziua da 1 ianuarie din 1994:";
    cin >>z;
    cout<<"da anul";
    cin >>an;
    n=0;
    for(int a=1994;a<an;a++){
       n+=365;
       if(a%4==0) n++;
    }
    n++;
    cout<<endl<<n<<endl;
    y=(z+(n-1))%7;          //se scade (n-1)din nr de ordine al zilei din an
                            //unde n este nr de ordine al zilei de 1 ian din cadrul saptamanii
    cout<<y<<endl;
    cout<<sapt[y];
    return 0;
}
