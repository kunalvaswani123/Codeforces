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
bool vis[2*L];
bool rec[2*L];
ll cost[2*L];
vector<ll>ad[2*L];
vector<ll>v;
ll mincos[2*L];
void dfs(ll ind)
{
	vis[ind]=true;
	if(ad[ind].size()==1&&ad[ind][0]==ind)
	{
		mincos[ind]=cost[ind];
		v.pb(ind);
		return;
	}
	rec[ind]=true;
	ll i;
	mincos[ind]=cost[ind];
	for(i=0;i<ad[ind].size();i++)
	{
		if(!vis[ad[ind][i]])
		{
			dfs(ad[ind][i]);
			mincos[ind]=min(mincos[ad[ind][i]],mincos[ind]);
		}
		else if(rec[ad[ind][i]])
			v.pb(ad[ind][i]);
	}
	rec[ind]=false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,te;
 	cin>>n;
 	for(i=1;i<=n;i++)
 		cin>>cost[i];
 	for(i=1;i<=n;i++)
 	{
 		cin>>te;
 		ad[i].pb(te);
 	}
 	for(i=1;i<=n;i++)
 	{
 		if(!vis[i])
 			dfs(i);
 	}
 	ll ans=0;
 	for(i=0;i<v.size();i++)
 		ans+=mincos[v[i]];
 	cout<<ans<<endl;
	return 0;
}