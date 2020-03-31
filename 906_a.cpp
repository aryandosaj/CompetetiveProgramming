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
    map<ll, ll> mp;
    ll flag = 0;
    bool unique = false;
    ll sum = 0;
    fr(0, n)
    {
        string first, second;
        cin >> first >> second;
        if (first == "!")
        {
            if (unique)
            {
                sum++;
                continue;
            }

            if (flag == 0)
            {
                frj(0, second.size())
                {
                    mp[second[j] - 'a'] = (ll)1;
                    // cout<<second[j]<<" ";
                }
                // cout<<mp.size()<<"\n";
                flag = 1;
            }
            else
            {
                map<ll, ll> check;
                vector<ll> v;
                frj(0, second.size())
                {
                    check[second[j] - 'a'] = (ll)1;
                    // cout<<second[j]<<" ";
                }
                // cout<<mp['h'-'a']<<"aa\n";
                for (auto ii = mp.begin(); ii != mp.end(); ii++)
                {
                    if (check[ii->first] == (ll)0)
                    {
                        v.push_back(ii->first);
                        cout<<ii->first<<"\n";
                        // cout<<char(ii->first+'a')<<"\n";
                    }
                }

                frj(0, v.size())
                {
                    cout << char(v[j] + 'a') << "\n";
                    mp.erase(v[i]);
                }
                // cout<<mp.size()<<"\n";
            }
        }
        else if (first == ".")
        {
            map<ll, ll> check;
            vector<ll> v;
            frj(0, second.size())
            {
                // check[second[j]-'a']=(ll)1;
                mp.erase((second[j] - 'a'));
                // cout<<second[j]<<"\n";
            }

            for(auto ii=mp.begin();ii!=mp.end();ii++)
            {
                if(check[ii->first]==(ll)1)
                {
                    v.push_back(ii->first);
                }
            }
            frj(0,v.size())
            {
                mp.erase(v[i]);
            }
            cout<<i<<" "<<mp.size()<<"\n";
        }
        else if (first == "?")
        {
            if (unique && i != (n - 1))
            {
                sum++;
                continue;
            }
            ll pos = second.at(0) - 'a';
            mp.erase(pos);
        }

        if (mp.size() == 1)
        {
            unique = true;
        }
    }
    cout << sum << "\n";
    return 0;
}