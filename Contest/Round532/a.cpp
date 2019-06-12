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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,k;
 	cin>>n>>k;
 	ll i,j;
 	ll maxva=INT_MIN;
 	ll check[101];
 	for(i=1;i<=n;i++)
 		cin>>check[i];
 	for(i=1;i<=n;i++)
	{
		ll arr[101];
		for(j=1;j<=n;j++)
			arr[j]=1;
		for(j=i;j<=n;j+=k)
			arr[j]=0;
		for(j=i;j>=1;j-=k)
			arr[j]=0;
		ll val1=0,val2=0;
		for(j=1;j<=n;j++)
		{
			if(check[j]==1&&arr[j]==1)
				val1++;
			else if(check[j]==-1&&arr[j]==1)
				val2++;
		}
		maxva=max(maxva,abs(val1-val2));	
	}		
	cout<<maxva<<endl;
	return 0;
}