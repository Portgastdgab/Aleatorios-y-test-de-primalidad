#include <iostream>
#include <NTL/ZZ.h>
#include <time.h>

#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
#define QR(a, b, c, d) (             \
	a += b, d ^= a, d = ROTL(d, 16), \
	c += d, b ^= c, b = ROTL(b, 12), \
	a += b, d ^= a, d = ROTL(d, 8),  \
	c += d, b ^= c, b = ROTL(b, 7))

using namespace std;
using namespace NTL;

// string toBinary(ZZ n)
// {
// 	string r;
// 	while (n != 0)
// 	{
// 		r += (n % 2 == 0 ? "0" : "1");
// 		n /= 2;
// 	}
// 	return r;
// }

// double results[40];
// long long global = 0;

void chacha_block(ZZ out[16], ZZ const in[16])
{
	int i;
	ZZ x[16];

	for (i = 0; i < 16; ++i)
		x[i] = in[i];
	// 10 loops × 2 rounds/loop = 20 rounds
	for (i = 0; i < 20; i += 2)
	{
		// Odd round
		QR(x[0], x[4], x[8], x[12]);  // column 0
		QR(x[1], x[5], x[9], x[13]);  // column 1
		QR(x[2], x[6], x[10], x[14]); // column 2
		QR(x[3], x[7], x[11], x[15]); // column 3
		// Even round
		QR(x[0], x[5], x[10], x[15]); // diagonal 1 (main diagonal)
		QR(x[1], x[6], x[11], x[12]); // diagonal 2
		QR(x[2], x[7], x[8], x[13]);  // diagonal 3
		QR(x[3], x[4], x[9], x[14]);  // diagonal 4
	}
	for (i = 0; i < 16; ++i)
	{
		out[i] = x[i] + in[i];
		cout << out[i] << endl;
		// string binary = toBinary(out[i]);
		// double ones = 0;
		// for (long long j = 0; j < binary.size(); j++)
		// 	if (binary[j] == '1')
		// 		ones++;

		// double ceros = binary.size() - ones;

		// double p1 = ones / binary.size();
		// double p2 = ceros / binary.size();
		// cout << "entropy: " << -p1 * log2(p1) - p2 * log2(p2) << endl;
		// results[global];
		// global++;
	}
	cout << endl;
}

ZZ stringToNumber(string str)
{
	ZZ number = conv<ZZ>(str[0]);
	long len = str.length();
	for (long i = 1; i < len; i++)
	{
		number *= 128;
		number += conv<ZZ>(str[i]);
	}

	return number;
}

int main()
{
	ZZ out[32];
	// ZZ in[16];
	ZZ in[16] = {
		stringToNumber("expa"), stringToNumber("nd 3"), stringToNumber("2-by"), stringToNumber("te k"),
		ZZ(time(NULL)), ZZ(time(NULL)), ZZ(time(NULL)), ZZ(time(NULL)),
		ZZ(time(NULL)), ZZ(time(NULL)), ZZ(time(NULL)), ZZ(time(NULL))

	};

	chacha_block(out, in);
	return 0;
}
