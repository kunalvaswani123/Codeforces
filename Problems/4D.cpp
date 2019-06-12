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
ll dp[5005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	vector<pair<pll,ll> >an;
	ll i,j,n,w,h;
	cin>>n>>w>>h;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(w<x&&h<y)
			an.pb(mp(mp(x,y),i+1));
	}
	sort(an.begin(),an.end());
	if(an.size()==0)
	{
		cout<<0<<endl;
		return 0;
	}
	ll ans=0;
	for(i=0;i<an.size();i++)
	{
		dp[i]=1;
		for(j=i-1;j>=0;j--)
		{
			if(an[j].fi.fi<an[i].fi.fi&&an[j].fi.se<an[i].fi.se)
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	vector<ll>pri;
	w=INT_MAX;
	h=INT_MAX; 
	for(i=an.size()-1;i>=0;i--)
	{
		if(dp[i]==ans)
		{
			if(an[i].fi.fi<w&&an[i].fi.se<h)
			{
				pri.pb(an[i].se);
				w=an[i].fi.fi;
				h=an[i].fi.se;
				ans--;
			}
		}
	}
	reverse(pri.begin(),pri.end());
	for(i=0;i<pri.size();i++)
		cout<<pri[i]<<' ';
	cout<<endl;
	return 0;
}