#include <stdio.h>
#include <stdarg.h>

// 变长参数

void handleVarargs(int arg_count, ...) {
  // 定义 va_list 接收变长参数
  va_list args;
  // 2. 开始遍历
  va_start(args, arg_count);
  for (int i = 0; i < arg_count; i++) {
    // 3. 取出对应参数, (va_list, type)
    int arg = va_arg(args, int);
    printf("%d: %d\n", i, arg);
  }
  // 4. 遍历结束
  va_end(args);
}

int main(void) {
  handleVarargs(3, 1, 7, 8);
  return 0;
}
