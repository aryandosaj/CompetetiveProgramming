//Convex Hull--------------
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define MAX 1000000007
#define point pair<ll, ll>
#define x first
#define y second
point arr[105];
point r;
ll dist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll orientation(point p, point a, point b) //1 for anticlockwise -1 for clockwise 0 for colinear
{
    point v1 = {a.x - p.x, a.y - p.y};
    point v2 = {b.x - p.x, b.y - p.y};
    point v1_rotated = {-v1.y, v1.x};
    ll dot = v2.x * v1_rotated.x + v2.y * v1_rotated.y;
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
int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + n);
    r = arr[0];
    sort(arr + 1, arr + n, compare);
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
        cout << "-1\n";
        return 0;
    }
    // Calculating Hull Here
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
    
}
