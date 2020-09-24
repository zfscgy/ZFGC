#include "../Common/BigInteger.h"

using namespace ZFGC;
int main() 
{
	size_t passed = 0;
	size_t unpassed = 0;
	std::cout << "Test BigInteger Module" << std::endl;

	std::cout << "Test BytesArray to Hex: ";
	BytesArray bytesArr(new unsigned char[3]{ 0, 1, 255 }, 3);
	std::string hex1 = bytesArr.ToHex();
	std::cout << "should be 0x0001ff. Result: " << hex1 << std::endl;
	if (hex1 == "0x0001ff")
	{
		std::cout << "Passed" << std::endl;
		passed++;
	}
	else
	{
		std::cout << "Failed" << std::endl;
		unpassed++;
	}

	// Test Add
	std::cout << "Test addition: ";
	BytesArray bytesArr1(new unsigned char[3]{ 1, 2, 3 }, 3);
	BytesArray bytesArr2(new unsigned char[3]{ 3, 2, 1 }, 3);
	BytesArray bytesArr3(new unsigned char[3]{ 4, 4, 4 }, 3);
	BigInteger bigInt1 = BigInt::FromBytesArray(bytesArr1);
	BigInteger bigInt2 = BigInt::FromBytesArray(bytesArr2);
	BigInteger bigInt3 = BigInt::FromBytesArray(bytesArr3);
	BigInteger bigIntSum12 = BigInt::Add(bigInt1, bigInt2);
	std::cout << bigInt1 << " + " << bigInt2 << " shoud be " << bigInt3 << ". Result: " << bigIntSum12 << std::endl;
	if (!BigInt::Equal(bigIntSum12, bigInt3))
	{
		std::cout << "Failed" << std::endl;
	}
	else
	{
		std::cout << "Passed" << std::endl;
		passed++;
	}

	std::cout << "Passed tests: " << passed << "  Failed tests: " << unpassed << std::endl;
	return 0;
}