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
ll a,b;
vector<ll>v;
ll ansflag=0;
void rec(ll n)
{
	if(n<b&&n%a!=0)
		ansflag=1;
	else if(n%a==0)
	{
		ll i;
		for(i=0;i<n/a;i++)
			v.pb(a);
	}
	else
	{
		v.pb(b);
		rec(n-b);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,j,n,fno,sno;
	cin>>n>>fno>>sno;
	a=min(fno,sno);
	b=max(fno,sno);
	rec(n);
	if(ansflag==1)
	{
		puts("-1");
		return 0;
	}
	ll st=1;
	for(i=0;i<v.size();i++)
	{
		cout<<st+v[i]-1<<' ';
		for(j=st;j<=st+v[i]-2;j++)
			cout<<j<<' ';
		st=st+v[i];
	}
	cout<<endl;
	return 0;
}