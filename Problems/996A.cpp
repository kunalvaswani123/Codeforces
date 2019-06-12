#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[10]={100,20,10,5,1};
int main()
{
	ll n;
	cin>>n;
	int i=0;
	ll ans=0;
  	while(n>0)
  	{
  		if(n/arr[i]!=0)
  		{
  			ans+=n/arr[i];
	  		n=n%arr[i];
  		}
  		else
  			i++;
  	}
  	cout<<ans<<endl;
  	return 0;
}