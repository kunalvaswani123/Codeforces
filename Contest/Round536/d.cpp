#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
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
const ll L =1e5+5;
vector<ll>ad[L];
set<ll>vis;
vector<ll>ans;
ll check[L];
ll n;
set<ll>::iterator it;
void dfs(ll ind)
{
	check[ind]=1;
	ans.pb(ind);
	if(ans.size()==n)
		return;
	vis.erase(vis.find(ind));
	ll i;
	for(i=0;i<ad[ind].size();i++)
	{
		if(check[ind]==0)
			vis.insert(ad[ind][i]);
	}
	it=vis.begin();
	dfs(*it);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m;
    cin >> n >> m;
    ll i;
    ll a,b;
    for(i=0;i<m;i++)
    {
	   cin >> a >> b;
	   ad[a].pb(b);
	   ad[b].pb(a);
    }
    vis.insert(1);
    it=vis.begin();
    dfs(*it);
    for(i=0;i<ans.size();i++)
    	cout << ans[i] << ' ';
    cout << endl;
	return 0;
}