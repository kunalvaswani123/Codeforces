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
 	ll n,i;
 	cin>>n;
 	if(n<=3)
 	{
	 	for(i=0;i<n-1;i++)
	 		cout<<1<<' ';
	 	cout<<n<<endl;   
		return 0;
	}
	ll evens=n/2;
	ll odds=n-evens;
	ll count=0;
	for(i=0;i<odds;i++)
	{
		count++;
		cout<<1<<' ';
	}
	ll start=2;
	while(start<=n)
	{
		ll newevens=evens/2;
		odds=evens-newevens; 
		evens=newevens;
		for(i=0;i<odds;i++)
		{
			if(n%2==0&&n%start!=0&&evens==0)
				cout<<n<<' ';
			else
				cout<<start<<' ';
			count++;
		}
		start+=start;
	}
	cout<<endl;
	return 0;
}