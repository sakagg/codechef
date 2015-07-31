
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
		int T1, T2, t1, t2;
		SI(T1); SI(T2); SI(t1); SI(t2);
		if(T1>T2)
		{
			swap(T1, T2);
			swap(t1, t2);
		}
		double ans = 0;
		{
			if(T1 + t1 <= T2)
				ans += double(t1)/T2;
			else if(t1 >= T2)
				ans += (2*T2 - T1)/(T2*2.0);
			else
			{
				int mid = T2 - t1;
				ans += (double(mid)/T1)*(double(t1)/T2);
				ans += (1 - double(mid)/T1)*((t1 + T2 - T1)/(T2*2.0));
			}
		}
		double ans2 = 0;
		{
			if(t2 >= T1)
				ans2 += 0.5;
			else
			{
				int mid = T1-t2;
				ans2 += (double(mid)/T1)*(double(t2)/T1);
				ans2 += (1 - double(mid)/T1)*(t2/(T1*2.0));
			}
		}
		//printf("%lf %lf\n", ans, ans2);
		ans += ans2*double(T1)/T2;
		printf("%0.6lf\n", ans);
	}
	return 0;
}
