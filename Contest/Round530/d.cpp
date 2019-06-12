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
vector<ll>ad[L];
ll visited[L];
ll sum[L];
ll ans=0;
ll flag=0;
void dfs(ll ind,ll dep,ll val)
{
	visited[ind]=1;
	ll i;
	if(dep%2!=0)
		ans+=(sum[ind]-val);
	else
		sum[ind]=val;
	if(dep%2==0&&!(ind!=1&&ad[ind].size()==1))
	{
		ll sumc=0;
		ll count=0;
		ll minval=1e12;
		for(i=0;i<ad[ind].size();i++)
		{
			if(!visited[ad[ind][i]])
			{
				sumc+=(sum[ad[ind][i]]);
				count++;
				minval=min(sum[ad[ind][i]],minval);
			}
		}
		// cout<<sumc<<endl;
		ll sumc2=sumc-count*(minval)+minval-val;
		// cout<<sumc2<<endl;
		if(minval!=1e12&&sumc2<sumc&&minval>=val)
		{
			ans+=(minval-val);
			sum[ind]=minval;
		}
	}
	for(i=0;i<ad[ind].size();i++)
	{
		if(!visited[ad[ind][i]])
		{
			if(sum[ad[ind][i]]!=-1&&sum[ad[ind][i]]<sum[ind])
				flag=1;
			dfs(ad[ind][i],dep+1,sum[ind]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,x,n;
 	cin>>n;
 	for(i=2;i<=n;i++)
 	{
 		cin>>x;
 		ad[x].pb(i);
 		ad[i].pb(x);
 	}	
 	for(i=1;i<=n;i++)
 		cin>>sum[i]; 	
 	dfs(1,1,0);
 	if(flag==1)
 		cout<<-1<<endl;
 	else
 		cout<<ans<<endl;
	return 0;
}