#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       int n,result=0;
       cin>>n;
       string s1,s2;
       cin>>s1>>s2;
       unordered_map<char,int>f1;
       unordered_map<char,int>f2;
       for(int i=0;i<s1.length();i++)
           f1[s1[i]]++,f2[s2[i]]++;
       for(char i='a';i<='z';i++)
           result+=min(f1[i],f2[i]);
       cout<<result<<endl;
   }
}