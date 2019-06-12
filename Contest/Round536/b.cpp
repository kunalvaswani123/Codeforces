#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
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
pll c[L];
ll a[L];
ll pos[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,j,n,m;
	cin >> n >> m;
	for(i=0;i<n;i++)
		cin>>a[i];
	ll x;
	for(i=0;i<n;i++)
	{
		cin>>pos[i];
		c[i].fi = pos[i], c[i].se = i;
	}
	sort(c,c+n);
	ll co = 0;
	ll t,d;
	while(m--)
	{
		cin>>t>>d;
		t--;
		ll cost = 0;
		if(a[t]>0)
		{
			if(d>a[t])
			{
				cost+=a[t]*pos[t];
				d-=a[t];
				a[t]=0;
			}
			else
			{
				cost+=d*pos[t];
				a[t]-=d;
				d=0;
			}
		}
		while(d > 0 && co < n)
		{
			if(a[c[co].se]>0)
			{
				if(d>a[c[co].se])
				{
					cost+=a[c[co].se]*c[co].fi;
					d-=a[c[co].se];
					a[c[co].se]=0;
				}
				else
				{
					cost+=d*c[co].fi;
					a[c[co].se]-=d;
					d=0;
				}
			}
			else
				co++;	
		}
		if(d==0)
			cout << cost << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}