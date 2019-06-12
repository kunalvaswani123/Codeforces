#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
const ll L = 1e6;
ll si[L];
ll p[L];
vector<ll>pri;
void soe()
{
	ll i,j;
	for(i=2;i<L;i++)
	{
		if(s[i] == 0)
		{
			pri.pb(i);
			for(j=i;j<L;j+=i)
				si[i] = 1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,n,x;
	cin >> n;
	ll one = 0;
	ll two = 0;
	for(i=0;i<n;i++)
	{
		cin >> x;
		if(x == 1)
			one++;
		else if(x == 2)
			two++;
	}
	pri.pb(0);
	soe();
	vector<ll>ans;
	for(i=1;i<pri.size();i++)
	{
		ll dif = pri[i] - pri[i - 1];
		while(dif > 0)
		{
			
		}
	}
	return 0;
}