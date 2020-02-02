#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        string s;
        cin >> n >> m;
        string grid[n];
        ll row[n];
        ll col[m];

        for (ll i = 0; i < n; i++)
        {
            row[i] = 0;
        }

        for (ll j = 0; j < m; j++)
        {
            col[j] = 0;
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> grid[i];
            for (ll j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        cin >> s;
        ll l = s.size();
        char a = ' ', b = ' ';
        a = s[l - 1];
        for (ll i = l - 1; i >= 0; i--)
        {
            if (a == 'L' || a == 'R')
            {
                if (s[i] == 'U' || s[i] == 'D')
                {
                    b = s[i];
                    break;
                }
            }
            if (a == 'U' || a == 'D')
            {
                if (s[i] == 'L' || s[i] == 'R')
                {
                    b = s[i];
                    break;
                }
            }
        }
        // cout<<a<<" "<<b<<"\n";
        if ((b == 'L') || (b == 'R'))
        {
            if (a != ' ')
            {
                for (ll i = 0; i < m; i++)
                {
                    col[i] = 0;
                    for (ll j = 0; j < n; j++)
                    {
                        if (row[j] >= i + 1)
                        {
                            col[i]++;
                        }
                    }
                }
            }

            

            for (ll i = 0; i < n; i++)
            {

                for (ll j = 0; j < m; j++)
                {
                    if ((a == 'D') && (b == 'L'))
                    {
                        if (col[j] >= (n - i))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    if ((a == 'D') && (b == 'R'))
                    {
                        if (col[m - j - 1] >= (n - i))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    if ((a == 'U') && (b == 'L'))
                    {
                        if (col[j] >= i + 1)
                            cout << '1';
                        else
                            cout << '0';
                    }
                    if ((a == 'U') && (b == 'R'))
                    {
                        if (col[m - j - 1] >= i + 1)
                            cout << '1';
                        else
                            cout << '0';
                    }
                }
                cout << "\n";
            }
        }

        if ((b == 'U') || (b == 'D'))
        {
            if (a != ' ')
            {
                for (ll i = 0; i < n; i++)
                {
                    row[i] = 0;
                    for (ll j = 0; j < m; j++)
                    {
                        if (col[j] >= i + 1)
                        {
                            row[i]++;
                        }
                    }
                }
            }

            for (ll i = 0; i < n; i++)
            {

                for (ll j = 0; j < m; j++)
                {
                    if ((a == 'L') && (b == 'U'))
                    {
                        if (row[i] >= (j + 1))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    if ((a == 'L') && (b == 'D'))
                    {
                        if (row[n - i - 1] >= j + 1)
                            cout << '1';
                        else
                            cout << '0';
                    }
                    if ((a == 'R') && (b == 'U'))
                    {
                        if (row[i] >= m - j)
                            cout << '1';
                        else
                            cout << '0';
                    }
                    if ((a == 'R') && (b == 'D'))
                    {
                        if (row[n - i - 1] >= m - j)
                            cout << '1';
                        else
                            cout << '0';
                    }
                }
                cout << "\n";
            }
        }
        if (b == ' ')
        {
            if ((a == 'L') || (a == 'R'))
            {
                for (ll i = 0; i < n; i++)
                {

                    for (ll j = 0; j < m; j++)
                    {
                        if ((a == 'L'))
                        {
                            if (row[i] >= (j + 1))
                                cout << '1';
                            else
                                cout << '0';
                        }
                        
                        if ((a == 'R'))
                        {
                            if (row[i] >= m - j)
                                cout << '1';
                            else
                                cout << '0';
                        }
                        
                    }
                    cout << "\n";
                }
            }
            else
            {
                for (ll i = 0; i < n; i++)
            {

                for (ll j = 0; j < m; j++)
                {
                    if ((a == 'D'))
                    {
                        if (col[j] >= (n - i))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    
                    if ((a == 'U'))
                    {
                        if (col[j] >= i + 1)
                            cout << '1';
                        else
                            cout << '0';
                    }
                    
                }
                cout << "\n";
            }
            }



        }
    }
}