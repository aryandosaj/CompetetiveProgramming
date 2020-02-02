#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    ll arr[n],brr[n];
    
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i]>>brr[i];
    }
    ll t = min(arr[n-1],brr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if((arr[i]>=t)||(brr[i]>=t))
        {
            if((arr[i]>=t)&&(brr[i]>=t))
            {
                t=min(arr[i],brr[i]);
            }
            else
            {
                if(arr[i]>=t)
                t=arr[i];
                if(brr[i]>=t)
                t=brr[i];
            }

        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

}