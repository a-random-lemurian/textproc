#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <textproc.h>

void textproc_reverse_string(char *str, char *out, size_t bufsiz)
{
  size_t j = (bufsiz - 1);
  size_t i = j - 1;
  size_t n;

  out[j] = '\0';
  for (n = 0; n < j; n++) {
    out[n] = str[i];
    i--;
  }
}
