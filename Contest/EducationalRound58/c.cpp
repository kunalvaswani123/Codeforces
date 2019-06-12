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
ll ans[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,t,n,l,r;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n;
 		vector<pair<pll,ll> >as;
 		for(i=0;i<n;i++)
 		{
 			cin>>l>>r;
 			as.pb(mp(mp(l,r),i));
 		}
 		sort(as.begin(),as.end());
 		ll maxt=as[0].fi.se;
 		ans[as[0].se]=1;
 		for(i=1;i<n;i++)
 		{	
 			if(as[i].fi.fi<=maxt)
 			{
 				maxt=max(maxt,as[i].fi.se);
 				ans[as[i].se]=1;
 			}
 			else
 				break;
 		}
 		for(;i<n;i++)
 			ans[as[i].se]=2;
 		ll f=0;
 		for(i=0;i<n;i++)
 		{
 			if(ans[i]==2)
 				f=1;
 		}	
 		if(f==0)
 			cout<<-1<<endl;
 		else
 		{
 			for(i=0;i<n;i++)
 				cout<<ans[i]<<' ';
 			cout<<endl;
 		}
 	}   
	return 0;
}