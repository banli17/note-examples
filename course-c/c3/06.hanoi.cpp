#include <stdio.h>
#include <stdarg.h>

// 变长参数
/**
 * @param n 移动数量
 * @param src 起始位置
 * @param dest 目标位置
 * @param tmp 临时位置
 */
void Move(int n, char src, char dest, char tmp) {
  if (n == 0) {
    return;
  } else if (n == 1) {
    printf("%c --> %c\n", src, dest);
  } else {
    Move(n - 1, src, tmp, dest);
    Move(1, src, dest, tmp);
    Move(n - 1, tmp, dest, src);
  }
}

int main(void) {
  Move(3, 'a', 'c', 'b');
  return 0;
}
