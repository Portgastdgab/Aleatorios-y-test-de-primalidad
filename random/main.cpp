#include <iostream>
#include <time.h>
#include <NTL/ZZ.h>
#include <cmath>

using namespace std;
using namespace NTL;

ZZ mod(ZZ dividend, ZZ divisor)
{
	const ZZ quotient = dividend / divisor;
	const ZZ remainder = dividend - (quotient * divisor);
	return (remainder < 0) ? remainder + divisor : remainder;
}

class BBS
{
	//code made by https://github.com/OverStruck/blum-blum-shub-prbg
	//reference: http://cacr.uwaterloo.ca/hac/about/chap5.pdf
	// 5.5.2 Blum-Blum-Shub pseudorandom bit generator

private:
	ZZ p, q, n, x0;

public:
	BBS(ZZ p, ZZ q, ZZ seed)
	{
		this->p = p;
		this->q = q;
		this->x0 = seed;
		this->n = p * q;
	}
	// ZZ getRandBit()
	// {
	// 	return mod(this->getRandNum(),2);
	// }
	ZZ getRandNum()
	{
		ZZ nextRandNum = mod((this->x0 * this->x0), this->n);
		this->x0 = nextRandNum;
		return nextRandNum;
	}
};

ZZ binary_exponentiation(unsigned long long power)
{
	ZZ two = ZZ(2);
	two <<= power;

	return two;
}

ZZ RANDBIGINTEGER(const unsigned long long BITS)
{
	const unsigned long long TIME = time(NULL);
	const ZZ MIN = binary_exponentiation(BITS - 1);
	const ZZ MAX = binary_exponentiation(BITS);
	unsigned long long position = TIME;
	return ZZ(1);
}

// ZZ getPrimeByRange(const ZZ MIN, const ZZ MAX)
// {
// 	return;
// }

int main()
{
	//Los dos números primos, p y q, deben ser ambos congruentes a 3 (mod 4) (esto asegura que cada residuo cuadrático posee una raíz cuadrada que también es un residuo cuadrático) y mcd(φ(p-1), φ(q-1)) debe ser pequeña (esto hace que la longitud del ciclo sea extensa)
	const ZZ P = ZZ(11);
	const ZZ Q = ZZ(19);
	const ZZ seed = ZZ(6);

	BBS numberGen(P, Q, seed);

	const unsigned iterations = 100;
	//generate 6 random numbers
	for (int i = 0; i < iterations; i++)
	{
		cout << numberGen.getRandNum() << " ";
	}

	return 0;
}

bool esPrimo(ZZ n)
{
	for (ZZ i = ZZ(3); i * i <= n; i += 2)
	{
		cout << i << endl;
		if (module(n, i) == 0)
		{
			return false;
		}
	}
	return true;
}

// mersene twister it is not suited for cryptographic code, because one only needs to observe 624 iterates to predict all future ones
