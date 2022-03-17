#include <stdio.h>

int is_digit(char symbol) {
  return (symbol >= '0') && (symbol <= '9');
}

int is_capital(char symbol) {
  return (symbol >= 'A') && (symbol <= 'Z');
}

int valid_number(char *number) {
  for (int i = 0; i < 2; ++i, ++number)
    if ((number == NULL) || (! is_digit(*number)))
      return -1;

  for (int i = 0; i < 2; ++i, ++number)
    if ((number == NULL) || (! is_capital(*number)))
      return -1;

  for (int i = 0; i < 2; ++i, ++number)
    if ((number == NULL) || (! is_digit(*number)))
      return -1;

  if ((number[-2] == '0' && number[-1] == '0') || (number[-6] == '0' && number[-5] == '0'))
    return -1;

  return 0;
}

int increase_number(char *number) {
  int encoded = (number[4] - '0') * 10 + (number[5] - '0') + 1;
  number[5] = encoded % 10 + '0';
  number[4] = encoded / 10 + '0';

  if (encoded >= 100) {
    number[5] = 1 + '0';
    number[4] = 0 + '0';

    encoded = (number[2] - 'A') * 26 + (number[3] - 'A') + 1;
    number[3] = encoded % 26 + 'A';
    number[2] = encoded / 26 + 'A';

    if (encoded >= 676) {
      number[2] = number[3] = 'A';

      encoded = (number[0] - '0') * 10 + (number[1] - '0') + 1;
      number[0] = encoded % 10 + '0';
      number[1] = encoded / 10 + '0';

      if (encoded >= 100)
        return -1;
    }
  }

  return 0;
}

int main(int argc, char **argv) {
  char *number = argv[1];

  if (valid_number(number) == -1) {
    printf("Error: invalid number!\n");
    return 1;
  }

  if (increase_number(number) == -1) {
    printf("99ZZ99\n");
    return 0;
  }

  printf("%s\n", number);

  return 0;
}
