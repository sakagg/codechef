#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long p[20][2];
	p[0][0] = 0;
	p[0][1] = 1 ;
	p[1][0] = 18;
	p[1][1] = 
	for(int i=1; i<20; i++)
	{
		p[i][0] = 0;
		p[i][1] = p[i-1][1]*;
		long long tmp = p[i][1] / 10;
		for(int j=0; j<i; j++)
		{
			p[i][0] += tmp;
			tmp = (tmp/10)*9;
		}
		p[i][0] += tmp;
//		cout<<p[i][0]<<" / "<<p[i][1]<<endl;
	}

	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int dig = 0;
		long long tmp = n;
		while(tmp)
		{
			dig++;
			tmp/=10;
		}
		long long numer=0, deno=0;
		numer = p[dig-1][0];
		deno = n;

		for(int i=1; i<=tmp;i++)
			total+=p[i]*probability(noofdigits(i));
		cout<<total;
	}
	return 0;
}
