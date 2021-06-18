#include <iostream>
#include <vector>
#include <math.h> /* sqrt */

using namespace std;

unsigned myModule(unsigned dividend, unsigned divisor)
{
	const unsigned quotient = dividend / divisor;
	const unsigned remainder = dividend - (divisor * quotient);
	return remainder;
}

unsigned six_complement(unsigned &number)
{
	return 6 - number;
}

unsigned nearest_multiple_of_six(unsigned number)
{
	const unsigned quotient = number / 6;
	unsigned remainder = number - (quotient * 6);

	if (remainder <= 1)
	{
		return quotient * 6;
	}

	const unsigned nearestSix = remainder + six_complement(remainder);
	return nearestSix;
}

static unsigned squareRoot(unsigned &number)
{
	sizeof(number);
	return sqrt(number);
}

bool isPrime(vector<unsigned> &primes, unsigned &number)
{
	for (vector<unsigned>::iterator it_ptr = primes.begin(); *it_ptr < squareRoot(number) + 1; it_ptr++)
	{
		if (myModule(number, *it_ptr) == 0)
		{
			return false;
		}
	}
	return true;
}

void eratosthenes_sieve(vector<unsigned> &primes, unsigned start, unsigned end)
{
	unsigned previous;
	unsigned back;
	for (unsigned i = nearest_multiple_of_six(start); i < end; i += 6)
	{
		previous = i - 1;
		back = i + 1;
		if (isPrime(primes, previous))
		{
			primes.push_back(previous);
		}
		if (isPrime(primes, back))
		{
			primes.push_back(back);
		}
	}
}

void printVector(vector<unsigned> &v)
{
	for (unsigned element : v)
	{
		cout << element << ", ";
	}
	cout << endl;
}

int main()
{
	unsigned start = 10;
	unsigned end = 100;
	vector<unsigned> primes = {2, 3, 5, 7};

	eratosthenes_sieve(primes, start, end);
	// printVector(primes);

	return 0;
}
