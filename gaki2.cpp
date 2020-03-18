#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr for (ll i = 0; i < n; i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> mp;
    map<char, int> mpbk;
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        mpbk[s[i]]++;
    }
    fr
    {
        mp[s.at(i)]++;
        mpbk[s.at(i)]--;
        for (ll j = 0; j < 26; j++)
        {
            char ch1 = 'a' + j;
            for (ll k = 0; k < 26; k++)
            {
                char ch2 = 'a' + k;
                ll temp = 0;
                if (ch1 != ch2)
                    temp = mp[ch1] * mpbk[ch2];
                // else
                // {
                //     temp = max((mp[ch1] + mpbk[ch2]), ((mp[ch1] + mpbk[ch2]) * (mp[ch1] + mpbk[ch2] - 1)) / 2);
                // }
                ans = max(ans, temp);
                // cout<<ch1<<" "<<mp[ch1]<<" "<<ch2<<" "<<mpbk[ch2]<<"\n";
            }
        }
    }

    fr
    {
        for (ll j = 0; j < 26; j++)
        {
            char ch1 = 'a' + j;
            ll temp = mp[ch1];
            ll num = 2;
            ans = max(ans,max(temp, (temp * (temp - 1)) / num));
        }
    }
    cout << ans << "\n";
    return 0;
}