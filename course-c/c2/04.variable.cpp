#include <stdio.h>
#include <limits.h>

int main() {
  int value = 4;
  printf("size of value: %d\n", sizeof(value)); // 4
  printf("address of value: %x\n", &value); // bc263698

  int value2;
  printf("value2 default value: %x\n", value2); // ffffffff
  printf("value2 default value: %d\n", value2); // -1
  return 0;
}