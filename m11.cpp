#include <bits/stdc++.h>
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define show(x) cout << (#x) << " : " << x << endl;
#define ll long long
#define ld long double
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define ff first
#define ss second
#define pii pair<ll, ll>
#define sq(x) ((x) * (x))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const ll MOD = 1000 * 1000 * 1000 + 7;
using namespace std;

long long factorial(ll n)
{

    long long f = 1;

    for (int i = 1; i <= n; i++)
        f = (f * i) % MOD;

    return f;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long int x1, y1;
    long long int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
long long int mi(long long int a, long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(a, m, &x, &y);
    long long int res = (x % m + m) % m;
    return res;
}
ll A[200005];
ll facts[200011];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio();
    int T;
    cin >> T;
    facts[0] = 1LL;
    for (ll i = 1; i <= 200000; i++)
        facts[i] = (facts[i - 1] * i) % MOD;
    while (T--)
    {
        ll N;
        cin >> N;
        ll S = 0;
        ll f1 = 1;
        map<ll, ll> last;
        ll O = 0;
        ll P = 0;
        A[0] = 0;
        A[1] = 0;
        ll ans = facts[N - 1];
        for (ll i = 0; i < 2 * N + 2; i++)
        {
            if (i > 1)
            {
                cin >> A[i];
                S += A[i];
            }
            last[A[i]]++; // taking count of all numbers
        }
        ll temp = S;
        last[0] = last[0] - 2;
        if (S % (N + 1) != 0)
        {
            cout << "0\n";
            continue;

        } // removing 2 added zeroes
        S = S / (N + 1);
        sort(A, A + 2 * N + 2);
        for (int i = 0; i < 2 * (N + 1); i++)
            if (A[i] + A[2 * N + 1 - i] != S) // checking if pair sums valid or not
                ans = 0;
        if(ans==0)
        {
            cout<<ans<<"\n";
            continue;
        }
        S = temp;
        if (S % (N + 1) == 0) // checking if the total is valid or not
        {
            if (N == 1)
            {
                if (A[2] == A[3])
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
            }
            else
            {
                S = S / (N + 1);
                for (auto x : last)
                {
                    if (x.ff != S - x.ff)
                    {
                        ans = (ans * (power(2, x.ss, MOD))) % MOD; // computing powers of 2 for pairs
                        O = mi(facts[x.ss], MOD);
                        ans = (ans * O) % MOD; // dividing by the factorial of the pair
                        last.erase(S - x.ff);  //removing the other number as computation is needed only once per pair
                    }
                    else
                    {
                        P = mi(facts[x.ss / 2], MOD); // for pair where number = total/2
                        ans = (ans * P) % MOD;
                    }
                }
                cout << ans << '\n';
            }
        }
        else
            cout << 0 << '\n';
    }
    return 0;
}