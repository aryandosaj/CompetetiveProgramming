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
struct dt
{
    ll f;
    char c;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    vll v;
    v.push_back(2);
    v.push_back(1);
    map<ll, ll> mp;
    mp[2] = 1;
    mp[1] = 1;
    for (ll i = 2; i < 100000; i++)
    {
        ll temp = v[i - 1] + v[i - 2];
        if (temp > 100001)
            break;
        v.push_back(temp);
        mp[temp] = 1;
    }

    while (t--)
    {
        map<char, ll> mp2;
        map<char, ll> mp3;
        string s;
        cin >> s;
        vector<dt> vv;
        ll flag = 0;
        for (ll i = 0; i < s.length(); i++)
        {
            mp2[s[i]]++;
        }
        for (auto i : mp2)
        {
            mp3[i.second] = i.first;
            dt temp;
            temp.c = i.first;
            temp.f = i.second;
            vv.push_back(temp);
        }
        // for (ll i = 2; i < vv.size(); i++)
        // {
        //     if ((vv[i - 2].f + vv[i - 1].f) == vv[i].f)
        //     {
        //         if (vv[i - 2].f != vv[i - 1].f)
        //         {
        //             if ((mp[vv[i - 2].f] == 1) && (mp[vv[i - 1].f] == 1) && (mp[vv[i].f] == 1))
        //             {
        //                 flag = 1;
        //                 break;
        //             }
        //         }
        //     }
        // }
        for (ll i = 0; i < vv.size(); i++)
        {
            for (ll j = i + 1; i < vv.size(); i++)
            {

                for (ll k = j + 1; k < vv.size(); k++)
                {
                    if ((vv[i].f + vv[j].f) == vv[k].f)
                    {
                        if (vv[i].f != vv[j].f)
                        {
                            if ((mp[vv[i].f] == 1) && (mp[vv[j].f] == 1) && (mp[vv[k].f] == 1))
                            {
                                flag = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // for (char i = 'a'; i <='z'; i++)
        // {
        //     auto p = mp.find(mp2[i]);
        //     if(p==mp.end())
        //     continue;
        //     ll a = *(++p);
        //     ll b = *(++p);
        //     cout<<a<<" "<<b;
        // }

        if (flag == 0)
            cout << "UNFIT\n";
        else
            cout << "FIT\n";
    }
}