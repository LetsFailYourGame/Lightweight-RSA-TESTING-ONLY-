#include "pch.h"
#include <iostream>

using namespace std;


int main()
{
    RSA rsa(277, 117, 73);

    int message = 14;

    int cipher = rsa.encrypt(message, rsa.pubKey);
    int msg = rsa.decrypt(cipher, rsa.prvKey);

    cout << "Cipher: " << cipher << endl << "Message: " << msg << endl;

    system("pause");
}
