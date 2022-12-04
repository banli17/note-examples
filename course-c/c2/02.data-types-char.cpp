#include <stdio.h>
#include <wchar.h>
#include <locale.h>
/**
 * 字符 char
 * - 字符的本质是数字, ASCII 字符集
 * - 0 表示 \0, null
 */
int main() {
  // 字符集 ASCII
  char a = 'a'; // 97
  char char_1 = '1'; // 49
  char char_0 = '0'; // 48

  char i = 0; // \0, NULL

  printf("char a: %d\n", a); // 97
  printf("char 1: %d\n", char_1); // 49
  printf("char 0: %d\n", char_0); // 48

  printf("char 1: %c\n", char_1); // '1'

  // 转义字符
  // 和 char_1 表示同一字符，计算机存储任何字符都是以数字形式
  // printf 只是用什么格式(format) 去打印查看数据
  char char_1_escape_oct = '\61'; // \ 后面跟八进制数
  char char_1_escape_hex = '\x31'; // \x 后面跟十六进制数
  printf("char 1: %d\n", char_1_escape_oct); // 49
  printf("char 1: %d\n", char_1_escape_hex); // 49

  wchar_t zhong = L'中';
  printf("中: %d\n", zhong); // 中: 20013
//  setlocale(LC_ALL, "zh_CN.UTF-8");
  //  printf和wprintf不能混用，即一个程序中使用了printf， 就不使用wprintf
  wprintf(L"中: %ls\n", zhong); // 中

  wchar_t zhong_hex = L'\u4E2D';
  printf("中: %d\n", zhong_hex); // 中: 20013

  char *string = "中";
  return 0;
}