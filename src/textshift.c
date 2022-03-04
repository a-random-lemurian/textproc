#include <textproc.h>

void textproc_shift_text(char *str, char *out, size_t bufsiz, int offset)
{
  size_t i;

  out[bufsiz] = '\0';

  for (i = 0; i < bufsiz; i++) {
    unsigned char c = str[i];
    if (c >= 'a' && c <= 'z') {
      c += offset;
      if (c > 'z') {
        c -= 26;
      }
    }
    else if (c >= 'A' && c <= 'Z') {
      c += offset;
      if (c > 'Z') {
        c -= 26;
      }
    }
    out[i] = c;
  }
}
