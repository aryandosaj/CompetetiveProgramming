    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    #define vll vector<ll>
    ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
    #define MAX 1000000007
    double fun(double num,ll n)
    {
        if(n==0)return num;
        if(n&1)
        {num/=2.0;return fun(num,n-1);}
        else
        {
            return fun(fun(num,n/2),n/2);
        }
    }
    int main()
    {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll p[n];
        for(int i=0;i<n;i++)
            cin>>p[i];
            sort(p,p+n);
            set<ll>ans;
            ans.insert(p[0]);
            long double s=p[0];
            long double d=1.0;
            unordered_map<ll,ll>mp;
            mp[p[0]]=1;
            for(ll j=1;j<n;j++)
            {
                // if(j<=60)
                {
                    d/=2.0;
                    s+= p[j]*d;
                }
                ans.insert((ll)s);
                mp[(ll)s]=j+1;
            }
            // for(auto i:ans)cout<<i<<" ";cout<<"\n";
            while(q--)
            {
                ll x;
                cin>>x;
                auto p  = ans.lower_bound(x);
                if(p==ans.begin()){cout<<"0\n";continue;}
                p--;
                
                ll a = *p;
                
                
                cout<<mp[a]<<"\n";
                // if(a==n-1){cout<<n<<"\n";continue;}
                
                // cout<<a<<"\n";
            }
    }
    }