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
ll ce(ll a, ll b)
{
	if(a%b==0)
		return a/b;
	return a/b+1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,m,k,l;
 	cin>>n>>m>>k>>l;
 	if(l+k>m*(n/m) || n<m)
 	{
 		printf("-1\n");
 		return 0;
 	}
 	ll f=n/m;
 	ll g=ce(l+k,m);
 	if(g>n/m)
 	{
 		printf("-1\n");
 		return 0;	
 	}
 	printf("%lld\n",g );

 	// lewc=n;
 	// if(newc<m)
 	// {
 	// 	cout<<-1<<endl;
 	// 	return 0;
 	// }
 	// ll final=newc/m;
 	// ll st=1;
 	// while(st<=final)
 	// {
	 // 	ll total=m*st;
	 // 	if(total>=l)
	 // 	{
	 // 		cout<<st<<endl;
	 // 		return 0;
	 // 	}
	 // 	st++;
 	// }	
 	// cout<<-1<<endl;

	return 0;
}