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

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		SI(n);
		int a[n];
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		int mx = 0, ind = -1, lastind = -1, len = 0;
		for(int i=0; i<n; i++)
		{
			if(a[i])
				len++;
			else
			{
				len = i - lastind;
				lastind = i;
			}
			if(len > mx)
			{
				mx = len;
				ind = lastind;
			}
		}
		printf("%d\n", ind);
	}
	return 0;
}

