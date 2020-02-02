#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define MAX 1000000007
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if(n==1)
        {
            if(m==0)cout<<"0\n";
            else if(m==1)cout<<"1\n";
            else cout<<"-1\n";
            continue;
        }
        if(n==2){
            if(m==1){cout<<"1\n";}
            else if(m>0&&m<=3){cout<<"2\n";}
            else cout<<"-1\n";
            continue;
        }
        ll num = (n * (n + 1)) / 2;
        if (m > num || m < n - 1)
        {
            cout << "-1"
                 << "\n";
                 continue;
        }
        if(m<=n+1)
        {
            cout<<"2\n";continue;
        }
        ll d;
        if (m > n)
        {
            d = 3;
            m -= 2 * n;
            if(m<0)cout<<d<<"\n";
            else
            {
                ll f = n;
                ll u = m/f;
                d+=u*2;
                ll o = m%f;
                if(o==0)cout<<d<<"\n";
                else if(o>0&&o<=n/2)cout<<d+1<<"\n";
                else cout<<d+2<<"\n";
            }
        }
    }
}
