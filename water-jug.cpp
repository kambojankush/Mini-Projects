#include <bits/stdc++.h>

using namespace std;

int A = 0;
int B = 0;

int gcd(int x, int y)
{
	if (x >= y)
	{
		int t = x; x = y; y = t;
	}
	if (x == 0) return y;
	return gcd(y%x, x);
}

bool verify(int a, int b, int l)
{
	return (a >= b && l >= 0 && l <= a && (l%gcd(b,a) == 0));
}

void empty(int *x, int *y, char jar_choice)
{
	if (jar_choice == 'a') *x = 0;
	else if (jar_choice == 'b') *y = 0;
	printf("-> (%d,%d)", *x, *y);
}

void fill(int *x, int *y, char jar_choice)
{
	if (jar_choice == 'a') *x = A;
	else if (jar_choice == 'b') *y = B;
	printf("-> (%d,%d)", *x, *y);
}

void pour(int *x, int *y, char jar_choice)
{
	if (jar_choice == 'a')
	{
		if ( *x + *y <= B)
		{
			*y += *x;
			*x = 0;
		}

		else if (*x + *y > B)
		{
			*x = (*x + *y) - B;
			*y = B;
		}
	}

	else if (jar_choice == 'b')
	{
		if ( *x + *y <= A)
		{
			*x += *y ;
			*y = 0;
		}

		else if (*x + *y > A)
		{
			*y = (*x + *y) - A;
			*x = A;
		}
	}

	printf("-> (%d,%d)", *x, *y);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int l;
	cin >> A >> B >> l;

	if (verify(A, B, l))
	{
		int s = 0, t = 0;
		printf("(%d,%d)", s, t);
		while(s != l)
		{
			fill(&s,&t,'b');
			while(t != 0)
			{
				if (s == A) empty(&s, &t, 'a');
				pour(&s, &t, 'b');
			}
		}
	}
	else cout << "Not Possible";
	 
	fclose(stdout);
	fclose(stdin);
	return 0;
}