#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(360%n==0)
			putchar('y');
		else
			putchar('n');
		putchar(' ');
		if(n<=360)
			putchar('y');
		else
			putchar('n');
		putchar(' ');
		if((n*(n+1))/2 <= 360)
			putchar('y');
		else
			putchar('n');
		putchar('\n');
	}
	return 0;
}
