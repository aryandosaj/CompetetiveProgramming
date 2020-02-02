#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct dt
{
    ll ind;
    ll a;
    ll b;
    ll diff;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k;
    cin >> n >> k;
    ll a[n];
    ll b[n];
    ll a_tot = 0;
    ll m = 1000000000000;
    dt data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_tot += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        m = min(b[i] / a[i], m);
        data[i].ind = i;
        data[i].a = a[i];
        data[i].b = b[i];
        data[i].diff = b[i] - a[i];
    }
    if (m != 0)
    {
        for (int i = 0; i < n; i++)
        {
            b[i] -= m * a[i];
        }
    }
    ll req[n];
    ll total = 0;
    while (k > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] > 0)
            {
                req[i] = a[i] - b[i];
                b[i] = 0;
            }   
            else
            {
                req[i] = 0;
                b[i] -= a[i];
            }
            total += req[i];
        }
        k-=total;
        if(k>=0)
        m++;
        total=0;
    }
    
    cout << m;
}