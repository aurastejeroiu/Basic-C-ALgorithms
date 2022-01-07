#include <iostream>

using namespace std;

///1.1. Fie i,j,k numere naturale. Sa se determine restul impartirii
///     numarului (i^j) la k; deci (i^j)mod k.
///     Idee:
///          - se calculeaza la fiecare pas de inmultire restul;
///          - practic se inmultesc resturile modulo k.

long long Rest(long long i, long long j, long long k){
    if(j>0) return ((i%k)*Rest(i,j-1,k)) % k;       ///recursiv, se autoapeleaza functia cat timp j>0
            return 1;                                   ///la final se inlocuieste cu 1, in sirul de produse.

}

void CitireDate(long long &i, long long &j, long long &k){
    cout    <<"da i:"; cin >>i;
    cout    <<"da j:"; cin >>j;
    cout    <<"da k:"; cin >>k;
}

int main()
{   long long  i,j,k;
    CitireDate (i,j,k);
    cout       << Rest(i,j,k);
    return 0;
}
