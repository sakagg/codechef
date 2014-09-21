#include <bits/stdc++.h>
#define fu(x) if(x>=n) x-=n;
#define fl(x) if(x<0) x+=n;

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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
	int n, m, num;
	char c;
	int a[100100];
	int start=0, ind;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	while(m--)
	{
		scanf("%c%c%d", &c, &c, &num);
		if(c=='C')
		{
			start += num;
			fu(start);
		}
		else if(c=='A')
		{
			start -= num;
			fl(start);
		}
		else if(c=='R')
		{
			ind = start + num - 1;
			fu(ind);
			printf("%d\n", a[ind]);
		}
//		cout<<start<<endl;
	}
	return 0;
}
