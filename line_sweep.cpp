#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000007
#define x second.first
#define y first
typedef pair<long long, pair<long long, long long>> dt;
dt arr[50005];
bool compare(dt a, dt b) { return a.x < b.x; };
int main()
{
    ll n;
    cin >> n;
    
    for (ll i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y, arr[i].second.second = i;
    sort(arr, arr + n, compare);
    set<dt> s;
    double h = MAX*100;
    s.insert(arr[0]);
    ll d = 0;
    ll a = 0;
    ll b = 1;
    for (ll i = 1; i < n; i++)
    {
        while (d < i && arr[d].x < arr[i].x - h)
            s.erase(arr[d++]);                                       //remove polls before x - h
        auto it = s.lower_bound({arr[i].y - h, {arr[i].x - h, -1}}); //initialize it with poll just greater than or equal to [x-h,y-h]
        for (; it != s.end() && (*it).y < h + arr[i].y; it++)
        {
            dt pt = *it;
            double f = sqrt(((arr[i].x - pt.x) * (arr[i].x - pt.x) + (arr[i].y - pt.y) * (arr[i].y - pt.y)));
            if (h > f)
            {
                h = f;
                a = pt.second.second;
                b = arr[i].second.second;
            }
        }
        s.insert(arr[i]);
    }
    if (a > b)
        swap(a, b);
    cout <<fixed<< setprecision(6) << a << " " << b << " " << h;
}