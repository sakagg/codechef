#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL gcd(LL a, LL b)
{
	LL tmp;
	while(b)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
// Uncomment to use TestCases
/*
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n;
	long long ans;
	LL den = 720;
	cin>>n;
	if(n<13)
	{
		printf("0\n");
		return 0;
	}
	n-=13;
	n/=2;
	ans = 1;
	int a[6];
	for(int i=0; i<6; i++)
		a[i] = n-i+6;
	for(int i=0; i<6; i++)
	{
		LL g = gcd(a[i], den);
		a[i]/=g;
		den/=g;
		ans *= a[i];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}

