#include "../Common/RSA.h"

using namespace ZFGC;

int main()
{
	int passed = 0;
	int unpassed = 0;
	std::cout << "Test RSA Module" << std::endl;
	std::cout << "Test RSA Encryption & Decryption: " << std::endl;
	RSA::RSAParams rsaParams = RSA::GenerateRSAParams(1024);
	BigInteger msg = BigInt::FromBytesArray(RandomBytes(1024 / 8));
	BigInteger cipherText = rsaParams.Encrypt(msg);
	BigInteger plainText = rsaParams.Decrypt(cipherText);
	std::cout << "Raw msg: " << BigInt::ToBytesArray(msg).ToHex() << std::endl;
	std::cout << "Cipher Text: " << BigInt::ToBytesArray(cipherText).ToHex() << std::endl;
	std::cout << "Decrypted: " << BigInt::ToBytesArray(plainText).ToHex() << std::endl;
	if (BigInt::Equal(msg, plainText))
	{
		std::cout << "Passed" << std::endl;
		passed++;
	}
	else 
	{
		std::cout << "Failed" << std::endl;
		unpassed++;
	}

	std::cout << "Total passed: " << passed << " Unpassed: " << unpassed << std::endl;
}