#include "RSA.h"

#ifdef USE_CRYPTOPP
namespace ZFGC::RSA {
	CryptoPP::AutoSeededRandomPool random_generator;
	RSAParams GenerateRSAParams(size_t key_size) 
	{
		CryptoPP::InvertibleRSAFunction rsaFunc;
		rsaFunc.GenerateRandomWithKeySize(random_generator, key_size);
		auto pub = CryptoPP::RSA::PublicKey(rsaFunc);
		auto priv = CryptoPP::RSA::PrivateKey(rsaFunc);
		return RSAParams(pub.GetModulus(), pub.GetPublicExponent(), priv.GetPrivateExponent() );
	}
	BigInteger RSAParams::Encrypt(const BigInteger& plainText)
	{
		return BigInt::A_exp_B_mod_C(plainText, e, N);
	}
	BigInteger RSAParams::Decrypt(const BigInteger& cipherText)
	{
		return BigInt::A_exp_B_mod_C(cipherText, d, N);
	}
}
#endif