#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll lps[1000010];
void long_pre_suf(string s1)
{
    ll l=s1.length();
    
    lps[0]=0;
    ll pre=0;ll suf=1; 
    while((suf<l)&&(pre<l))
    {
        if(s1[pre]==s1[suf])
        {
           lps[suf]=pre+1;
           suf++;pre++;

        }
        else
        {
            if(pre!=0)
            {
                pre=lps[pre-1];
            }
            else
            {
                lps[suf]=0;
                suf++;
            }
        }
    }
    // for(int i = 0; i < l; i++)
    // {
    //     cout<<lps[i]<<" ";
    // }
    
    
}
int main()
{
   
    //code start here
    string s,ss;
    cin>>s;
    // cout<<s<<"hsuv";
    ss=s;
    ll l=s.length(),flag=0;
    // cout<<long_pre_suf(s)<<" oo";return 0;
    if(l>2){
    for(ll i = 0; i < l; i++)
    {
        if(s[0]!=s[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {cout<<s.substr(2);return 0;}}
    
    long_pre_suf(s);
    ss[ss.length()-1]=' ';
    ll pass=s.length();
    ll cc=0;
    while(cc<3)
    {
        
        pass=lps[pass-1];
        // cout<<pass<<" -";
        if(pass==0)
        break;
        for(ll i=0;i<l-1;i++)
        {
            if(pass==lps[i])
            {
                cout<<s.substr(0,pass);
                return 0;
            }
        }
        cc++;
        
        //  cout<<pass<<"-";
    }
    cout<<"Just a legend";

}