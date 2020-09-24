cmake_minimum_required (VERSION 3.8)

add_executable(Test_BigInteger "Test_BigInteger.cpp")

target_link_libraries(Test_BigInteger ZFGC_COMMON ${CRYPTOPP_LIB})

add_executable(Test_RSA "Test_RSA.cpp")

target_link_libraries(Test_RSA ZFGC_COMMON ${CRYPTOPP_LIB})