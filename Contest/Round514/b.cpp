#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
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
const ll L=5000;
int arr[L][L];
char arr3[L][L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n,m;
 	cin>>n>>m;
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 			cin>>arr3[i][j];
 	}
 	for(i=0;i<n-2;i++)
 	{
 		for(j=0;j<m-2;j++)
 		{
 			if(arr3[i][j]=='#')
 			{
 				if(arr3[i][j+1]=='.')
 					continue;
 				if(arr3[i][j+2]=='.')
 					continue;
 				if(arr3[i+1][j]=='.')
 					continue;
 				if(arr3[i+1][j+2]=='.')
 					continue;
 				if(arr3[i+2][j]=='.')
 					continue;
 				if(arr3[i+2][j+1]=='.')
 					continue;
 				if(arr3[i+2][j+2]=='.')
 					continue;
 				arr[i][j]=1;
 				arr[i][j+1]=1;
 				arr[i][j+2]=1;
 				arr[i+1][j]=1;
 				arr[i+1][j+2]=1;
 				arr[i+2][j]=1;
 				arr[i+2][j+1]=1;
 				arr[i+2][j+2]=1;
 			}
 		}
 	}
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 		{
 			if(arr3[i][j]=='#'&&arr[i][j]==0)
 			{
 				// cout<<i<<j<<endl;
 				cout<<"NO"<<endl;
 				return 0;
 			}
 			else if(arr3[i][j]=='.'&&arr[i][j]==1)
 			{
 				// cout<<i<<j<<endl;
 				cout<<"NO"<<endl;
 				return 0;	
 			}
 		}
 	}
 	cout<<"YES"<<endl;
	return 0;
}