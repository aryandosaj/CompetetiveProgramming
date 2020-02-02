#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll arr[200];
    vector<ll> ind[200];
    map<ll, ll> mp[200];
    for (char i = 'a'; i <= 'z'; i++)
    {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    ll l = s.length();
    ll cum_sum[l];
    ll sum = 0;
    for (ll i = 0; i < l; i++)
    {
        sum += arr[s[i]];
        cum_sum[i] = sum;

        ind[s[i]].push_back(cum_sum[i]);
        mp[s[i]][cum_sum[i]]++;
    }
    ll ans = 0;
    for (ll i = 'a'; i <= 'z'; i++)
    {
        for (ll j = 0; j < ind[i].size(); j++)
        {
            // cout << (ind[i][j])<<" ";
            if (arr[i] != 0)
            {
                ans += mp[i][ind[i][j] + arr[i]];
                if(mp[i][ind[i][j]]>0)
                mp[i][ind[i][j]]--;
                // cout<<(char)i<<" "<<ans<<"\n";
            }
            else
            {
                ans += mp[i][ind[i][j]] * (mp[i][ind[i][j]] - 1) / 2;
                mp[i][ind[i][j]] = 0;
            }
            // ans += mp[i][ind[i][j] + arr[i]];
        }
    }
    cout << ans;
}