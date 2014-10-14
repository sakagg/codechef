#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

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

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131    , 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281    , 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457    , 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641    , 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827    , 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1001};

int gcount[1000100];

int main()
{
	int T;
	int a[100100];
	LL ans;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		ans = 0;
		memset(gcount, 0, sizeof(gcount));
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", a+i);
			int count[170] = {0};
			for(int j=0; j<168; j++)
				while(a[i]%p[j] == 0)
				{
					count[j]++;
					a[i]/=p[j];
				}
			if(a[i]>1000)
				gcount[a[i]] = 1;
			for(int j=0; j<168; j++)
				gcount[p[j]] = max(gcount[p[j]], count[j]);
		}
		for(int i=2; i<1000001; i++)
			ans += gcount[i];
		cout<<ans<<endl;
	}
	return 0;
}

