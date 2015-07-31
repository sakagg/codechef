
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

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char a[110];
		int chef = 0, oth = 0;
		scanf("%s", a);
		for(int i=0; a[i]; i++)
		{
			if(a[i] == '0')
				oth++;
			else
				chef++;
			if(chef>=10 && oth >= 10)
			{
				if(abs(chef-oth) >= 2)
					break;
			}
			else
			{
				if(chef>=11 || oth >=11)
					break;
			}
		}
		if(chef > oth)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
}
