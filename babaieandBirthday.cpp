#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;

struct dt
{
    double r, h, v;
    ll i;
};
dt srr[100010];
double lis[100010];

// double bn(ll low,ll high,double vol)
// {
//     ll mid  = (low+high)/2;
//     if(srr[low].v>vol)
//     {
//         return 0;
//     }

//     if(vol>srr[high].v)
//     return lis[srr[high].i];
//     if((vol>srr[mid].v)&&(vol<srr[mid+1].v)
//     {
//         return lis[srr[mid].i];
//     }
//     else if((vol<srr[mid].v))
//     {
//         return bn(low,mid-1,vol);
//     }
//     else{
//         return bn(mid+1,high,vol);
//     }
// }
bool comp(dt a,dt b)
{
    return a.i<b.i;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    for(ll i=0;i<100010;i++)
    {
        srr[i].i=MAX;
        srr[i].v=MAX;
    }
    ll n;
    cin >> n;
    dt arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].r >> arr[i].h;
        arr[i].v =  arr[i].r * arr[i].r * arr[i].h;
        arr[i].i=i;
        srr[i]=arr[i];
    }
    sort(srr,srr+100010,comp);

    for (ll i = 0; i < n; i++)
    {
        lis[i] = arr[i].v;
    }
    
    for(ll i = 0; i < n; i++)
    {
        lis[i]+=bn(0,i,)
    }
    
}