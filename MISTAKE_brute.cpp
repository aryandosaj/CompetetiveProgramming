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
    int n, t;
    cin >> n>>t;
    int arr[n];
    int brr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i], brr[i] = arr[i];
    sort(brr, brr + n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(arr[i] - brr[i]);
    while (next_permutation(brr, brr + n))
    {
        int temp = abs(arr[0]-brr[0]);
        int f = 0;
        for (int i = 1; i < n; i++)
        {
            if (abs(brr[i] - brr[i - 1]) > t)
            {   
                f = 1;
                break;
            }
            temp += abs(arr[i] - brr[i]);
        }
        if (f == 0)
            sum = min(sum, temp);
    }
    cout << sum;
}