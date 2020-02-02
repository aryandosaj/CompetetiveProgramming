#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int C[100005];
    int A[100005];
    int B[100005];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        cin >> C[i], A[i] = A[i] ^ B[i];
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        int d = 0;
        for (int j = 0; j < 31; j++)
        {
            if ((A[i] & (1 << j)) == 0)
            {
                if ((1 << j) & C[i])
                {
                    d = d | (1 << j);
                }
            }
        }
        if (d != 0)
            s += A[i] ^ d;
        else
        {
            for (int j = 0; j < 31; j++)
            {

                if ((1 << j) & C[i])
                {
                    d = d | (1 << j);
                    break;
                }
            }
            s += A[i] ^ d;
        }
    }
    cout << s;
}