#include <stdio.h>

double addOne(double x) {
  return x + 1;
}

double add(double x, double y, double z) {
  return x + y + z;
}

int main() {
  // 函数命名是 大写字母开头，如 Add, FindNumber
  int a = 2;
  int b = addOne(a);
  printf("b is %d\n", b); // 3

  printf("sum is %d\n", add(2, 3, 5)); // 73896
  printf("sum is %f\n", add(2.0, 3.0, 5.0)); // 10.000000

  return 0;
}
