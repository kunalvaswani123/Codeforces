#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=998244353;
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
ll flag=0;
ll visited[3*L];
ll valset[3*L];
ll ans=1;
vector<ll>ad[3*L];
void dfs(ll ind,ll val,ll parent)
{
	ll i;
	ll send;
	visited[ind]=1;
	valset[ind]=val;
	if(val==0)
	{
		ans=(ans*2)%mod;
		send=1;
	}
	else
		send=0;
	for(i=0;i<ad[ind].size();i++)
	{
		if(!visited[ad[ind][i]])
			dfs(ad[ind][i],send,ind);
		else if(ad[ind][i]!=parent)
		{
			if(valset[ad[ind][i]]==valset[parent])
				flag=1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,t;
 	cin>>t;
 		
 	while(t--)
 	{	
 		ll n,m;
		ll u,v;
 		cin>>n>>m;
 	for(i=1;i<=n;i++)
 			valset[i]=-1;
 		for(i=0;i<m;i++)
 		{
 			cin>>u>>v;
 			ad[u].pb(v);
 			ad[v].pb(u);
 		}
 		dfs(1,0,-1);
 		ll tempans1=ans%mod;
 		for(i=1;i<=n;i++)
 			visited[i]=0;
 		for(i=1;i<=n;i++)
 			valset[i]=-1;
 		ans=1;
 		dfs(1,1,-1);
 		ll tempans2=ans%mod;
 		for(i=1;i<=n;i++)
 			visited[i]=0;
 		for(i=1;i<=n;i++)
 			valset[i]=-1;
 		
 		if(flag==1)
 			cout<<0<<endl;
 		else
 		{
	 		ans=(tempans1+tempans2)%mod;
	 		cout<<ans<<endl;
 		}
 		flag=0;
 		ans=1;
 		for(i=1;i<=n;i++)
	 		ad[i].clear();
 	}   
	return 0;
}