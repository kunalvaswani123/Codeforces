#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
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
const ll L = 1e5 + 5;
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,a,b;
 	cin >> a >> b;
 	vector<ll>as;
 	as.pb(0);
	for(i=1;i<1e5;i++) 	   
		as.pb(i+as[i-1]);
	ll v = lower_bound(as.begin(),as.end(),a+b)-as.begin();
	if(as[v]!=a+b)
		v--;
	ll c = a + b - as[v];
	if(a >= b)
		a -= c;
	else
		b -= c;
	vector<ll>n1,n2;
	ll t = v;
	while(a > t)
	{
		if(t != 0)
			n1.pb(t);
		arr[t] = 1;
		a = a - t;
		t--;
	}
	arr[a] = 1;
	if(a != 0)
		n1.pb(a);
	for(i=1;i<=v;i++)
	{
		if(arr[i] == 0)
			n2.pb(i);
	}
	if(n1.size() == 0)
		cout << 0 << endl;
	else
	{
		cout << n1.size() << endl;
		for(i=0;i<n1.size();i++)
			cout << n1[i] << ' ';
		cout << endl;
	}
	if(n2.size() == 0)
		cout << 0 << endl;
	else
	{
		cout << n2.size() << endl;
		for(i=0;i<n2.size();i++)
			cout << n2[i] << ' ';
		cout << endl;
	}
	return 0;
}