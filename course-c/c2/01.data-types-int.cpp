#include <stdio.h>
#include <limits.h>

/**
 * int 类型
 * 1. 按照长度，分类 4 种类型：short int(16), int, long int, long long int
 * 2. 按照符号，分为有符号(signed)和无符号(unsigned)
 *
 * limits.h 定义了各种数据类型的相关常量
 * INT_MAX, INT_MIN, UINT_MAX, UINT_MIN
 */

int main() {
  short short_int = 0;
  int i = 0;
  long long_int = 0;
  long long long_long_int = 0;

  printf("short int: %lu\n", sizeof(short_int)); // 2 -> 16 bit, 65536
  printf("int: %d\n", sizeof(int)); // 4 -> 32 bit
  printf("long int: %d\n", sizeof(long_int)); // 8 -> 64 bit
  printf("long long int: %d\n", sizeof(long_long_int)); // 8 -> 64 bit

  printf("min short int %d\n", SHRT_MAX); // 32767
  printf("max int %d, min int %d\n", INT_MAX, INT_MIN);
  // max int 2147483647, min int -2147483648

  unsigned int j = 0;
  printf("unsigned int: %d\n", sizeof(j)); // 4 -> 32 bit

  printf("max int %d, min int %d\n", UINT_MAX, 0);
  // max int -1, min int 0, %d 是有符号的

  printf("max int %u, min int %d\n", UINT_MAX, 0);
  // max int 4294967295, min int 0
  return 0;
}