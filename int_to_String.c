#include <stdio.h>
#include <stdlib.h>

int len_of_num(int n) {
  int count = 0;
  int num = n;

  while (num > 9 || num < -9) {
    num /= 10;
    count++;
  }
  return (count);
}

char *int_to_string(int number) {
  int digits, tens, i = 0, t = 0, x;
  char *res;

  digits = number;
  tens = 1;

  if (number < 0)
    t = 1;

  printf("(number) after first if is: %d\n", number);
  printf("value of (t) after first if is: %d\n and digits is: %d\n", t, digits);

  res = malloc(sizeof(char) * (len_of_num(digits) + 2 + t));
  if (res == NULL)
    return (NULL);
  if (number < 0) {
    res[i] = '-';
    i++;
  }
  printf("---------1st loop-------\n");
  for (x = 0; digits > 9 || digits < -9; x++) {
    digits /= 10;
    tens *= 10;
    printf("(digit) at (%d) round: %d\n", x, digits);
    printf("(tens) at (%d) round: %d\n", x, tens);
  }
    printf("---------2nd loop-------\n");
  for (digits = number; x >= 0; x--) {
    if (digits < 0) {
      res[i] = (digits / tens) * -1 + '0';
      i++;
    } else {
      res[i] = (digits / tens) + '0';
      i++;
    }
    digits %= tens;
    tens /= 10;

    printf("(digit) at (%d) round: %d\n", x, digits);
    printf("(tens) at (%d) round: %d\n", x, tens);
  }
  res[i] = '\0';
  return (res);
}

int main() {
    printf("-------------------------------\n");
    int_to_string(123);
    printf("-------------------------------\n");
    int_to_string(1000);

  return (0);
}