#pragma once
#include <iostream>
#include <math.h>

class RSA
{ 
	private:
		unsigned int p, q, e, n, phi_n, d, message = 0, cipher = 0;
	public:

		unsigned long power(long b, long x, long n);
		unsigned int gcd(unsigned int a, unsigned int b);
		unsigned int mul_inv(unsigned int a, unsigned int b);
		unsigned int encrypt(unsigned int msg, unsigned int pubKey[]);
		unsigned int decrypt(unsigned int cipher, unsigned int prvKey[]);

		void print_pubKey(void);
		void print_prvKey(void);

		unsigned int pubKey[2];
		unsigned int prvKey[4];

		RSA(unsigned int p, unsigned int q, unsigned int e)
		{
			this->phi_n = (p - 1) * (q - 1);

			if (gcd(e, (p - 1) * (q - 1)) == 1) { this->e = e; }
			else { std::cout << "GCD(" << e << ", " << phi_n << ") != 1" << std::endl; return; }
				
			this->p = p;
			this->q = q;
			this->n = p * q;
			this->d = mul_inv(this->e, phi_n);
			
			this->pubKey[0] = this->e;
			this->pubKey[1] = this->n;

			this->prvKey[0] = this->p;
			this->prvKey[1] = this->q;
			this->prvKey[2] = this->d;
			this->prvKey[3] = this->n;
		}

		unsigned int get_p(void)	 { return this->p; }
		unsigned int get_q(void)	 { return this->q; }
		unsigned int get_e(void)	 { return this->e; }
		unsigned int get_n(void)	 { return this->n; }
		unsigned int get_d(void)	 { return this->d; }
		unsigned int get_phi_n(void) { return this->phi_n; }

		unsigned int set_p(unsigned int new_p)			{ this->p = new_p; }
		unsigned int set_q(unsigned int new_q)			{ this->q = new_q; }
		unsigned int set_e(unsigned int new_e)			{ this->e = new_e; }
		unsigned int set_n(unsigned int new_n)			{ this->n = new_n; }
		unsigned int set_d(unsigned int new_d)			{ this->d = new_d; }
		unsigned int set_phi_n(unsigned int new_phi_n)	{ this->phi_n = new_phi_n; }
};