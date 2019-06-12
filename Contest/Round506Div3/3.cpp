#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll L=1e6;
ll arr1[L];
ll arr2[L];
ll temparr1[L];
ll temparr2[L];

int main()
{
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr1[i]>>arr2[i];
	for(i=0;i<n;i++)
		temparr1[i]=arr1[i];
	for(i=0;i<n;i++)
		temparr2[i]=arr2[i];
	
	sort(temparr1,temparr1+n);
	sort(temparr2,temparr2+n);
	
	ll min=temparr2[0];
	ll max=temparr1[n-1];

	ll maxans=0;
	for(i=0;i<n;i++)
	{
		ll ans=0;
		if(arr1[i]==max)
		{
			ll newmax=temparr1[n-2];
			if(arr2[i]==min)
				ans=temparr2[1]-newmax;
			else
				ans=min-newmax;
		}
		else
		{
			if(arr2[i]==min)
				ans=temparr2[1]-max;
			else
				ans=min-max;
		}
		if(ans>maxans)
			maxans=ans;
	}
	cout<<maxans<<endl;
	return 0;
}