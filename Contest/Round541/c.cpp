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
ll arr[200];
ll ans[200];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin>>arr[i];
 	sort(arr, arr+n);
 	ans[0] = arr[0];
 	ll count = 1;
 	for(i=1;i<=n/2;i++)
 	{
 		if(n%2 == 0 && i == n/2)
 		{
 			ans[i] = arr[count];
 			continue;
 		}
 		ans[i] = arr[count];
 		ans[n-i] = arr[count+1];
 		count += 2;
 	}
 	for(i=0;i<n;i++)
 		cout << ans[i] << ' ';
 	cout << endl;
	return 0;
}