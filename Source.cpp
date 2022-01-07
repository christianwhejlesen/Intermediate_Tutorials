//Tutorials for Chili's "Intermediate C++ Game Programming DirectX" course
//https://wiki.planetchili.net/index.php/Main_Page
//
// Tutorial 4

#include <conio.h>
#include <fstream>
//#include <iostream>

namespace cwh {
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

	int str2int(const char* s)
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

	void strrev(char* buf, int size)
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
} //End cwh namespace

struct Entry
{
	char name[20];
	char value[10];
};

bool menu(Entry* db);
void printValue(const char* s);
void printDB(const Entry* db, int len);
int loadDB(Entry* db, char* filename);


int main()
{
	//Entry db[100];

	//while (menu(db));
	std::ifstream in("tekst.txt");
	if (!in.good())
	{
		cwh::print("File error..");
		while (!_kbhit());
		return -1;
	}



	for (char c = in.get(); in.good(); c=in.get())
	{
		_putch(c);
	}

	std::ofstream out("out.txt", std::ios_base::app);
	cwh::print("\n\n\n\tType something (ESC to end)\n");
	for (char c = _getch(); c != 27; c = _getch())
	{
		if (c==13)
		{
			cwh::print("\n");
		}
		_putch(c);
		out.put(c);
	}



	while (!_kbhit());
	return 0;
}




bool menu(Entry* db)
{
	static int index = 0;
	char c;
	char filename[20];

	cwh::print("\n");
	cwh::print("\t(L)oad  (S)ave  (A)dd  (P)rint  (Q)uit\n");
	do
	{
		c = _getch();

	} while (c != 'l' && c != 's' && c != 'a' && c != 'p' && c != 'q');

	switch (c)
	{
	case 'l':
		cwh::read(filename, 20);
		index = loadDB(db, filename);
		return true;
		break;
	case 's':
		return true;
		break;
	case 'a':
		cwh::print("Name: ");
		cwh::read(db[index].name, 20);
		cwh::print("\nValue: ");
		cwh::read(db[index].value, 10);
		cwh::print("\n");
		index++;
		return true;
		break;
	case 'p':
		printDB(db, index);
		return true;
		break;
	case 'q':
		return false;
		break;
	}

	return false;
}

void printValue(const char* s)
{
	const int val = cwh::str2int(s);
	for (int i = 0; i < val; i++)
	{
		cwh::print("=");
	}
}

void printDB(const Entry* db, int len)
{
	cwh::print("\n");

	for (int i = 0; i < len; i++)
	{
		cwh::print(db[i].name);
		cwh::print("\t|");
		printValue(db[i].value);
		cwh::print("\n");
	}
}

int loadDB(Entry* db, char* filename)
{
	int index = 0;
	std::ifstream inFile(filename);
	if (!inFile)
	{
		cwh::print("\n\n\nFile error...");
	}



	return index;
}