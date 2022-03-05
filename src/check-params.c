#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <textproc-internal.h>

void __textproc_check_string_params(char *str, char *out, size_t bufsiz)
{
  if (strlen(str) != bufsiz) {
    fprintf(stderr, "textproc: invalid bufsiz "
           "(param str strlen(): %ld, bufsiz %ld, diff %ld)",
           strlen(str), bufsiz, (strlen(str) - bufsiz));
    abort();
  }
}
