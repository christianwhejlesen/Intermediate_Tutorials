//Tutorials for Chili's "Intermediate C++ Game Programming DirectX" course
//https://wiki.planetchili.net/index.php/Main_Page
//
// Tutorial 3

#include <conio.h>

int fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

void print(const char* s)
{
	while (*s != 0)
	{
		_putch(*s);
		s++;
	}
}

int strlength(const char* s)
{
	int i = 0;
	for (; *s != 0; s++) {
		i++;
	}
	return i;
}

int str2int(char* s)
{
	int sum = 0;
	for (; *s >= '0' && *s <= '9'; s++)
	{
		// shift entire sum left by one decimal place
		sum *= 10;
		// add in new lowest digit
		sum += *s - '0';
	}
	return sum;
}

void read(char* buf, const int maxsize)
{
	const char* const pEnd = buf + maxsize - 1;
	for (char c = _getch(); c != 13 && buf < pEnd; c = _getch(), buf++)
	{
		_putch(c);
		*buf = c;
	}
	*buf = 0;
}

void revstr(char* buf, int size)
{
	char temp;
	char* pEnd = buf + size - 1;

	for (; buf < pEnd; buf++, pEnd--)
	{
		temp = *buf;
		*buf = *pEnd;
		*pEnd = temp;
	}
}

int int2str(int val, char* buf)
{
	int mod = 10;
	int i = 0;

	for (; val > 0; buf++)
	{
		*buf = (val % mod) + 48;
		val -= val % mod;
		val /= mod;
		i++;
	}
	*buf = 0;
	return i;
}

int main()
{
	const int size = 69;
	char ans[size];
	char i2s[size];
	//GIT TEST
	print("Enter Fibonacci number: ");
	read(ans, size);

	revstr(i2s, int2str(fib(str2int(ans)), i2s));

	print("\tFibo num: ");
	print(i2s);

	while (!_kbhit());
	return 0;
}