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
map<point, int> a;
map<point, int> danger;
point r;
ll dist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll orientation(point p, point a, point b)
{
    point v1 = {a.x - p.x, a.y - p.y};
    point v2 = {b.x - p.x, b.y - p.y};
    point v1_rotated = {-v1.y, v1.x};
    ll dot = v2.x * v1_rotated.x + v2.y * v1_rotated.y;
    if (dot == 0)
        return 0;
    if (dot < 0)
        return -1;
    return 1;
}
point nextToTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
bool compare(point a, point b)
{
    ll dot = orientation(r, a, b);
    if (dot == 0)
    {
        if (dist(r, a) > dist(r, b))
            return 1;
        return 0;
    }
    else if (dot > 0)
        return 1;
    else
        return 0;
}

void solve(vector<point> nz, vector<point> sv)
{
    vector<point> v;
    sort(nz.begin(), nz.end());
    r = nz[0];
    sort(next(nz.begin()), nz.end(), compare);
    v.push_back(nz[0]);
    for (int i = 1; i < nz.size(); i++)
    {
        v.push_back(nz[i]);
        ll j = i + 1;
        while (j < nz.size() && orientation(r, nz[i], nz[j]) == 0)
            j++;
        i = j - 1;
    }

    if (v.size() < 3)
    {
        return;
    }
    stack<point> st;
    st.push(v[0]);
    st.push(v[1]);
    st.push(v[2]);
    point last = v[1];
    for (int i = 3; i < v.size(); i++)
    {
        while (orientation(nextToTop(st), st.top(), v[i]) <= 0)
            st.pop();
        st.push(v[i]);
    }
    v.clear();
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    if (v.size() < 3)
    {
        return;
    }
    v.push_back(v[0]);
    map<point,int>aa;
    ll count=0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < sv.size(); j++)
        {

            if (orientation(v[i], v[i + 1], sv[j]) < 0)
            {
                aa[sv[j]] = 1;
                count++;
                // cout<<sovi[j].x<<" "<<sovi[j].y<<"\n";
            }
        }
    }
    if(v.size()==5)
    {
         for (int j = 0; j < sv.size(); j++)
        {

            if(aa[sv[j]]==0)
            {
                danger[sv[j]]=1;
            }
        }
        
    }
}
bool ptchek(vector<point> pp, vector<point> v)
{
    ll c = v.size();
    v.push_back(v[0]);
    map<point, int> vis;
    for (auto i : v)
        vis[i] = 1;

    for (int i = 0; i < pp.size(); i++)
    {
        for (int j = 0; j < v.size()-1; j++)
        {

            if (vis[pp[i]] == 0 && orientation(v[j], v[j + 1], pp[i]) == 0)
            {
                c++;
            }
        }
    }
    if (c == pp.size())
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
    point nazi[1003];
    point sovi[1003];
    vector<point> nzpoint;
    vector<point> svpoint;
    vector<point> v;
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nazi[i].x >> nazi[i].y;
        nzpoint.push_back(nazi[i]);
    }
    ll s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> sovi[i].x >> sovi[i].y;
        svpoint.push_back(sovi[i]);
    }
    sort(nazi, nazi + n);
    r = nazi[0];
    sort(nazi + 1, nazi + n, compare);
    v.push_back(nazi[0]);
    for (int i = 1; i < n; i++)
    {
        v.push_back(nazi[i]);
        ll j = i + 1;
        while (j < n && orientation(r, nazi[i], nazi[j]) == 0)
            j++;
        i = j - 1;
    }

    if (v.size() < 3)
    {
        cout << "0";
        return 0;
    }
    stack<point> st;
    st.push(v[0]);
    st.push(v[1]);
    st.push(v[2]);
    point last = v[1];

    for (int i = 3; i < v.size(); i++)
    {
        while (orientation(nextToTop(st), st.top(), v[i]) <= 0)
            st.pop();
        st.push(v[i]);
    }
    v.clear();
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    ll f = ptchek(nzpoint, v);
    if (v.size() == 3 && f == 0)
    {
        vector<point> nztemp;
        for (auto j : v)
        {
            nztemp.clear();
            for (int i = 0; i < n; i++)
            {
                if (nazi[i] != j)
                    nztemp.push_back(nazi[i]);
            }
            solve(nztemp, svpoint);
        }
        ll ans = 0;
        for (int i = 0; i < s; i++)
        {
            ans += danger[sovi[i]];
        }
        cout <<ans;
        return 0;
    }

    ll ans = 0;
    v.push_back(v[0]);
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < s; j++)
        {

            if (orientation(v[i], v[i + 1], sovi[j]) < 0)
            {
                a[sovi[j]] = 1;
            }
        }
    }
    for (int i = 0; i < s; i++)
        ans += a[sovi[i]];
    cout << s - ans;
}