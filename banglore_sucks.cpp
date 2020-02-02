#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll t;
    cin>>t;
    while (t--)
    {
        
        ll a, b;
        cin >> a >> b;
        ll s = min(a, b);
        ll l = max(a, b);
        if (l % s == 0)
        {
            cout << s << "\n";
            continue;
        }
        else
        {
            ll alpha = l - s;
            ll beta = s;
            if (beta > alpha)
            {
                cout << alpha << "\n";
                continue;
            }
            else
            {
                ll lambda = alpha / beta+1;
                ll ans = alpha / lambda;
                if(ans!=1)
                cout << ans << "\n";
                else
                cout<<"ML nahi lag payega :D\n";
                continue;
            }
        }
    }
}