#include <textproc.h>

void textproc_rot13_encode(char *str, char *out, size_t bufsiz)
{
  textproc_shift_text(str, out, bufsiz, 13);
}

void textproc_rot13_decode(char *str, char *out, size_t bufsiz)
{
  textproc_shift_text(str, out, bufsiz, 13);
}
