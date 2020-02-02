#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll dsu[200];
ll ds(ll a)
{
    ll b=a;
    while(dsu[b]!=dsu[dsu[b]])
    {
        b=dsu[b];
    }
    return dsu[b];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<pair<ll, ll> > v;
    for (int i = 0; i < 200; i++)
    {
        dsu[i] = 0;
    }
    dsu[0]=0;
    ll steps = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        if ((dsu[s1[i]] == 0) && (dsu[s2[i]] == 0))   
        {
            dsu[s1[i]] = s2[i];
            dsu[s2[i]] = s2[i];
            v.push_back(make_pair(s1[i], s2[i]));
            
        }
        else if ((dsu[s1[i]] == 0) || (dsu[s2[i]] == 0))
        {
            if (dsu[s1[i]] == 0)
            {
                dsu[s1[i]] = dsu[dsu[s2[i]]];
                // dsu[s1[i]] = dsu[s2[i]];
                v.push_back(make_pair(s1[i], dsu[dsu[s2[i]]]));
                
            }
            else
            {
                dsu[s2[i]] = dsu[dsu[s1[i]]];
                v.push_back(make_pair(s2[i], dsu[dsu[s1[i]]]));
            }
        }
        else if (ds(s1[i]) != ds(s2[i]) )
        {
            v.push_back(make_pair(ds(s1[i]), ds(s2[i]))); 
            dsu[ds(s1[i])] = dsu[ds(s2[i])];
            
            
        }
    }
    cout<<v.size()<<"\n";
    for(int i = 0; i < v.size(); i++)
    {
        cout<<(char)v[i].first<<" "<<(char)v[i].second<<"\n";
    }
    
}
