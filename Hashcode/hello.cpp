#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b = 5;
    int *a = &b;
    int **z = &a;
    int *y = (&b);
    int *x = *(&y);
    cout << *x << "\n";`
}