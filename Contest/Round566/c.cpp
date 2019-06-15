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
vector< pair<pair<string,string>, pair<string,string> > >ans;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	multiset<pair<string,string> >s1;
 	multiset<pair<string,string> >s2;
 	map<char,multiset<pair<ll,string> > >m1;
 	multiset<pair<ll,string> >::iterator it;
 	map<ll,string>m2;
 	ll i,j,n;
 	cin >> n;
 	string s;
 	multiset<pair<ll,string> > left;
 	for(i=0;i<n;i++)
 	{
		char e;
 		cin >> s;
	 	ll c = 0;
	 	for(j=0;j<sz(s);j++)
	 	{
	 		if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
	 			c++, e = s[j];
	 	}
	 	if(sz(m1[e]) == 0)
	 	{
	 		left.insert(mp(c,s));
	 		m1[e].insert(mp(c,s));
	 	}
	 	else
	 	{
	 		it = m1[e].lower_bound(mp(c,""));
	 		if(it == m1[e].end() || (*it).fi != c)
	 		{
	 			left.insert(mp(c,s));
		 		m1[e].insert(mp(c,s));
	 		}
	 		else
	 		{
	 			s1.insert(mp((*it).se, s));
	 			if(left.find(mp(c,(*it).se)) != left.end())
	 				left.erase(left.find(mp(c,(*it).se)));
	 			m1[e].erase(it);
	 		}
	 	}
 	}
 	multiset<pair<ll,string> > :: iterator it2;
 	multiset<pair<ll,string> > :: iterator pit;
 	it2 = left.begin();
 	pit = it2;
 	if(pit!=left.end())
 	{
	 	it2++;
	 	for(;it2!=left.end();)
	 	{
	 		if(pit == left.end())
	 			break;
	 		if((*pit).fi == (*it2).fi)
	 		{
	 			s2.insert(mp((*pit).se,(*it2).se));
	 			pit = it2;
	 			pit++;
	 			if(pit == left.end())
	 				break;
	 			else
	 				it2 = pit, it2++;
	 		}
	 		else
	 		{
	 			it2++;
	 			pit++;
	 		}
	 	}
 	}
 	multiset<pair<string,string> > :: iterator it3;
 	multiset<pair<string,string> > :: iterator it4 = s2.begin();
	vector<pair<string,string> >last;
	for(it3=s1.begin();it3!=s1.end();it3++)
	{
		if(it4 == s2.end())
			last.pb(*it3);
		else
		{
			ans.pb(mp(*it4,*it3));
			it4++;
		}
	}
	ll temp = sz(last) / 2;
	for(i=0;i<temp*2;i+=2)
		ans.pb(mp(last[i],last[i+1]));
	cout << sz(ans) << endl;
	for(i=0;i<sz(ans);i++)
	{
		cout << ans[i].fi.fi << ' ' << ans[i].se.fi << endl;
		cout << ans[i].fi.se << ' ' << ans[i].se.se << endl;
	}
	return 0;
}