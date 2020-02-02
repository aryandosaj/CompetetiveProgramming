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
#define quad pair<ll, ll>
#define x first
#define c second
ll n, c;
deque<quad> dq;
ll cost(quad q, ll y)
{
    return (q.x - y) * (q.x - y) + q.c;
}
bool chkdel(quad cur)
{
    quad q1 = dq[dq.size() - 1];
    quad q2 = dq[dq.size() - 2];
    bool f = ((cur.x-q2.x)*((q1.c-q2.c)+q1.x*(q1.x-q2.x))) >= ((q1.x-q2.x)*((cur.c-q2.c)+cur.x*(cur.x-q2.x)));  
    return f;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    ll bp = 0, x;
    cin>>x;
    dq.push_back({x,bp+c});
    for (ll i = 1; i < n; i++)
    {
        cin >> x;
        
        while (dq.size() > 1 && cost(dq[0], x) >= cost(dq[1], x))
            dq.pop_front();
        bp = cost(dq.front(), x);
        quad q = {x, bp + c};
        while (dq.size() >= 2 && chkdel(q))
            dq.pop_back();
        dq.push_back(q);
        
    }
    cout << bp;
}