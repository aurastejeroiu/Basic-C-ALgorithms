#include <iostream>

using namespace std;

///1.1. Fie i,j,k numere naturale, nenule. Sa se determine restul impartirii
///     numarului (i^j) la k; deci (i^j)mod k.
///     Idee:
///          - se calculeaza la fiecare pas de inmultire restul produsului;
///          - practic se inmultesc resturile modulo k.

long long CalcRest(long long i, long long j, long long k){///long long e facilitate a Code::Blocks
    long long iModuloK=i%k;
    long long R=1;
    while (j--)
        R=(R*iModuloK)%k;   ///atat lui i cat si produsului  se aplica %
    return R;
}

void CitireDate(long long &i, long long &j, long long &k){
    cout    <<"da i:"; cin >>i;
    cout    <<"da j:"; cin >>j;
    cout    <<"da k:"; cin >>k;
}

void AfisRest(long long i, long long j, long long k, long long Rest){
    cout   << "restul lui ("<< i << " la " <<j << ")%" << k << " =" << Rest;
}

int main()
{   long long   i,j,k,R;
    CitireDate  (i,j,k);
    R		    =CalcRest(i,j,k);
    AfisRest    (i,j,k,R);
    return 0;
}
