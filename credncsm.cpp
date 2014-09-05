#include <bits/stdc++.h>

using namespace std;

struct t
{
	t *next[10];
};

t *top;

void add(int num)
{
	int start = 1000000000;
	int dig;
	t *st = top;
	while(num)
	{
		dig = num/start;
		num = num%start;
		start /= 10;
		if(st->next[dig] != NULL)
			st = st->next[dig];
		else
		{
			st->next[dig] = new t;
			st = st->next[dig];
			for(int i=0; i<10; i++)

		}
	}
}