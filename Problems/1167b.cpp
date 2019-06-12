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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n;
 	ll arr[] = {4, 8, 15, 16, 23, 42};
 	map<ll,pll>m;
 	for(i=0;i<6;i++)
 		for(j=i+1;j<6;j++)
 		{
 			pll temp;
 			temp.fi = arr[i];
 			temp.se = arr[j];
 			m[arr[i] * arr[j]] = temp;
 		}
 	ll ans[6];
 	ll val1,val2,val3;
 	cout << "? " << 1 << ' ' << 2 << endl;
 	cin >> val1;
 	cout << "? " << 3 << ' ' << 4 << endl;
 	cin >> val2;
 	cout << "? " << 2 << ' ' << 4 << endl;
 	cin >> val3;
 	ll arr1[2], arr2[2];
 	arr1[0] = m[val1].fi;
 	arr1[1] = m[val1].se;
 	arr2[0] = m[val2].fi;
 	arr2[1] = m[val2].se;
 	for(i=0;i<2;i++)
 		for(j=0;j<2;j++)
 		{
 			if(arr1[i] * arr2[j] == val3)
 			{
 				ans[1] = arr1[i];
 				ans[3] = arr2[j];
 				break;
 			}
 		}
 	ans[0] = (arr1[0] * arr1[1]) / ans[1];
 	ans[2] = (arr2[0] * arr2[1]) / ans[3];
 	cout << "? " << 5 << ' ' << 5 << endl;
 	ll val4;
 	cin >> val4;
 	ans[4] = sqrt(val4);
 	for(i=0;i<6;i++)
 	{
 		ll f = 0;
 		for(j=0;j<5;j++)
 		{
 			if(arr[i] == ans[j])
 			{
 				f = 1;
 				break;
 			}
 		}
 		if(f == 0)
 		{
 			ans[5] = arr[i];
 			break;
 		}
 	}
 	cout << "! ";
 	for(i=0;i<6;i++)
 		cout << ans[i] << ' ';
 	cout << endl;
	return 0;
}