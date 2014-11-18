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

int ls[31];

int level(int x)
{
	int pos = upper_bound(ls, ls+31, x) - ls;
//	printf("Level of %d: %d\n", x, pos);
	return pos%2;
}

int main()
{	
	int T;
	for(int i=0; i<31; i++)
		ls[i] = 1<<i;
//	print_array(ls, 31);
	int root = 1;		//BLACK
	scanf("%d", &T);
	while(T--)
	{
		char s[10];
		int x, y;
		scanf("%s", s);
		if(s[1] == 'i')
			root = !root;
		else
		{
			int cnt[2] = {0};
			scanf("%d%d", &x, &y);
			while(x != y)
			{
				if(x > y)
				{
					cnt[level(x)]++;
					x >>= 1;
				}
				if(y > x)
				{
					cnt[level(y)]++;
					y >>= 1;
				}
			}
			cnt[level(x)]++;
			if(s[1] == 'b')
				printf("%d\n", cnt[root]);
			else
				printf("%d\n", cnt[!root]);
		}
	}
	return 0;
}

