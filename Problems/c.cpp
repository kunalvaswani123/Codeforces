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
map <ll,ll> m;
map <ll,ll> c;
ll maxans=0;
void primecheck(ll n) 
{ 
    if(n%2==0)
    {
    	if(m[2]>0)
    	{
    		c[2]++;
    		if(c[2]>maxans)
    			maxans=c[2];
    	}
    	else
    	{
	    	m[2]++;
    		c[2]++;
    	}
	    while(n%2==0) 
	        n=n/2; 
	} 
    for(ll i=3;i<=sqrt(n);i=i+2) 
    { 
        if(n%i==0) 
        { 
            if(m[i]>0)
            {
            	c[i]++;
            	if(c[i]>maxans)
	    			maxans=c[i];
            }
            else
            {
            	c[i]++;
            	m[i]++;
            }
            while(n%i==0)
	            n=n/i; 
        } 
    } 
    if(n>2) 
    {
	    if(m[n]>0)
	    {
	    	c[n]++;
	    	if(c[n]>maxans)
	    		maxans=c[n];
	    }
        else
        {
        	c[n]++;
        	m[n]++;
        }
    }
} 
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin>>n;
 	for(i=0;i<n;i++)
 		cin>>arr[i];
	ll gcd=arr[0];
	for(i=1;i<n;i++)
	{
 		gcd=__gcd(arr[i],gcd);
	}
	for(i=0;i<n;i++)
	{
 		arr[i]=arr[i]/gcd;
	}
	for(i=0;i<n;i++)
	{
		primecheck(arr[i]);
	}
	ll x=arr[0];
	ll f=1;
	for(i=1;i<n;i++)
	{	
		if(x!=arr[i])
			f=0;
	}
	if(f==1)
		cout<<-1<<endl;
	else if(maxans==0)
		cout<<1<<endl;
	else
		cout<<n-maxans<<endl;
	return 0;
}