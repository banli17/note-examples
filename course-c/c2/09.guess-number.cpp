#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // 1. 随机数 [0, 0x7fff]
  srand(time(NULL)); // 需要传递一个不同的数作为种子

  int magic_number = rand();
  while (1) {
    int input;
    puts("Please input a number :"); // puts 可以打印字符串, 不能格式化字符串
    scanf("%d", &input);
    if (input == 10) {
      break;
    }
  }

  return 0;
}
