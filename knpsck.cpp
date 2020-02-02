#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct wcr
{
    ll w;
    ll c;
    ll r;
};
bool mycomparator(wcr a, wcr b)
{
    return a.c > b.c;
}
struct answer
{
    ll ans;
    ll i1;
    ll i2;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    vector<wcr> s1;
    vector<wcr> s2;
    wcr ratio[n];
    ll weight = 0;
    answer a[n];
    a[0].ans = 0;
    a[0].i1 = 0;
    a[0].i2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> ratio[i].w >> ratio[i].c;
        // ratio[i].r = ratio[i].c / ratio[i].w;
        if (ratio[i].w == 1)
            s1.push_back(ratio[i]);
        else
            s2.push_back(ratio[i]);
        weight += ratio[i].w;
    }
    // sort(ratio, ratio + n, mycomparator);
    sort(s1.begin(), s1.end(), mycomparator);
    sort(s2.begin(), s2.end(), mycomparator);
    if (s1.size() == 0)
    {
        a[1].ans = 0;
        a[1].i1 = 0;
    }
    else
        a[1].ans = s1[0].c;
        a[1].i1 = 1;
        a[1].i2 = 0;
    // for(int i = 0; i < s1.size(); i++)
    // {
    //     cout<<s2[i].c<<"$$$";
    // }

    wcr zero;
    zero.c = 0;
    s1.push_back(zero);    
    s2.push_back(zero);
    ll l1 = s1.size();
    ll l2 = s2.size();
    
    cout << a[1].ans << " ";
    for (int i = 2; i <= weight; i++)
    {
        if (a[i - 1].i1 > l1 - 2)
        {
            a[i - 1].i1 = l1 - 1;
        }
        if (a[i - 2].i2 > l2 - 2)
        {
            a[i - 2].i2 = l2 - 1;
        }
        // ans[i]=max(ans[i-1]+s1[ind_1].c,ans[i-2]+s1[ind_2++].c);
        if ((a[i - 1].ans + s1[a[i - 1].i1].c) > (a[i - 2].ans + s2[a[i - 2].i2].c))
        {

            a[i].ans = a[i - 1].ans + s1[a[i - 1].i1].c;
            a[i].i1 = a[i - 1].i1 + 1;
            a[i].i2 = a[i - 2].i2;
        }
        else
        {
            // cout<<"here--"<<s2[a[i - 2].i2].c;
            a[i].ans = a[i - 2].ans + s2[a[i - 2].i2].c;
            a[i].i2 = a[i - 2].i2 + 1;
            a[i].i1 = a[i - 2].i1;
        }
        cout << a[i].ans << " ";
    }
}