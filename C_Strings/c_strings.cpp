#include <iostream>
#include <conio.h>

void revarr(char* buf, int size)
{
	char temp;
	char* pEnd = buf + size;
	for (; buf < pEnd; buf++, pEnd--)
	{
		temp = *buf;
		*buf = *pEnd;
		*pEnd = temp;
	}
}


int main()
{
	char arr[] = "Christian Wiehl Hejlesen";

	std::cout << "\t";
	std::cout << "\t";
	for (int i = 0; i <= 24; i++)
	{
		std::cout << arr[i];
	}

	revarr(arr, 24);

	for (int i = 0; i <= 24; i++)
	{
		std::cout << arr[i];
	}


	while (!_kbhit());
	return 0;
}