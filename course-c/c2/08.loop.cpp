#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("Please input your name:");
  char name;
  scanf("%c", &name);
  printf("Please input a char:");
  char command;

  // 如果上面输入 ab，name = a, b 会被 command 接收到
  while (command = getchar()) {
    if (command == 'q') break;
  }

  printf("command is %d\n", command);

  int sum = 1;
  do {
    sum++;
  } while (sum < 2);

  printf("sum is %d\n", sum);

  int sum100 = 0;
  // C99 支持 for 语句里定义变量: int num = 1
  for (int num = 1; num < 100; ++num) {
    sum100 += num;
  }
  printf("sum100 of [1, 100]: %d\n", sum100);

  // continue 继续下次循环
  // break 跳出循环

  // goto 跳转到任意的标签, 避免使用
  int i = 0;
  begin:
  printf("%d\n", i);
  if (i++ < 5) {
    goto begin;
  }
  //  0 1 2 3 4 5
  return 0;
}
