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
    ll t;
    cin >> t;
    while (t--)
    {
        unordered_map<char, pair<ll, ll>> start;
        unordered_map<char, pair<ll, ll>> end;
        unordered_map<char, ll> vis;
        unordered_map<char, ll> evis;
        ll n, m, f = 0, num = 0;
        cin >> n >> m;
        string s[n];
        for (ll i = 0; i < n; i++)
            cin >> s[i];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (s[i][j] != '.')
                {
                    num = max(num, s[i][j] - 'a' + 1ll);
                    if (vis[s[i][j]] == 0)
                    {
                        start[s[i][j]].first = i;
                        start[s[i][j]].second = j;
                        end[s[i][j]].first = i;
                        end[s[i][j]].second = j;
                        vis[s[i][j]] = 1;
                    }
                    else
                    {

                        if (!((i == start[s[i][j]].first) || (j == start[s[i][j]].second)))
                        {
                            cout << "NO\n";
                            f = 1;
                            break;
                        }
                        if (evis[s[i][j]])
                        {
                            if (start[s[i][j]].first == end[s[i][j]].first)
                            {
                                if (i != start[s[i][j]].first)
                                {
                                    cout << "NO\n";
                                    f = 1;
                                    break;
                                }
                            }
                            else if (start[s[i][j]].second == end[s[i][j]].second)
                            {
                                if (j != start[s[i][j]].second)
                                {
                                    cout << "NO\n";
                                    f = 1;
                                    break;
                                }
                            }
                        }
                        if (i + j > end[s[i][j]].first + end[s[i][j]].second)
                        {
                            end[s[i][j]].first = i;
                            end[s[i][j]].second = j;
                        }
                        evis[s[i][j]] = 1;
                    }
                }
                
            }
            if (f)
                break;
        }

        if (f)
        {
            continue;
        }
        for (char i = 'a' + num - 2ll; i >= 'a'; i--)
        {
            if (vis[i] == 0)
            {
                start[i] = start[i + 1];
                end[i] = end[i + 1];
            }
        }

        for (char i = 'a'; i < 'a' + num; i++)
        {
            if (start[i].first == end[i].first)
            {
                ll k = start[i].first;
                for (ll j = start[i].second; j <= end[i].second; j++)
                {
                    if ((s[k][j] < i))
                    {
                        cout << "NO\n";
                        f = 1;
                        break;
                    }
                }
            }
            else if (end[i].second == start[i].second)
            {
                ll j = start[i].second;
                for (ll k = start[i].first; k <= end[i].first; k++)
                {
                    if ((s[k][j] < i))
                    {
                        cout << "NO\n";
                        f = 1;
                        break;
                    }
                }
            }
            else
            {
                cout << "NO\n";
                f = 1;
            }
            if (f)
                break;
        }
        if (f)
            continue;
        cout << "YES\n"
             << num << "\n";
        for (char i = 'a'; i < 'a' + num; i++)
        {
            cout << start[i].first + 1 << " " << start[i].second + 1 << " " << end[i].first + 1 << " " << end[i].second + 1 << "\n";
        }
    }
}