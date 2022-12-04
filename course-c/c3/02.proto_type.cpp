#include <stdio.h>

// 函数声明需要在调用前面, 函数实现可以放后面
void EmptyParamList(void); // 函数原型

int Add(int, int);

/**
 * 1. 函数名
 * 2. 函数如果不写返回值类型, 函数默认返回值类型为 int
 * 3. 函数参数列表，参数类型和参数的顺序，参数形参名不重要
 * @return
 */
int main(void) {
  // 参数列表，如果不写，c 表示不知道有多少个参数, 传了参数不会报错，c++ 表示没有参数, 传了参数会报错
  // c 没有参数，可以使用 void
  // EmptyParamList(2, 3, 4); // c 不报错, cpp 报错

  EmptyParamList();

  // 函数参数列表，可以不写名字，只写类型, 但是无法获取
  // 编译时不会报错, 执行时报错
  Add(3, 4);
  return 0;
}

void EmptyParamList() {
  puts("hello, this is empty");
}

