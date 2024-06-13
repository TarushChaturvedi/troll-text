#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '[', ']', ';', '\0'};
const char chars_to_replace[] = {'a', 'e', 'i', 'o', 'u', '\0'};

int main(int argc, char* argv[]) {

  if (argc != 2) {
    fprintf(stderr, "Invalid usage!\nCorrect usage: %s <text>\n", argv[0]);
    return -1;
  }

  char* trolltext = argv[1];

  srand(time(NULL)); // Different seed each time

  for (int i = 0; i < strlen(trolltext); i++) {
    for (int j = 0; j < strlen(chars_to_replace); j++) {
      if (trolltext[i] == chars_to_replace[j]) {
        trolltext[i] = chars[rand() % strlen(chars_to_replace)];
      }
    }
  }

  puts(trolltext);
  putc('\n', stdout);
  return 0;
}
