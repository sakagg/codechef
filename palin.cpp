
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

char a[1000100];

void increment(char *a, int len)
{
	for(int i=len-1; i>=0; i--)
		if(a[i]!='9')
		{
			a[i]++;
			break;
		}
		else
			a[i] = '0';
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", a);
		int len = strlen(a);
		int i;
		for(i=0; i<len; i++)
			if(a[i]!='9')
				break;
		if(i == len)
		{
			printf("1");
			for(int j=1; j<len; j++)
				printf("0");
			printf("1\n");
			continue;
		}
		if(len%2 == 0)
		{
			for(i=len/2 - 1; i>=0 && a[i]==a[len-1-i]; i--);
			
			if(i==-1 || a[i]<a[len-i-1])
				increment(a, len/2);
			
			a[len/2] = 0;
			printf("%s", a);
			reverse(a, a+len/2);
			printf("%s\n", a);
			continue;
		}
		else
		{
			for(i=len/2 - 1; i>=0 && a[i]==a[len-i-1]; i--);

			if(i==-1 || a[i]<a[len-i-1])
				increment(a, len/2+1);

			a[len/2 + 1] = 0;
			printf("%s", a);
			a[len/2] = 0;
			reverse(a, a+len/2);
			printf("%s\n", a);
		}
	}
	return 0;
}
