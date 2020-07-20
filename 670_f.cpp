#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)

string fun(string s, string ss)
{
    map<char, ll> mp;
    f(0, s.length()) mp[s[i]]++;
    ll len = s.length();
    f(0, ss.length()) mp[ss[i]]--;
    f(1, 7) if (to_string(len - i).length() == i)
    {
        len = i;
        break;
    }
    ll l = s.length();
    l -= len;
    string leng = to_string(l);
    for (auto i : leng)
        mp[i]--;
    char star = ss[0];
    ll flag = 0;
    f(1, ss.length())
    {
        if (ss[i] < star)
        {
            flag = 0;
            break;
        }
        else if (ss[i] > star)
        {
            flag = 1;
            break;
        }
    }
    string n = "";
    ll f = 0;
    map<char, ll> mp1 = mp;
    if (mp['0'] > 0 || star == '0')
    {
        for (char i = '1'; i <= '9' + 1; i++)
        {
            if (star == i)
            {
                f = 1;
                fi(0, ss.length()) n.pb(ss[j]);
                break;
            }
            if (star == '0' || i <= star)
            {
                if (mp[i] > 0)
                {
                    mp[i]--;
                    n.pb(i);
                    break;
                }
            }
            else
            {
                f = 1;
                fi(0, ss.length()) n.pb(ss[j]);
                break;
            }
        }
    }

    for (auto i : mp)
    {
        if (f == 0 && i.first == star)
        {
            if (flag == 0)
            {
                fi(0, ss.length()) n.pb(ss[j]);
                fi(0, i.second) n.pb(i.first);
            }
            else
            {
                fi(0, i.second) n.pb(i.first);
                fi(0, ss.length()) n.pb(ss[j]);
            }
        }
        else
            fi(0, i.second) n.pb(i.first);
    }
    return n;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string ss;
    cin >> s >> ss;
    map<char, ll> mp;
    f(0, s.length()) mp[s[i]]++;
    ll len = s.length();
    f(0, ss.length()) mp[ss[i]]--;
    f(1, 7) if (to_string(len - i).length() == i)
    {
        len = i;
        break;
    }
    ll l = s.length();
    l -= len;
    string leng = to_string(l);
    for (auto i : leng)
        mp[i]--;
    char star = ss[0];
    ll flag = 0;
    f(1, ss.length())
    {
        if (ss[i] < star)
        {
            flag = 0;
            break;
        }
        else if (ss[i] > star)
        {
            flag = 1;
            break;
        }
    }
    string n = "";
    ll f = 0;
    map<char, ll> mp1 = mp;
    if (mp['0'] > 0 || star == '0')
    {
        for (char i = '1'; i <= '9' + 1; i++)
        {
            // if (star == i)
            // {
            //     string temp = "";
            //     if (mp[i])
            //     {
            //         temp.pb(i);
            //         fi(0, ss.length())
            //     }
            // }
            if (star == '0' || i <= star)
            {
                if (mp[i] > 0)
                {
                    mp[i]--;
                    n.pb(i);
                    break;
                }
            }
            else
            {
                f = 1;
                fi(0, ss.length()) n.pb(ss[j]);
                break;
            }
        }
    }

    for (auto i : mp)
    {
        if (f == 0 && i.first == star)
        {
            if (flag == 0)
            {
                fi(0, ss.length()) n.pb(ss[j]);
                fi(0, i.second) n.pb(i.first);
            }
            else
            {
                fi(0, i.second) n.pb(i.first);
                fi(0, ss.length()) n.pb(ss[j]);
            }
        }
        else
            fi(0, i.second) n.pb(i.first);
    }
    string n1 = fun(s, ss);
    if (n.compare(n1) < 0)
        cout << n << "\n";
    else
        cout << n1 << "\n";
}