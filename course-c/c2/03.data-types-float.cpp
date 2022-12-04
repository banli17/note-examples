#include <stdio.h>
#include <limits.h>

/**
 * 浮点数
 * - float 精度 6 位
 * - double 15-16位
 */
int main() {
  // 不加 f, 默认为 double
  float a_float = 3.14f; // 至少表示 6 个有效数字, 精度 +-10^-37 ~ 10^37
  double a_double = 3.14; // 15-16位

  printf("a_float size %d\n", sizeof(float)); // 4
  printf("a_double size %d\n", sizeof(double)); // 8

  float lat = 0.0001f;
  printf("%f\n", 0.0002 - lat); // 0.000100

  float lat1 = 0.000008f;
  printf("%f\n", 0.000009f - lat); // -0.000091 浮点精度有问题

  float money = 3.14f; // error 钱不要用浮点数
  float money2 = 3.02f;
  printf("money - money2: %f\n", money - money2); // 0.120000
  return 0;
}