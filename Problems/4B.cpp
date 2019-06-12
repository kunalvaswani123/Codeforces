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
ll arr[32];
ll minv[32];
ll maxv[32];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,d,s;
 	cin>>d>>s;
 	for(i=0;i<d;i++)
 		cin>>minv[i]>>maxv[i];
 	ll cur=0;
 	for(i=0;i<d;i++)
 		arr[i]+=minv[i],cur+=arr[i];
 	if(cur>s)
 	{
 		cout<<"NO";
 		return 0;
 	}
 	while(cur<s)
 	{
 		ll flag=0;
 		for(i=0;i<d;i++)
 		{
 			if(arr[i]+1<=maxv[i])
 			{
 				flag=1;
 				arr[i]++;
 				cur++;
 			}
 			if(cur==s)
 				break;
 		}
 		if(flag==0)
 			break;
 	}
 	if(cur!=s)
 	{
 		cout<<"NO";
 		return 0;
 	}	
 	cout<<"YES"<<endl;
 	for(i=0;i<d;i++)
 		cout<<arr[i]<<' ';
 	cout<<endl;
	return 0;
}