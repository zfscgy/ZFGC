#include "../configs.h"
#include "BigInteger.h"

#ifdef USE_CRYPTOPP
#include "cryptopp/cryptlib.h"
#include "cryptopp/rsa.h"
#include "cryptopp/osrng.h"
#endif // CRYPTOPP



namespace ZFGC::RSA
{
	class RSAParams {
		BigInteger N;
		BigInteger e;
		BigInteger d;
	public:
		RSAParams(const BigInteger& _N, const BigInteger& _e, const BigInteger& _d) : N(_N), e(_e), d(_d) {}
		BigInteger Encrypt(const BigInteger& plainText);
		BigInteger Decrypt(const BigInteger& cipherText);
	};
	RSAParams GenerateRSAParams(size_t key_size);
}