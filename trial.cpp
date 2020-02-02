#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
int main()
{
    int a = 5;
    int &b = a;
    int &c = b;
    a++;
    c++;
    cout << b<<" "<<c;
}