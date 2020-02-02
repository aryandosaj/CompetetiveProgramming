#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
map<ll, ll> nn;
map<ll, ll> mm;
map<ll, ll> kk;
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
#define MAX 9223372036854775807
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k,n1,m1,k1;
    cin >> n >> m >> k;
    // cout<<MAX;
    n1=n,k1=k,m1=m;
    // if (k >= (n * m))
    // {
    //     cout << "NO";
    //     return 0;
    // }
    if (k == 2)
    {
        cout<<"YES\n";
        cout << "0 0\n";
        cout << n << " 0\n";
        cout << "0 " << m;
        return 0;
    }
    ll flag=0;
    if (k % 2 == 0)
    {
        k /= 2;
        flag=1;
    }
    {
        while (n % 2 == 0)
        {
            nn[2]++;
            n = n / 2;
        }

        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                nn[i]++;
                n = n / i;
            }
        }

        if (n > 2)
            nn[n]++;
    }
    {
        while (m % 2 == 0)
        {
            mm[2]++;
            m =m / 2;
        }

        for (int i = 3; i <= sqrt(m); i = i + 2)
        {
            while (m % i == 0)
            {
                mm[i]++;
                m = m / i;
            }
        }

        if (m > 2)
            mm[m]++;
    }
    {
        while (k % 2 == 0)
        {
            kk[2]++;
            k =k / 2;
        }

        for (int i = 3; i <= sqrt(k); i = i + 2)
        {
            while (k % i == 0)
            {
                kk[i]++;
                k = k / i;
            }
        }

        if (k > 2)
            kk[k]++;
    }
    ll nf=1,mf=1;
    for(auto i:kk)
    {
        if(i.second>(mm[i.first]+nn[i.first]))
        {cout<<"NO";return 0;}
        else
        {
            if(mm[i.first]>i.second)
            mf*=power(i.first,i.second,MAX);
            else
            {mf*=power(i.first,mm[i.first],MAX);nf*=power(i.first,i.second-mm[i.first],MAX);}
        }
    }
    if(flag==0)
    {
        if(nf>=2) n1*=2;
        else m1*=2;
    }
    cout<<"YES\n";
    cout << "0 0\n";
    cout << n1/nf << " 0\n";
    cout << "0 " << m1/mf;
}
