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
const ll L = 1e4;
ll arr[L];
ll pref[L];
map<ll, set<pll> >m;
map<ll, set<pll> > :: iterator it;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	pref[0] = arr[0];
 	for(i=1;i<n;i++)
 		pref[i] = arr[i] + pref[i - 1];
 	
 	ll l, r;
 	ll ans = -1e12;
 	vector<pll> vals;
 	for(l=0;l<n;l++)
 	{
 		for(r=l;r<n;r++)
 		{
 			ll sum;
 			if(l == 0)
 				sum = pref[r];
 			else
 				sum = pref[r] - pref[l - 1];
 			m[sum].insert(mp(r, l));
 		}
 	}
 	for(it=m.begin();it!=m.end();it++)
 	{
 		set<pll>temp = (*it).se;
 		set<pll> :: iterator it2;
 		ll prev = -1;
 		ll count = 0;
 		vector<pll> temp2;
 		for(it2=temp.begin();it2!=temp.end();it2++)
 		{
 			ll r1 = (*it2).fi;
 			ll l1 = (*it2).se;
 			if(l1 > prev)
 			{
 				temp2.pb(mp(l1 + 1, r1 + 1));
 				prev = r1, count++;
 			}
 		}
 		if(count > ans)
 		{
 			vals = temp2;
 			ans = count;
 		}
 	}
 	cout << vals.size() << endl;
 	for(i=0;i<vals.size();i++)
 		cout << vals[i].fi << ' ' << vals[i].se << endl;
	return 0;
}