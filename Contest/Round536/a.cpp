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
char arr[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n;
 	cin>>n;
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 			cin>>arr[i][j];
 	}
 	ll count=0;
	for(i=1;i<n-1;i++)
 	{
 		for(j=1;j<n-1;j++)
 		{
 			if(arr[i][j]=='X')
 			{
 				if(arr[i-1][j-1]=='X')
 				{
 					if(arr[i-1][j+1]=='X')
 					{
 						if(arr[i+1][j-1]=='X')
 						{
 							if(arr[i+1][j+1]=='X')
 								count++;
 						}
 					}
 				}
 			}
 		}
 	}
 	cout << count << endl;
	return 0;
}