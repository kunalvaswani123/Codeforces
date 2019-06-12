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
ll arr[2 * L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	vector<ll>s1;
 	vector<ll>s2;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	sort(arr, arr + n);
 	ll f = 0;
 	s1.pb(arr[0]);
 	for(i=1;i<n;i++)
 	{
 		if(arr[i] == arr[i-1])
 		{
 			if(f == 0)
 				s2.pb(arr[i]), f = 1;
 			else
 			{
 				cout << "NO" << endl;
 				return 0;
 			}
 		}
 		else
 			s1.pb(arr[i]), f = 0;
 	}
 	reverse(s2.begin(), s2.end());
	cout << "YES" << endl;
 	cout << s1.size() << endl;
 	for(i=0;i<s1.size();i++)
 		cout << s1[i] << ' ';
 	cout << endl;
 	cout << s2.size() << endl;
 	for(i=0;i<s2.size();i++)
 		cout << s2[i] << ' ';
 	cout << endl;
	return 0;
}