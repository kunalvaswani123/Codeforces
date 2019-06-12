#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[1000];
multiset<int>prices;
int main()
{
	int n,B,i;
	cin>>n>>B;
	for(i=0;i<n;i++)
		cin>>arr[i];
	ll evenc=0;
	ll oddc=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]%2)
			oddc++;
		else
			evenc++;
		if(evenc==oddc&&i!=n-1)
			prices.insert(abs(arr[i+1]-arr[i]));
	}
	multiset<int>::iterator itr;
	int cuts=0;
	for(itr=prices.begin();itr!=prices.end();itr++)
	{
		B-=*itr;
		if(B>=0)
			cuts++;
		else
			break;
	}
	cout<<cuts<<endl;
	return 0;
}