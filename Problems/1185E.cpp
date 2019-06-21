#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
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
const ll L = 2e3 + 5;
ll arr[L][L];
vector<pair<pll,pll> >ans;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll t,n,m;
 	cin >> t;
 	while(t--)
 	{	
 		cin >> n >> m;
 		ans.clear();
 		ll i,j;
 		string s;
 		for(i=1;i<=n;i++)
 		{
 			cin >> s;
 			for(j=1;j<=m;j++)
 				arr[i][j] = s[j-1];
 		}
 		ll f = 0;
 		ll ch = 0;
 		for(char it='z';it>='a';it--)
 		{
 			pll st = {0,0}, et = {0,0};
 			pll temp = {0,0};
 			if(f == 1)
 				break;
 			ll b = 0;
 			for(i=1;i<=n;i++)
 			{
 				for(j=1;j<=m;j++)
 				{
 					if(arr[i][j] == it)
 					{
 						st = {i,j}, b = 1;
 						break;
 					}
 					if(arr[i][j] == '*')
 						temp = {i,j};
 				}
 				if(b == 1)
 					break;
 			}
 			if(st == pll {0,0} && ch == 0)
 				continue;
 			else if(st == pll {0,0})
 			{
 				ans.pb({temp,temp});
 				continue;
 			}
 			else
 				ch = 1;
 			ll f2 = 0;
 			j = st.se;
 			for(i=st.fi+1;i<=n;i++)
 			{
 				if(arr[i][j] == '.')
 					break;
 				if(arr[i][j] == it)
 				{
 					f2 = 1;
 					et = {i,j};
 				}
 			}
 			i = st.fi;
 			for(j=st.se+1;j<=m;j++)
 			{
 				if(arr[i][j] == '.')
 					break;
 				if(arr[i][j] == it)
 				{
 					if(f2 == 1)
 					{
 						f = 1;
 						break;
 					}
 					else
 						f2 = 2, et = {i,j};
 				}
 			}
 			if(f2 == 0)
 				et = st, f2 = 1;
 			if(f2 == 1)
 			{
 				for(i=st.fi;i<=et.fi;i++)
 				{
 					if(arr[i][st.se]!='*'&&arr[i][st.se]!=it)
 						f = 1;
 					arr[i][st.se] = '*';
 				}
 			}
 			else if(f2 == 2)
 			{
 				for(j=st.se;j<=et.se;j++)
 				{
 					if(arr[st.fi][j]!='*'&&arr[st.fi][j]!=it)
 						f = 1;
 					arr[st.fi][j] = '*';
 				}
 			}
 			ans.pb({st,et});
 		}
 		for(i=1;i<=n;i++)
 			for(j=1;j<=m;j++)
 			{
 				if(arr[i][j]!='.'&&arr[i][j]!='*')
 					f = 1;
 			}
 		if(f == 1)
 			cout << "NO" << endl;
 		else
 		{
 			reverse(all(ans));
 			cout << "YES" << endl;
 			cout << sz(ans) << endl;
 			for(i=0;i<sz(ans);i++)
 			{
 				cout << ans[i].fi.fi << ' ' << ans[i].fi.se << ' ';
 				cout << ans[i].se.fi << ' ' << ans[i].se.se << endl;
 			}
 		}
 	}
	return 0;
}