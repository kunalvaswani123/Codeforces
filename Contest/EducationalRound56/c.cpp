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
ll barr[2*L];
ll aarr[2*L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin>>n;
 	for(i=1;i<=n/2;i++)
 		cin>>barr[i];
 	aarr[n+1]=1e18+5;
	for(i=1;i<=n/2;i++)
	{
		ll temp=min(aarr[n-i+2],barr[i]);
		if(aarr[i-1]>barr[i]-temp)
		{
			aarr[i]=aarr[i-1];
			aarr[n-i+1]=barr[i]-aarr[i];
		}
		else
		{
			aarr[n-i+1]=temp;
			aarr[i]=barr[i]-aarr[n-i+1];
		}
	} 	
	for(i=1;i<=n;i++)
		cout<<aarr[i]<<' ';
	cout<<endl;
	return 0;
}