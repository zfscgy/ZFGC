// ZFGC.cpp: 定义应用程序的入口点。
//

#include "ZFGC.h"
#include "Common/BigInteger.h"

using namespace std;
using namespace ZFGC;
int main()
{
	BigInteger a(10);
	BigInteger b(10);
	cout << a + b << endl;
	return 0;
}
