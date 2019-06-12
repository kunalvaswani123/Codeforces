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
const ll L=1e5+5;
ll arr[3*L];
bool vis[3*L];
vector<pll >ad[3*L];
ll ans[3*L];
ll pr=0;
void dfs(ll ind)
{
	vis[ind]=true;
	ans[ind]=arr[ind];
	ll tempans=ans[ind];
	ll i;
	ll count=0;
	for(i=0;i<ad[ind].size();i++)
	{
		if(!vis[ad[ind][i].fi])
		{
			dfs(ad[ind][i].fi);
			if(ans[ad[ind][i].fi]-ad[ind][i].se>=0)
			{
				if(count>=1)
					pr=max(pr,tempans+ans[ad[ind][i].fi]-ad[ind][i].se);
				tempans=max(tempans,ans[ad[ind][i].fi]-ad[ind][i].se+ans[ind]);
				count++;
			}
		}
	}
	ans[ind]=tempans;
	pr=max(tempans,pr);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin>>n;
 	for(i=1;i<=n;i++)
 		cin>>arr[i];
 	ll u,v,c;
 	for(i=0;i<n-1;i++)
 	{
 		cin>>u>>v>>c;
 		ad[u].pb(mp(v,c));
 		ad[v].pb(mp(u,c));
 	}
 	dfs(1);
 	cout<<pr<<endl;
	return 0;
}