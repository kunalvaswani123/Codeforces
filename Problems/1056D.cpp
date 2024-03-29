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
bool vis[L];
vector<ll>as;
ll dfs(ll ind)
{
	vis[ind]=true;
	ll i;
	if(ad[ind].size()==1&&ind!=1)
	{
		as.pb(1);
		return 1;
	}
	ll count=0;
	for(i=0;i<ad[ind].size();i++)
	{
		if(!vis[ad[ind][i]])
			count+=dfs(ad[ind][i]);
	}
	as.pb(count);
	return count;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,te;
 	cin>>n;
 	if(n==1)
 	{
 		cout<<1<<endl;
 		return 0;
 	}
 	for(i=2;i<=n;i++)
 	{
 		cin>>te;
 		ad[i].pb(te);
 		ad[te].pb(i);
 	}
 	dfs(1);
 	sort(as.begin(),as.end());
 	for(i=0;i<as.size();i++)
 		cout<<as[i]<<' ';
 	cout<<endl;
	return 0;
}