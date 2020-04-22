# Lightweight-RSA-TESTING-ONLY-

### RSA::CONSTRUCTOR (p , q , e )

    RSA rsa(277, 117, 73);

    int message = 14;

    int cipher = rsa.encrypt(message, rsa.pubKey);
    
    int msg = rsa.decrypt(cipher, rsa.prvKey);
