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
ll arr1[L];
ll arr2[L];
ll ans[L];
ll n;
ll flag=0;
void check(int value,int index)
{
	ll i;
	if(index==n)
	{
		flag=1;
		return;
	}
	cout<<index<<' '<<value<<endl;
	ans[index]=value;
	for(i=0;i<=3;i++)
	{
		ll a1=value|i;
		ll a2=value&i;
		if(a1==arr1[index]&&a2==arr2[index])
			check(i,index+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i;	
 	cin>>n;

 	for(i=0;i<n-1;i++)
 		cin>>arr1[i];
 	for(i=0;i<n-1;i++)
 		cin>>arr2[i];
 	
 	for(i=0;i<=3;i++)
 	{
 		check(i,0);
 		if(flag==1)
 		{
 			cout<<"YES"<<endl;
 			for(ll j=0;j<n;j++)
 				cout<<ans[j]<<' ';
 			cout<<endl;
 			return 0;
 		}
 	}
 	cout<<"NO"<<endl;
	return 0;
}