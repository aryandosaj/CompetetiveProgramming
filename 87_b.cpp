#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    unordered_map<string, ll> mp;
    unordered_map<string, ll> vis;
    vis["void"] = 1;
    while (n--)
    {
        string s;
        cin >> s;
        if (s.compare("typedef") == 0)
        {
            string s1, var;
            cin >> s1 >> var;
            string t = "";
            ll a = 0, b = 0;
            for (ll i = 0; i < s1.length(); i++)
                if (s1[i] == '&')
                    a++;
                else if (s1[i] == '*')
                    b++;
                else
                    t.push_back(s1[i]);
            if (vis[t] == 1)
            {
                vis[var] = 1;
                mp[var] = mp[t] + b;
                mp[var] -= a;
                if (mp[var] < 0)
                    mp[var] = -MAX, vis[var] = 0;
            }
            else
            {
                vis[var]=0;mp[var]=0;
            }
            
        }
        else
        {
            string var;
            cin >> var;
            string t = "";
            ll a = 0, b = 0;
            for (ll i = 0; i < var.length(); i++)
                if (var[i] == '&')
                    a++;
                else if (var[i] == '*')
                    b++;
                else
                    t.push_back(var[i]);
            if (vis[t] == 0)
            {
                cout << "errtype\n";
                continue;
            }
            ll temp = mp[t];
            temp += b - a;
            if (temp < 0)
                cout << "errtype\n";
            else
            {
                cout << "void";
                for (ll i = 0; i < temp; i++)
                    cout << '*';
                cout << "\n";
            }
        }
    }
}