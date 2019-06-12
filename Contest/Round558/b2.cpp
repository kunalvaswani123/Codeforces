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
multiset<ll>c;
set<pll>ch;
set<pll>::iterator it;
multiset<ll>::iterator it2;
multiset<ll>::reverse_iterator rit;
const ll L = 1e5 + 5;
ll arr[L];
ll ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,n;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> arr[i];
	for(i=0;i<n;i++)
	{
		it = ch.lower_bound(mp(arr[i],-1));
		if(it == ch.end())
		{
			ch.insert(mp(arr[i],1));
			c.insert(1);			
		}
		else
		{
			pll temp = *it;
			if(temp.fi == arr[i])
			{
				ch.erase(it);
				c.erase(c.find(temp.se));
				ch.insert(mp(arr[i],temp.se+1));
				c.insert(temp.se+1);
			}
			else
			{
				ch.insert(mp(arr[i],1));
				c.insert(1);		
			}
		}
		it2 = c.begin();
		ll val = *it2;
		it2++;
		if(it2 == c.end())
			ans = max(ans,i);		
		else if(val == 1)
		{
			if(c.upper_bound(*it2) == c.end())
				ans = max(ans,i);
		}
		rit = c.rbegin();
		ll val2 = (*rit) - 1;
		rit++;
		if((*rit) == val2 && val == val2)
			ans=max(ans,i);
	}
	cout << ans + 1 << endl;
	return 0;
}