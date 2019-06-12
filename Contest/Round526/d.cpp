#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
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
const ll L=1e5;
ll lits[3*L+5];
ll visited[3*L+5];
ll ans[3*L+5];
vector<pll >ad[3*L+5];
void dfs(ll id,ll curvalue)
{
	if(visited[id]==0)
	{
		ll i;
		if(ad[id].size()==1&&visited[ad[id][0].fi]==1)
		{
			ans[ad[id][0].fi]=curvalue+lits[id];
		}
		else
		{
			pqq<pll>check;
			ans[id]=curvalue;
			for(i=0;i<ad[id].size();i++)
			{
				ll sendval=0;
				if(curvalue+lits[id]>=ad[id][i].se)
					sendval=curvalue+lits[id]-ad[id][i].se;
				dfs(ad[id][i].fi,sendval);
				ans[id]=max(ans[id],ans[ad[id][i].fi]);
				if(lits[id]>=ad[id][i].se)
					check.push(mp(ans[ad[id][i].fi],ad[id][i].se));
			}
			if(check.size()>=2)
			{
				pll a=check.top();
				check.pop();
				pll b=check.top();
				ans[id]=max(ans[id],a.fi+b.fi+lits[id]-a.se-b.se);
			}

		}
		visited[id]=1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
	ll i,n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>lits[i];
	ll u,v,c;
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v>>c;
		ad[u].pb(mp(v,c));
		ad[v].pb(mp(u,c));	
	}
	dfs(1,0);
	ll an=INT_MIN;
	for(i=1;i<=n;i++)
		an=max(an,ans[i]);
	cout<<an<<endl;
	return 0;
}