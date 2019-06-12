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
ll vis[3*L];
vector<ll>ad[3*L];
ll ans=1;
ll flag=0;
void dfs(ll ind,ll val)
{
	ll i,ch;
	vis[ind]=val;
	if(val==1)
		ch=2;
	else
	{
		ch=1;
		ans=(ans*2)%mod;
	}
	for(i=0;i<ad[ind].size();i++)
	{
		if(vis[ad[ind][i]]==0)
			dfs(ad[ind][i],ch);
		else if(vis[ad[ind][i]]==vis[ind])
			flag=1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll t,n,m,i,j,u,v;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n>>m;
 		while(m--)
 		{
 			cin>>u>>v;
 			ad[u].pb(v);
 			ad[v].pb(u);
 		}
 		vector<ll>ans1;
 		vector<ll>ans2;
 		for(i=1;i<=n;i++)
 		{	
 			if(vis[i]==0)
 				dfs(i,1);
			else
				ans=0;
			ans1.pb(ans%mod);
			ans=1;
 		}
 		for(i=1;i<=n;i++)
	 		vis[i]=0;
	 	for(i=1;i<=n;i++)
 		{	
 			if(vis[i]==0)
 				dfs(i,2);
 			else
 				ans=0;
			ans2.pb(ans%mod);
			ans=1;
 		}
 		for(i=1;i<=n;i++)
 		{
	 		vis[i]=0;
 			ad[i].clear();
 		}
 		ll finalans=1;
 		for(i=0;i<ans1.size();i++)
 		{
 			ll tempans=(ans1[i]+ans2[i])%mod;
 			if(tempans==0)
 				tempans=1;
 			finalans=(finalans*tempans)%mod;
 		}
 		if(flag==0)
	 		cout<<finalans<<endl;
 		else
 			cout<<0<<endl;
 		flag=0;
 	}   
	return 0;
}