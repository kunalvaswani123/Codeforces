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
const ll L = 5e5 + 5;
ll arr[L];
ll ans[100];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,x;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	for(i=n-1;i>=0;i--)
 	{
 		if(arr[i] == 42)
 			ans[42]++;
 		else if(arr[i] == 23)
 		{
 			if(ans[42] > 0)
 				ans[42]--, ans[23]++;
 		}
 		else if(arr[i] == 16)
 		{
 			if(ans[23] > 0)
 				ans[23]--, ans[16]++;
 		}
 		else if(arr[i] == 16)
 		{
 			if(ans[23] > 0)
 				ans[23]--, ans[16]++;
 		}
 		else if(arr[i] == 15)
 		{
 			if(ans[16] > 0)
 				ans[16]--, ans[15]++;
 		}
 		else if(arr[i] == 8)
 		{
 			if(ans[15] > 0)
 				ans[15]--, ans[8]++;
 		}
 		else
 		{
	 		if(ans[8] > 0)
 				ans[8]--, ans[4]++;	
 		}	
 	}
 	ans[4] *= 6;
 	cout << n - ans[4] << endl;
	return 0;
}