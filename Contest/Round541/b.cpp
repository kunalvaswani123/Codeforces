#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
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
 	set<pll> as;
 	ll n, x, y;
 	as.insert(mp(0,0));
 	cin >> n;
 	while(n--)
 	{
 		cin >> x >> y;
 		as.insert(mp(x, y));
 	}   
 	ll count = 0;
 	set<pll> :: iterator it;
 	ll pval1 = 0, pval2 = 0;
 	if(as.size() == 1)
 	{
 		cout << 1 << endl;
 		return 0;
 	}
 	it=as.begin();
 	it++;
 	for(;it!=as.end();it++)
 	{	
 		ll val1 = (*it).fi;
 		ll val2 = (*it).se;
 		if(min(val1,val2) >= max(pval1,pval2))
 			count += min(val1,val2) - max(pval1,pval2) + 1;
 		if(val1 == val2)
 			pval1 = val1 + 1, pval2 = val2 + 1;
 		else
 		{
	 		pval1 = val1;
	 		pval2 = val2;
 		}
 	}
 	cout << count << endl;
	return 0;
}