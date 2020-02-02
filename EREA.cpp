#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define deb(x) cout << #x << "  " << x << endl;
#define point pair<double, double>
#define x first
#define y second
point r;

//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

//Convex arr--------------

double dist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll orientation(point p, point a, point b) //1 for anticlockwise -1 for clockwise 0 for colinear
{
    point v1 = {a.x - p.x, a.y - p.y};
    point v2 = {b.x - p.x, b.y - p.y};
    point v1_rotated = {-v1.y, v1.x};
    double dot = v2.x * v1_rotated.x + v2.y * v1_rotated.y;
    if (dot == 0)
        return 0;
    if (dot > 0)
        return 1;
    else
        return -1;
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
        if (dist(a, r) > dist(b, r))
            return 1;
        return 0;
    }
    if (dot > 0)
        return 1;
    else
        return 0;
}
vector<point> ch(vector<point> arr)
{
    ll n = arr.size();
    sort(arr.begin(), arr.end());
    r = arr[0];
    sort(arr.begin() + 1, arr.end(), compare);
    vector<point> v;
    v.push_back(arr[0]);
    //removing colinear points considering only the farthest point
    for (int i = 1; i < n; i++)
    {
        v.push_back(arr[i]);
        ll j = i + 1;
        while (j < n && orientation(r, arr[i], arr[j]) == 0)
            j++;
        i = j - 1;
        
    }
    if (v.size() < 3)
    {
        return {};
    }
    // Calculating arr Here
    stack<point> st;
    st.push(v[0]);
    st.push(v[1]);
    st.push(v[2]);
    point last2 = v[1];
    for (int i = 3; i < v.size(); i++)
    {
        while (orientation(nextToTop(st), st.top(), v[i]) <= 0)
        {
            st.pop();
        }
        st.push(v[i]);
    }
    v.clear();
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    // sort(v.begin(), v.end());
    return v;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<point> v;
    vector<point> arr;

    f(0, n)
    {
        double a, b;
        cin >> a >> b;
        v.pb({a, b});
        if (i)
        {
            arr.pb({(v[i - 1].x + v[i].x) / 2.0, (v[i - 1].y + v[i].y) / 2.0});
        }
    }
    arr.pb({(v[n - 1].x + v[0].x) / 2.0, (v[n - 1].y + v[0].y) / 2.0});

    double area = 0.0;
    arr = ch(arr);
    ll j = n - 1;
    f(0, n)
    {
        area += (arr[i].x + arr[j].x) * (arr[i].y - arr[j].y);
        j = i;
    }
    
    cout << setprecision(15) << fixed << abs(area / 2.0);
    return 0;
}
