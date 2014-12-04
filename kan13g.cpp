#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++)
	{
		printf("Case %d:\n", t+1);
		int n, m;
		SI(n); SI(m);
		double num;
		int a[n];
		for(int i=0; i<n; i++)
		{
			scanf("%lf", &num);
			a[i] = num*100;
		}
		sort(a, a+n);
//		print_array(a, n);
		for(int M=0; M<m; M++)
		{
			printf("Scenario %d:\n", M+1);
			int tot;
			scanf("%lf", &num);
			tot = num*100;
			for(int i=n-1; i>=0 && tot>0; i--)
				if(a[i]<=tot)
				{
					if(a[i]>=100)
						printf("%d", a[i]/100);
					else
						printf("%.2lf", a[i]/100.0);
					printf(" %d\n", tot/a[i]);
					tot %= a[i];
				}
		}
	}
	return 0;
}

