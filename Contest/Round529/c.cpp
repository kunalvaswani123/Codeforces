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
ll ceil(ll a,ll b)
{
	if(a%b==0)
		return a/b;
	return a/b + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,k;
 	cin>>n>>k;
 	ll temp=n;
 	vector<ll>ans;
 	ll count=0;
 	if(k>temp)
 	{
 		cout<<"NO"<<endl;
 		return 0;
 	}
 	while(k<ceil(temp,2)&&temp>0)
 	{
 		if(temp%2==1)
 		{
 			k--;
 			ans.pb(pow(2,count));
 		}
 		count++;
 		temp/=2;
 	}
 	ll i;
 	vector<ll>finalans;
 	
 	for(i=0;i<ans.size();i++)
 		finalans.pb(ans[i]);

	for(i=1;i<=(temp-k);i++)
 		finalans.pb(pow(2,count+1));
	
	for(i=1;i<=(2*k-temp);i++)
 		finalans.pb(pow(2,count));

 	ll check=0;
	for(i=0;i<finalans.size();i++)
		check+=finalans[i];
	if(check!=n)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(i=0;i<finalans.size();i++)
			cout<<finalans[i]<<' ';
		cout<<endl;
	}
	return 0;	
}