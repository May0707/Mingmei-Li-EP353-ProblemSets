#include <stdio.h>
int main() {  

  char noteName = 'D';

  printf("Find the interval between notes in C Maj scale\n");
  switch (noteName) {
    case 'C':
    case 'c':
      printf("\nThe interval between C and C is 0.\n");
      break;

    case 'D':
    case 'd':
      printf("\nThe interval between C and D is 2.\n");
      break;

    case 'E':
    case 'e':
      printf("\nThe interval between C and E is 4.\n");
      break;

    case 'F':
    case 'f':
      printf("\nThe interval between C and F is 5.\n");
      break;

    case 'G':
    case 'g':
      printf("\nThe interval between C and G is 7.\n");
      break;

    case 'A':
    case 'a':
      printf("\nThe interval between C and A is 9.\n");
      break;

    case 'B':
    case 'b':
      printf("\nThe interval between C and B is 11.\n");
      break;

    default:
      printf("This note is not a white key!\n");
  }

  return 0;
}