#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
const ll L = 1e5 + 5;
vector<ll>ad[2 * L];
ll vis[2 * L];
ll flag = 0;
vector<pll>edgs;
void dfs(ll ind, ll val)
{
    ll i;
    vis[ind] = val;
    
    if(val == 1)
        val = 2;
    else
        val = 1;
    
    for(i=0;i<ad[ind].size();i++)
    {
        if(vis[ad[ind][i]] == 0)
            dfs(ad[ind][i], val);
        else if(vis[ad[ind][i]] == vis[ind])
            flag = 1;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n,m,u,v;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> u >> v;
        edgs.pb(mp(u,v));
        ad[u].pb(v);
        ad[v].pb(u);
    }
    dfs(1,1);
    if(flag == 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for(i=0;i<edgs.size();i++)
        {
            u = edgs[i].fi, v = edgs[i].se;
            if(vis[u] == 1 && vis[v] == 2)
                cout << 0;
            else
                cout << 1;
        }
    }
    cout << endl;
	return 0;
}