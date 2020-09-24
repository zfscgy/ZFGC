# CMakeList.txt: ZFGC 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 调用Crypto++自带的makefile生成静态库
# add_custom_target(CryptoLib ALL
#                   COMMAND make
#                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs/cryptopp-CRYPTOPP_8_2_0/
# )
# 由于VS自动同步会删除所有文件，因此不用这种方法，而是采用在别的目录下make之后生成.a静态库再链接。

# Crypto++的源码目录
include_directories("/data/home/zf/dev/libs/")

# 设置Crypto++的.a文件路径
SET(CRYPTOPP_LIB "/data/home/zf/dev/libs/cryptopp/libcryptopp.a")

# 搜索Common目录下的.cpp和.h源文件
FILE(GLOB ZFGC_COMMON_SOURCES "Common/*.cpp" "Common/*.h")

# 生成一个库
add_library(ZFGC_COMMON STATIC ${ZFGC_COMMON_SOURCES})

# FILE(GLOB ZFGC_OT_SOURCES "OT/*.cpp" "OT/*.h")
# add_library(ZFGC_OT STATIC ${ZFGC_OT_SOURCES})

add_executable (ZFGC "ZFGC.cpp" "ZFGC.h")

target_link_libraries(ZFGC ZFGC_COMMON ${CRYPTOPP_LIB})

# TODO: 如有需要，请添加测试并安装目标。

add_subdirectory("Tests")