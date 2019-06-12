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
const ll L=1e4;
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	ll s=0,e,m=1;
	ll c=1;
	ll as,ae;
	for(i=1;i<n;i++)
	{
		if(arr[i]==(arr[i-1]+1))
		{
			if(s==0)
				s=arr[i-1];
			c++;
		}
		else
		{
			e=arr[i-1];
			if(c>m||(c==m&&(s==0||e==1000)))
			{
				m=c;
				as=s;
				ae=e;
			}
			s=0;
			c=1;
		}
	}
	e=arr[i-1];
	if(c>m||(c==m&&(s==0||e==1000)))
	{
		m=c;
		as=s;
		ae=e;
	}
	ll ans=m;
	if(as!=1)
		ans--;
	if(ae!=1000)
		ans--;
	if(ans==-1)
		cout<<0<<endl;
	else
		cout<<ans<<endl;
	return 0;
}