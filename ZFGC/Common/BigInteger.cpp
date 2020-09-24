#include "BigInteger.h"
#ifdef USE_CRYPTOPP
namespace ZFGC 
{
	std::default_random_engine random_engine(time(0));
	std::uniform_int_distribution<unsigned char> uniformBytes;

	BytesArray::BytesArray(unsigned char* _bytes, size_t _length)
	{
		bytes = _bytes; length = _length;
	}

	BytesArray::BytesArray(const BytesArray& _bytesArray)
	{
		bytes = new unsigned char[_bytesArray.length];
		std::memcpy(bytes, _bytesArray.bytes, _bytesArray.length);
		length = _bytesArray.length;
	}

	BytesArray::BytesArray(BytesArray&& _bytesArray)
	{
		bytes = _bytesArray.bytes;
		length = _bytesArray.length;
		_bytesArray.bytes = nullptr;
	}

	BytesArray::~BytesArray()
	{
		delete bytes;
	}

	std::string const BytesArray::ToHex()
	{
		std::stringstream hexSS;
		hexSS << "0x" << std::hex;
		for (int i = 0; i < length; ++i)
			hexSS << std::setw(2) << std::setfill('0') << (int)bytes[i];
		return hexSS.str();
	}

	std::ostream& operator<<(std::ostream& os, ZFGC::BytesArray const& bytesArray)
	{
		for (size_t i = 0; i < bytesArray.length; i++)
		{
			os << " " << bytesArray.bytes[i];
		}
		return os;
	}

	BytesArray RandomBytes(size_t length)
	{
		BytesArray bytesArray(new unsigned char[length], length);
		for (size_t i = 0; i < length; i++)
		{
			bytesArray.bytes[i] = uniformBytes(random_engine);
		}
		return bytesArray;
	}

	namespace BigInt 
	{
		BigInteger FromBytesArray(const BytesArray& bytesArray)
		{
			return CryptoPP::Integer(bytesArray.bytes, bytesArray.length);
		}

		BytesArray ToBytesArray(const BigInteger& bigInt) 
		{
			BytesArray bytesArray(new unsigned char[bigInt.ByteCount()], bigInt.ByteCount());
			for (size_t i = 0; i < bigInt.ByteCount(); i++)
			{
				bytesArray.bytes[i] = bigInt.GetByte(i);
			}
			return bytesArray;
		};

		BigInteger Add(const BigInteger& left, const BigInteger& right)
		{
			return left + right;
		}
	
		BigInteger Sub(const BigInteger& left, const BigInteger& right)
		{
			return left - right;
		}
		
		BigInteger A_exp_B_mod_C(const BigInteger& a, const BigInteger& b, const BigInteger& c)
		{
			CryptoPP::ModularArithmetic mr(c);
			return mr.Exponentiate(a, b);
		}
		
		bool Equal(const BigInteger& left, const BigInteger& right)
		{
			return (left - right).IsZero();
		}
	}
}
#endif // USE_CRYPTOPP