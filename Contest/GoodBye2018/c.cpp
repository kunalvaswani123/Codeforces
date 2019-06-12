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
ll n;
set<pll> as;
ll sev()
{
	ll i,j;
	for(i=1;i*i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			if(as.lower_bound(mp(j+1,0))!=as.end())
			{
				pll x=*as.lower_bound(mp(j+1,0));
				x.se+=(j+1);
			}
			else
				as.insert(mp(j+1,j+1));
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i;
 	cin>>n;
 	sev();
 	set<ll> as2;
 	set<pll>::iterator it;
 	for(it=as.begin();it!=as.end();it++)
 		as2.insert((*it).se);
 	set<ll>::iterator it2;
 	for(it2=as2.begin();it2!=as2.end();it2++)
 		cout<<*it2<<' ';
 	cout<<endl;	
	return 0;
}