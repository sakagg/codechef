
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

char s[1000100];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, k;
		SI(n); SI(k);
		scanf("%s", s);
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '#')
			{
				cnt++;
				if(cnt >= k)
				{
					cnt = -1;
					break;
				}
			}
			else
				cnt = 0;
		}
		if(cnt == -1)
			printf("NO\n");
		else
			printf("YES\n");

	}
	return 0;
}
