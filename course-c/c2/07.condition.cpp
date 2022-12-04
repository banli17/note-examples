#include <stdio.h>
#include <stdbool.h>

void playGame() {

#define MAGIC_NUMBER 10

  int user_input;
  printf("Please input a number: \n");

  while (true) {
    scanf("%d", &user_input);
    if (user_input > MAGIC_NUMBER) {
      printf("Your number is bigger!");
    } else if (user_input < MAGIC_NUMBER) {
      printf("Your number is smaller!");
    } else {
      printf("Yes! You got it!");
      break;
    }
  }
}

int main() {
  // Bool true:1, false 0
  // _Bool, bool
  _Bool is_enabled = true; // 只能是 1 或者 0
  is_enabled = 10;
  printf("is_enabled: %d\n", is_enabled); // 1, 强制转换为 1

//  playGame();

//  int is_visible;
//  printf("Please input is_visible:");
//  scanf("%d", &is_visible);
//  int is_open = is_enabled && is_visible ? 1 : 0;
//  printf("is_open: %d\n", is_open);

  // switch
#define ADD '+'
#define MINUS '-'

  char operator1;
  int a, b, result;
  printf("Please input an expression: \n");
  scanf("%d %c %d", &a, &operator1, &b);
  switch (operator1) {
    case ADD:result = a + b;
      break;
    case MINUS:result = a - b;
      break;
    default:result = 0;
      break;
  }
  printf("result is %d\n", result);

  return 0;
}
