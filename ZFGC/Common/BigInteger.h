#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include "../configs.h"
namespace ZFGC {
	/*
	BytesArray class. Stores a pointer of byte(unsigned char), and a length.
	The desctructor function will free memory of the char pointer.
	*/
	class BytesArray
	{
	public:
		unsigned char* bytes;
		size_t length;
		BytesArray(unsigned char* _bytes, size_t _length);
		// Assignment operator
		BytesArray(const BytesArray& _bytesArray);
		// Move operator
		BytesArray(BytesArray&& _bytesArray);
		~BytesArray();
		std::string const ToHex();
	};
	std::ostream& operator<<(std::ostream& os, const BytesArray& bytesArray);
	BytesArray RandomBytes(size_t length);
}

#ifdef USE_CRYPTOPP
/*
	When uses 
*/
#include "cryptopp/cryptlib.h"
#include "cryptopp/integer.h"
#include "cryptopp/modarith.h"
namespace ZFGC {
	typedef CryptoPP::Integer BigInteger;
}
#endif // USE_CRYPTOPP

namespace ZFGC::BigInt{
	BigInteger FromBytesArray(const BytesArray& bytesArray);
	BytesArray ToBytesArray(const BigInteger& bigInt);
	BigInteger Add(const BigInteger& left, const BigInteger& right);
	BigInteger Sub(const BigInteger& left, const BigInteger& right);
	BigInteger A_exp_B_mod_C(const BigInteger& a, const BigInteger& b, const BigInteger& c);
	bool Equal(const BigInteger& left, const BigInteger& right);
}