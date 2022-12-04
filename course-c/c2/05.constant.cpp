#include <stdio.h>
#include <limits.h>

# define COLOR_RED 0xFF0000 // 定义宏，不可变常量，会直接编译为一个常量
int main() {
  const int kRed = 0xFF0000;
  const int kGreen = 0x00FF00;
  const int kBlue = 0x0000FF;

  // kRed = 12; // 不能重新赋值

  printf("kRed: %d\n", kRed);
  // 不能指针修改, 报错，下面语句已经不生效了
  //  int *p_k_red = &kRed;
  //  *kRed = 0;
  //  printf("kRed: %d\n", kRed);

  // macro，真正运行时，这个 COLOR_RED 已经不存在了
  printf("COLOR_RED: %d\n", COLOR_RED);
  // #undef COLOR_RED 取消定义宏, 后面再使用 COLOR_RED 会报错
//  gcc -E 05.constant.cpp -o 05.out.cpp 预处理命令

  // 字面量
  // 5  3u 3l 3.f 3.9 'c' "cs" L'中' L"中国"
  return 0;
}