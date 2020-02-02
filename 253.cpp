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
#define point pair<ll, ll>
#define x first
#define y second
point pol[100005];
point mis[100005];
point r;
ll dist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll orientation(point a, point b, point o)
{
    point v1 = {a.x - o.x, a.y - o.y};
    point v2 = {b.x - o.x, b.y - o.y};
    point v1_rotated = {-v1.y, v1.x};
    ll dd = v1_rotated.x * v2.x + v1_rotated.y * v2.y;
    if (dd == 0)
        return 0;
    if (dd > 0)
        return 1; //anti-clockwise
    return -1;    //clockwise;
}
bool compare(point a, point b)
{
    ll dot = orientation(a, b, r);
    if (dot > 0)
        return 1;
    else
        return 0;
}

bool in_triangle(point a, point b, point c, point p)
{
    if (orientation(a, p, c) < 0)
        return 0;
    if (orientation(b, p, a) < 0)
        return 0;
    if (orientation(c, p, b) < 0)
        return 0;
    return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    r = {MAX, MAX};
    ll m_i = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> pol[i].x >> pol[i].y;
        if (pol[i].x < r.x)
            r = pol[i], m_i = i;
        else if (pol[i].x == r.x && pol[i].y < r.y)
            r = pol[i], m_i = i;
    }

    for (int i = 0; i < m; i++)
        cin >> mis[i].x >> mis[i].y;
    swap(pol[0], pol[m_i]);
    sort(pol + 1, pol + n, compare);

    for (int i = 0; i < m; i++)
    {
        ll low = 1, high = n - 1, mid, ind = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (orientation(pol[mid], mis[i], pol[0]) >= 0)
                ind = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        // cout << ind << "\n";
        if (ind == -1)
            continue;
        if (ind == n - 1 && orientation(pol[ind], mis[i], pol[0]) > 0)
            continue;
        if (ind == n - 1)
        {
            if(in_triangle(pol[0], pol[n-2], pol[n-1], mis[i]))
                k--;
            continue;
        }
        if (in_triangle(pol[0], pol[ind], pol[ind + 1], mis[i]))
            k--;
    }
    if (k <= 0)
        cout << "YES";
    else
        cout << "NO";
}