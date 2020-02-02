#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
double fun(vector<pair<double,double>>v)
{
    double l = 0, h = INT_MAX, m, tt = 0;

    while (1)
    {
        m = (l + h) / 2;
        double t = 0;
        for (auto i : v)
        {
            t += (m - i.first) / i.second;
        }
        if (t > 0)
        {
            h = m;
        }
        else
        {
            l = m;
        }
        // cout << t<<" "<<m << "\n";
        if (abs(tt - t) > 0.001)
        {
            tt = t;
            continue;
        }
        else
            break;
    }
    return m;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<double, double>> x;
    vector<pair<double, double>> y;
    for (int i = 0; i < n; i++)
    {
        pair<pair<double, double>,double> p;
        cin >> p.first.first >> p.first.second>>p.second;
        x.push_back({p.first.first,p.second});
        y.push_back({p.first.second,p.second});
    }
    double ans_x = fun(x);
    double ans_y = fun(y);
    cout<<ans_x<<" "<<ans_y;
    
}