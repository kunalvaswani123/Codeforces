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
const ll L=1e6;
map <pair<ll,ll>,pair<ll,ll> >mp1;
ll n;
ll arr1[L];
ll arr2[L];
ll ans[L];
ll flag=0;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j;
    for(i=0;i<=3;i++)
    {
    	for(j=0;j<=3;j++)
    	{
    		pair<ll,ll>a;
    		a.fi=i;
    		a.se=j;
    		mp1[a].fi=-1;
    		mp1[a].se=-1;
    	}
    }
    for(i=0;i<=3;i++)
    {
    	for(j=i;j<=3;j++)
    	{
    		pair<ll,ll>a;
    		a.fi=i|j;
    		a.se=i&j;
    		mp1[a].fi=i;
    		mp1[a].se=j;
    	}
    }
    cin>>n;
    for(i=0;i<n-1;i++)
 		cin>>arr1[i];
 	for(i=0;i<n-1;i++)
 		cin>>arr2[i];
 	
 	if(n==2)
 	{
 		pair<ll,ll>px;
 		px.fi=arr1[0];
 		px.se=arr2[0];
 		ll aa=mp1[px].fi;
 		ll bb=mp1[px].se;
 		if(aa==-1)
 			cout<<"NO"<<endl;
 		else
 		{
 			cout<<"YES"<<endl;
	 		cout<<aa<<' '<<bb<<endl;
 		}
 		return 0;
 	}


 	pair<ll,ll>p1;
	p1.fi=arr1[0];
	p1.se=arr2[0];
	pair<ll,ll>p2;
	p2.fi=arr1[1];
	p2.se=arr2[1];
	ll x1=mp1[p1].fi;
	ll x2=mp1[p1].se;
	ll f1=mp1[p2].fi;
	ll f2=mp1[p2].se;

	if(x1==f1||x1==f2)
	{
		ans[1]=x1;
		ans[0]=x2;
	}
	else if(x2==f1||x2==f2)
	{
		ans[1]=x2;
		ans[0]=x1;
	}
 	for(i=1;i<n-1;i++)
 	{
 		p1.fi=arr1[i];
 		p1.se=arr2[i];
 		// p2.fi=arr1[i-1];
 		// p2.se=arr2[i-1];
 		x1=mp1[p1].fi;
 		x2=mp1[p1].se;
 		// f1=mp1[p2].fi;
 		// f2=mp1[p2].se;
 		if(x1==ans[i])
 			ans[i+1]=x2;
 		else if(x2==ans[i])
 			ans[i+1]=x1;
 		else
 		{
 			cout<<"NO"<<endl;
 			return 0;
 		}
 	}
 	cout<<"YES"<<endl;
 	for(i=0;i<n;i++)
 		cout<<ans[i]<<' ';
 	cout<<endl;
	return 0;
}