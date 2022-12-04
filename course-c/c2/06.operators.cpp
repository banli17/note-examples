#include <stdio.h>

int main() {
  int first = 1;
  int second = 2;
  int sum = first + second;

//  first = second;
//  printf("first is %d, second is %d\n", first, second);

  printf("sum is %d\n", sum);

  printf("first * second is %d\n", first * second);
  int q1 = 2 / 3;
  printf("q1 is %d\n", q1); // 0
  printf("q1 is %f\n", q1); // 0.000000

  // 作除法时，2, 3 都是 int ，运算之后会转成 int 0，再赋值给 q1，
  float q2 = 2 / 3;
  printf("q2 is %d\n", q2); // 738960
  printf("q2 is %f\n", q2); // 0.000000

  float q3 = (2 * 1.f) / (3 * 1.f);
  printf("q3 is %f\n", q3); // 0.666667

  // 判断
  // > < >= <= == !=
  // C99 增加了布尔类型，本质还是整型，true: 1, false: 0
  printf("3 > 2: %d\n", 3 > 2); // 1
  printf("3 < 2: %d\n", 3 < 2); // 0

  // 逻辑
  // && ||
  printf("3 > 2 && 3 < 2: %d\n", 3 > 2 && 3 < 2); // 1
  // || 后面代码变灰色，短路
  printf("3 > 2 || 3 < 2: %d\n", 3 > 2 || 3 < 2); // 0

  // ++ --
  int i = 1;
  int j = i++; // j = 1, i = 2
  int k = ++j; // k = 2, j = 2
  printf("i, j, k = %d, %d, %d", i, j, k); // 2, 2, 2

  // 位运算
  //  & 相同为1,不同为 0
  //  | 有1 为1,全0为 0
  //  ^ 不同为1,相同为 0
  //  ~ 1 得0 , 0 得1
#define FLAG_VISIBLE 0x1 // 2^0, 0001
#define FLAG_TRANSPARENT 0x2 // 2^1, 0010
#define FLAG_RESIZABLE 0x4 // 2^2, 0100

  int flag = FLAG_RESIZABLE | FLAG_TRANSPARENT; // 0110
  int resizable = flag & FLAG_RESIZABLE; // 0100
  int visible = flag & FLAG_VISIBLE; // 0000

  printf("弹框可见 %d\n", visible != 0); // 0
  printf("弹框可调大小 %d\n", resizable != 0); // 1

  // 移位运算
#define FLAG_VISIBLE 1 << 0 // 2^0, 0001
#define FLAG_TRANSPARENT 1 << 1 // 2^1, 0010
#define FLAG_RESIZABLE 1 << 2 // 2^2, 0100

  int x = 1000;
  // x << 1 -> x * 2 移位速度更快, 左移 *2, 右移 /2
  printf("x * 2 is %d\n", x << 1); // 2000
  printf("x / 2 is %d\n", x >> 1); // 500

  // 赋值运算符
  x *= 2;
  x /= 2;
  x %= 2;
  x += 2;
  x -= 2;

  x >>= 1;
  x <<= 1;

  // 逗号运算符, 结果是后面一个表达式的值
  // y = x = x * 2, x = x + 3;


  return 0;
}