#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define N 200005
ll ans[N];
ll nck[N];
ll phi[N];
vll fac[N];
ll nck1[N];
ll fans[N];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q, k;
    cin >> q >> k;
    nck1[k] = 1;
    for (int i = k + 1; i < N; i++)
    {
        nck1[i] = (((nck1[i - 1] * (i)) % MAX) * power((i - k), MAX - 2, MAX)) % MAX;
    }
    k--;
    nck[k] = 1;
    for (int i = 1; i < N; i++)
        phi[i] = i;
    for (int i = k + 1; i < N; i++)
    {
        nck[i] = (((nck[i - 1] * (i)) % MAX) * power((i - k), MAX - 2, MAX)) % MAX;
    }
    for (ll i = 2; i < N; i++)
        fac[i].push_back(1);
    for (ll i = 2; i < N; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            for (ll j = 2 * i; j < N; j += i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
                fac[j].push_back(i);
            }
        }
        else
        {
            for (ll j = 2 * i; j < N; j += i)
            {
                fac[j].push_back(i);
            }
        }
    }
   
    for (ll i = 2; i < N; i++)
    {
        for (auto j : fac[i])
        {
            ll n1 = (i-1)/j;
            ll n2 = phi[i/j];
            ll n3 = n1-n2;
            ans[i] = (ans[i] + j*(nck[n1]-nck[n3]+MAX)%MAX)%MAX;
            fans[i] = (fans[i] + (nck[n1]-nck[n3]+MAX)%MAX)%MAX;
            if(i==6)
            {
                cout<<j<<" "<<n1<<" "<<n2<<" "<<n3<<" "<<(j*(nck[n1]-nck[n3]+MAX))%MAX<<"\n";
            }
        }
    }
    for (ll i = 2; i < N; i++)
        ans[i] = (ans[i] + ans[i - 1]) % MAX,fans[i] = (fans[i]+fans[i-1])%MAX;
    ll n;
    while (q--)
    {
        cin >> n;
        ll t = nck1[n];
        // ans[n] = (ans[n] +MAX)%MAX;
        // cout<<ans[n]<<"\n";
        // cout << (ans[n] + t - fans[n] +MAX)%MAX<< "\n";
        cout<<(ans[n]*power(t,MAX-2,MAX))%MAX<<"\n";
    }
}