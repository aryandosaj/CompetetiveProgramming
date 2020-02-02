#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define MAX 1000000007;
ll po[100005];
// p=31 for lower case
// p=53 for both cases
// ll MAX = pow(2,63)-25;

ll generate_hash(string s)
{
    ll hash=0;
    for(ll i=0;i<s.length();i++)
        hash = (hash+po[i]*s[i])%MAX;
    return hash;
}
ll reverse_generate_hash(string s)
{
    ll hash=0;
    for(ll i=s.length()-1;i>=0;i--)
        hash = (hash+po[i]*s[i])%MAX;
    return hash;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p = 53;
    po[0]=1;
    for(int i=1;i<100005;i++)
        po[i] = (po[i-1]*p)%MAX;
    
    
}