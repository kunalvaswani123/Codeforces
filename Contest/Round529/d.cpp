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
pll arr[2*L];
ll check(ll a,ll b)
{
	if(arr[a].fi==b)
		return 1;
	if(arr[a].se==b)
		return 1;
	return 0;
}
ll ans[2*L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,x,y,i;
 	cin>>n;
 	for(i=1;i<=n;i++)
 	{
 		cin>>x>>y;
 		arr[i].fi=x;
 		arr[i].se=y;
 	}
 	ans[0]=1;
 	for(i=0;i<n;i++)
 	{
 		if(ans[i+1]==0)
 		{
	 		if(check(arr[ans[i]].fi,arr[ans[i]].se)==1)
	 		{
	 			ans[i+1]=arr[ans[i]].fi;
	 			ans[i+2]=arr[ans[i]].se;
	 		}
	 		else
	 		{
	 			ans[i+1]=arr[ans[i]].se;
	 			ans[i+2]=arr[ans[i]].fi;	
	 		}
 		}
 	}
 	for(i=0;i<n;i++)
 		cout<<ans[i]<<' ';
 	cout<<endl;
	return 0;
}