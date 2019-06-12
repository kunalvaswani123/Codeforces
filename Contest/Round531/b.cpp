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
ll carr[L];
ll k1[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n,k;
 	cin>>n>>k;
 	for(i=0;i<n;i++)
 		cin>>arr[i];
 	ll st=1;
 	for(i=0;i<n;i++)
 	{
	 	if(carr[i]==0)
	 	{
		 	ll c=st;
		 	ll count=1;
		 	carr[i]=st;
		 	k1[st]=1;
	 		for(j=0;j<n;j++)
	 		{
	 			if(j!=i&&arr[j]==arr[i])
	 			{
		 			c++;
		 			if(c>k)c=1;
		 			carr[j]=c;
	 				k1[c]=1;
	 				count++;
	 			}
	 		}
	 		if(count>k)
	 		{
	 			cout<<"NO"<<endl;
	 			return 0;
	 		}
	 		c++;
	 		if(c>k)c=1;
	 		st=c;
	 	}
 	}
 	for(i=1;i<=k;i++)
 	{
 		if(k1[i]==0)
 		{
 			cout<<"NO"<<endl;
	 			return 0;
 		}
 	}
	cout<<"YES"<<endl;
	for(i=0;i<n;i++)
		cout<<carr[i]<<' ';
	cout<<endl;
	return 0;
}