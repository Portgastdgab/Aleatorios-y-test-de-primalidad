#include <iostream>
#include <NTL/ZZ.h>

#define N 10000001

bool criba[N];

using namespace std;
using namespace NTL;

// precálculo de los números primos en O(n*log(log(n)))
void preCriba()
{
	for (int i = 2; i * i <= N; i++)
	{
		if (!criba[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				criba[j] = true;
			}
		}
	}
}

// test de primalidad utilizando criba en O(1)
bool esPrimo(int n)
{
	return !criba[n];
}

int main()
{

	preCriba();

	for (int i = 11; i <= 50; i += 4)
	{
		//ahora puede saber si un número es primo en O(1)
		// 4n + 3
		if (esPrimo(i))
		{
			cout << i << " es primo\n";
		}
		else
		{
			cout << i << " no es primo\n";
		}
		// 4n + 1
		i += 2;
		if (esPrimo(i))
		{
			cout << i << " es primo\n";
		}
		else
		{
			cout << i << " no es primo\n";
		}
	}
	return 0;
}
