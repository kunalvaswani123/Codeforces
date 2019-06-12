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
const ll L = 1e5 + 5;
ll arr[2 * L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,k;
 	string s;
 	cin >> n >> k;
 	for(i = 0; i < n; i++)
 		cin >> arr[i];
 	arr[n + 1] = 0;
 	cin >> s;
 	s[n + 1] = '1';
 	ll ans = 0;
 	ll counter;
 	multiset <ll, greater<ll> > as;
 	multiset <ll, greater<ll> > :: iterator it;
 	for(i = 0; i < n + 1; i++)
 	{
 		if(i != 0 && s[i] == s[i-1])
 			as.insert(arr[i]);
 		else
 		{
 			counter = 0;
 			it = as.begin();
 			while(it != as.end() && counter < k)
 			{
 				ans += *it;
 				it++, counter++;
 			}
 			as.clear();
 			as.insert(arr[i]);	
 		}
 	}
 	cout << ans << endl;
	return 0;
}