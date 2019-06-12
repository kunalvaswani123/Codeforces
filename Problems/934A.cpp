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
ll arr1[100];
ll arr2[100];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,k,n,m;
 	cin>>n>>m;
 	ll p1=1e18+1;
 	for(i=0;i<n;i++)
 		cin>>arr1[i];
 	for(i=0;i<m;i++)
 		cin>>arr2[i];
 	for(i=0;i<n;i++)
 	{
 		ll p2=-1e18-1;
 		for(j=0;j<n;j++)
 		{
 			if(j!=i)
 			{
	 			for(k=0;k<m;k++)
		 			p2=max(p2,arr1[j]*arr2[k]);
 			}
 		}
 		if(p2<p1)
 			p1=p2;
 	}	
 	cout<<p1<<endl;
	return 0;
}