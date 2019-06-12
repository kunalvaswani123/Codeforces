#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
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
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll b, k, i;
 	cin >> b >> k;
 	for(i=0;i<k;i++)
 		cin >> arr[i];
 	ll val1 = 1;
 	ll sum = 0;
 	for(i=k-1;i>=0;i--)
 	{
 		sum = (sum + (val1 % 2) * (arr[i] % 2)) % 2;
 		val1 = (val1 * b) % 2;
 	}
 	if(sum % 2 == 0)
 		cout << "even" << endl;
 	else
 		cout << "odd" << endl;
	return 0;
}