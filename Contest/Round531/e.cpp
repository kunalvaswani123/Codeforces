#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=998244353;
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
ll arr[2*L];
map<ll,ll>mp;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n;
cin>>n;
    for(i=0;i<n;i++)
    	cin>>arr[i];
    ll count=0;
    ll j;
    ll st=1;
    for(i=0;i<n;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		if(arr[j]==arr[i])
    		{
				st++;
				st=st%mod;	    			
    			i=j;
    			break;
    		}
    	}
    	if(j==n)
    	{
    		st=(st+n-i)%mod;
    	}
    }
    cout<<st<<endl;
	return 0;
}