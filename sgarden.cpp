#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 1000000007

using namespace std;

int GCD(int a, int b)
{
	while(1)
	{
		if(a==0)
			return b;
		b = b%a;
		if(b==0)
			return a;
		a = a%b;
	}
}

long long LCM(long long a, int b)
{
	int gcd = GCD(a, b);
	return (a/gcd)*b;
}

void tester()
{
	long long lcm = 1;
	for(int i=1; i<=40; i++)
		lcm = LCM(lcm, i)%mod;
	cout<<lcm<<endl;
}

int main()
{
//	tester();
	int t, n, cur, count;
	int a[100100];
	int prod[100100], prodsize;
	long long lcm;
	cin>>t;
	while(t--)
	{
		cin>>n;
		prodsize = 0;
		int done[100100] = {0};
		for(int i=1; i<=n; i++)
			scanf("%d", a+i);
		lcm = 1;
		for(int i=1; i<=n; i++)
		{
			count = 0;
			cur = i;
			while(!done[cur])
			{
				done[cur] = 1;
				cur = a[cur];
				count++;
			}
			if(count > 1)
			{
				for(int j=0; j<prodsize; j++)
					count /= GCD(prod[j], count);
				if(count > 1)
				{
					prod[prodsize++] = count;
					lcm = (lcm*count)%mod;
				}
			}
		}
//		for(int i=0; i<prodsize; i++)
//			cout<<prod[i]<<" ";
//		cout<<endl;
		cout<<lcm<<endl;
	}
	return 0;
}
