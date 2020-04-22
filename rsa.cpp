#include "rsa.h"
#include "pch.h"

unsigned long RSA::power(long b, long x, long n)
{
	long z = 1; b = b % n;
	while (x != 0) {
		if (x % 2 != 0) z = (z * b) % n;
		b = (b * b) % n; x = x / 2;
	}
	return z;
}

unsigned int RSA::gcd(unsigned int a, unsigned int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

unsigned int RSA::mul_inv(unsigned int a, unsigned int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

void RSA::print_pubKey(void)
{
	std::cout << "\nPubKey = { " << this->e << ", " << this->n << " }\n" << std::endl;
}
void RSA::print_prvKey(void)
{
	std::cout << "\nPrvKey = { " << this->p << ", " << this->q << ", " << this->d << " }\n" << std::endl;
}

unsigned int RSA::encrypt(unsigned int msg, unsigned int pubKey[])
{
	if (msg < this->n)					
		return this->cipher = power(msg, pubKey[0], pubKey[1]); // msg ^ e mod n -> Pubkey = { e, n }
	else
		return 0;
}
unsigned int RSA::decrypt(unsigned int cipher, unsigned int prvKey[])
{
	return this->message = power(cipher, prvKey[2], prvKey[3]); // cipher ^ d mod n -> PrvKey = { p , q , d , n }
}


