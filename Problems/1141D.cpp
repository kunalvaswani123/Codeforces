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
 	ll i, n;
 	cin >> n;
 	string l, r;
 	cin >> l >> r;
 	multiset<pair<char,ll> >le;
 	multiset<pair<char,ll> >ri;
 	deque<ll>cl;
 	deque<ll>cr;
 	vector<pll>ans;
 	for(i=0;i<n;i++)
 	{
 		if(l[i] == '?')
 			cl.pb(i+1);
 		else
	 		le.insert(mp(l[i], i+1));
 	}
 	for(i=0;i<n;i++)
 	{
 		if(r[i] == '?')
 			cr.pb(i+1);
 		else
	 		ri.insert(mp(r[i], i+1));
 	}
 	multiset<pair<char,ll> >::iterator it1;
 	multiset<pair<char,ll> >::iterator it2;
 	it1 = le.begin();
 	it2 = ri.begin();
 	while(1)
 	{
 		if(it1 == le.end() || it2 == ri.end())
 		{
 			break;
 		}
 		pair<char,ll>p1 = *it1;
 		pair<char,ll>p2 = *it2;
 		// cout << p1.fi << ' ' << p2.fi << endl;
 		if(p1.fi == p2.fi)
 		{
 			ans.pb(mp(p1.se, p2.se));
 			it1++, it2++;
 		}
 		else if(p1.fi < p2.fi)
 		{
 			it1++;
 			if(!cr.empty())
 			{
 				ans.pb(mp(p1.se, cr.back()));
 				cr.pop_back();
 			}
 		}
 		else if(p1.fi > p2.fi)
 		{
 			it2++;
 			if(!cl.empty())
 			{
 				ans.pb(mp(cl.back(), p2.se));
 				cl.pop_back();
 			}
 		}
 	}
 	if(it1 == le.end())
 	{
 		while(!cl.empty() && it2 != ri.end())
 		{
 			ans.pb(mp(cl.back(), (*it2).se));
 			cl.pop_back();
 			it2++;
 		}
 	}
 	if(it2 == ri.end())
 	{
 		while(!cr.empty() && it1 != le.end())
 		{
 			ans.pb(mp((*it1).se, cr.back()));
 			cr.pop_back();
 			it1++;
 		}
 	}
 	while(!cl.empty() && !cr.empty())
 	{
 		ans.pb(mp(cl.back(), cr.back()));
 		cl.pop_back();
 		cr.pop_back();
 	}
 	cout << ans.size() << endl;
 	for(i=0;i<ans.size();i++)
 		cout << ans[i].fi << ' ' << ans[i].se << endl;
	return 0;
}