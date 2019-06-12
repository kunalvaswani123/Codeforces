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
ll a[100];
ll n;
bool rec(ll val,ll ind)
{	
	if(ind==n+1&&(val%360==0))
		return true;
	else if(ind==n+1)
		return false;

	if(rec(val+a[ind],ind+1)==true||rec(val-a[ind],ind+1)==true)
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i;
 	cin>>n;
 	for(i=1;i<=n;i++)
 		cin>>a[i];
 	if(rec(0,1)==true)
 		cout<<"YES";
 	else
 		cout<<"NO";
	return 0;
}