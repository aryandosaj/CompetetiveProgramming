#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
#define vll vector<ll>
#define MAX 1000000007

/*
 * Complete the 'invitations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY pairs
 */

ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
ll fact[200001];
vll graph[200005];
ll dsu[200005];
map<ll, ll> visit;
map<ll, ll> child;
ll ans = 1;

void dfs(ll u, ll d)
{
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != d)
        {
            dfs(v, u);
            child[u] += child[v] + 1;
        }
    }
}
ll inv_mod(ll a)
{
    return power(a, MAX - 2, MAX);
}
ll ncr(ll n, ll r)
{
    return ((((fact[n] * inv_mod(fact[r])) % MAX) * inv_mod(fact[n - r])) % MAX);
}
ll find_dsu(ll u)
{
    while (dsu[u] != u)
    {
        u = dsu[u];
    }
    return u;
}
ll rec(ll u, ll n)
{
    visit[u] = 1;
    if (graph[u].size() == child[u])
    {
        
        for(ll i = 0; i < graph[u].size(); i++)
        {
            visit[graph[u][i]]=1;
        }
        // cout<<(ncr(n, graph[u].size() + 1) * fact[child[u]]) % MAX;
        
        return (ncr(n, graph[u].size() + 1) * fact[child[u]]) % MAX;

    }
    n--;
    ll ans = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        ans = (ans * rec(v, child[v]+1)*ncr(n,child[v]+1)) % MAX;
        n -= (child[v] + 1);
    }
    return ans;
}

int invitations(int n, vector<vector<int>> pairs) {
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < 200005; i++)
    {
        fact[i] = (i * fact[i - 1]) % MAX;
    }

    for (ll i = 0; i < 200005; i++)
        {
            dsu[i] = i;
        }
    for (auto i:pairs)
    {
             ll u, v;
        u = i[0];v = i[0];
            graph[u].push_back(v);
            dsu[v] = dsu[u];
    }
    
        // cin >> n >> m;

        

        // for (ll i = 0; i < m; i++)
        // {
        //     ll u, v;
        //     cin >> u >> v;
        //     graph[u].push_back(v);
        //     dsu[v] = dsu[u];
        // }
        ll ans = 1;
        ll temp=n;
        
        for (ll i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                ll dad = find_dsu(i);
                // cout<<dad;
                dfs(dad, -1);
                ans=(((ans*rec(dad,child[dad]+1))%MAX)*ncr(temp,child[dad]+1))%MAX;
                temp-=(child[dad]+1);
            }
            graph[i].clear();
        }
        
        visit.clear();
        child.clear();
    return ans;
}

int main()
{
    
    ofstream fout(getenv("OUTPUT_PATH"));

    string tc_temp;
    getline(cin, tc_temp);

    int tc = stoi(ltrim(rtrim(tc_temp)));

    for (int tc_itr = 0; tc_itr < tc; tc_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> pairs(m);

        for (int i = 0; i < m; i++) {
            pairs[i].resize(2);

            string pairs_row_temp_temp;
            getline(cin, pairs_row_temp_temp);

            vector<string> pairs_row_temp = split(rtrim(pairs_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int pairs_row_item = stoi(pairs_row_temp[j]);

                pairs[i][j] = pairs_row_item;
            }
        }

        int result = invitations(n, pairs);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
