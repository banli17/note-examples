#include <stdio.h>

/**
 * 变量类型
 * - 自动变量 auto
 * - 函数静态变量 static
 * - 寄存器变量 register
 * 作用域
 * - 函数原型作用域 (proto scope)
 * - 函数作用域 (function scope)
 * - 全局作用域 (file scope）
 * - 块作用域
 */

// 全局作用域
int global_var = 10;

void func() {
  static int static_func_var; // 默认值为 0, 会一直存在内存中
  int func_var;

  printf("static_func_var is: %d\n", static_func_var++);
  printf("func_var is: %d\n", func_var++);
}

// size 原型作用域
void sortArray(int size, int array[size], register int reg_var);
// 寄存器变量编译成汇编时，会直接操作寄存器，而不是赋值值到内存
// register 一般不写，这个过程由编译器自动完成

int main(void) {
  // 函数作用域
  // 自动变量, 进入函数，内存自动分配，离开函数，自动销毁
  int value = 0;
  // 等价于 auto int value = 0;

  // 块作用域, if else 等
  {
    int a = 1;
  }
//  printf("%d\n", a);
  printf("global var: %d\n", global_var);

  func();
  func();
  func();
  return 0;
}
