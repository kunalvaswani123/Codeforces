#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
const ll L = 2e5 + 5;
vector<ll> ad[L];
bool vis[L];
ll ans = 1;
void dfs(ll ind, ll l)
{	
	vis[ind] = true;
	ll i;
	ll temp = 1;
	for(i=0;i<sz(ad[ind]);i++)
	{
		if(!vis[ad[ind][i]])
		{
			ans = (ans * temp) % mod;
			temp++;
			dfs(ad[ind][i], l+1);
		}
	}
	if(l != 0)
		ans = (ans * temp) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	ll x,y;
 	for(i=0;i<n-1;i++)
 	{
 		cin >> x >> y;
 		ad[x].pb(y);
 		ad[y].pb(x);
 	}
 	dfs(1, 0);
 	ans = (ans * n) % mod;
 	cout << ans << endl;
	return 0;
}