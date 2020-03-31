#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr(a, b) for (ll i = a; i < b; i++)
#define frj(a, b) for (ll j = a; j < b; j++)

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
    string s;
    cin >> s;
    map<ll, vector<ll>> mp;
    bool arr[n];
    ll sum = 0;
    fr(0, n)
    {
        mp[s.at(i) - 'a'].push_back(i);
        arr[i] = true;
    }
    for (ll z = 0; z < n; z++)
    {
        for (ll i = 25; i > 0; i--)
        {
            frj(0, mp[i].size())
            {
                ll pos = mp[i][j];
                if (arr[pos] == false)
                    continue;
                ll flag = 0;
                for (ll k = pos - 1; k >= 0; k--)
                {
                    if (arr[k] == true)
                    {
                        if ((int)((int)s.at(pos) - (int)s.at(k)) == 1)
                            flag = 1;
                        break;
                    }
                }
                for (ll k = pos + 1; k < n; k++)
                {
                    if (arr[k] == true)
                    {
                        if ((int)((int)s.at(pos) - (int)s.at(k)) == 1)
                            flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    arr[pos] = false,
                    sum++;
            }
        }
    }
    cout << sum << "\n";
    return 0;
}