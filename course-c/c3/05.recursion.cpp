#include <stdio.h>
#include <stdarg.h>

// 变长参数

unsigned int fib(unsigned int n) {
  if (n < 2) {
    return n;
  }
  int last = 0;
  int current = 1;
  for (int i = 0; i <= n - 2; i++) {
    int temp = current;
    current += last;
    last = temp;
  }
  return current;
}

int main(void) {
  printf("fib(10) = %d\n", fib(10));
  return 0;
}
