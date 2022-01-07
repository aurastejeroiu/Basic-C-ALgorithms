#include <iostream>

using namespace std;

long C (long n);
long Cmin(long n);

int main()
{
    int n;

    cin >> n;

    cout << C(n) << '\n';
    cout << Cmin(n);

    return 0;
}

long C (long n)
{
    cout << n << endl;

    if (n < 10)
        return n;

    if ((n % 10) < ((n / 10) % 10))
        return C((n / 100) * 10 + n % 10);

    return C(n / 10);
}

long Cmin(long n)
{
    long U, M;

    if (n < 10)
        return n;

    U = n % 10;
    M = Cmin(n / 10);

    if (U < M)
        return U;
    return M;
}

