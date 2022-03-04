#include <textproc.h>

void textproc_manip_case_string(char *str, char *out, size_t bufsiz, int mode)
{
  size_t i;
  out[bufsiz] = '\0';
  for (i = 0; i < bufsiz - 1; i++) {
    char c = str[i];
    if (mode == TP_UPPER) {
      if (c >= 'a' || c <= 'z') {
        c -= 32;
      }
    }
    else if (mode == TP_LOWER) {
      if (c >= 'A' || c <= 'z') {
        c += 32;
      }
    }
    out[i] = c;
  }
}

void textproc_lower_string(char *str, char *out, size_t bufsiz)
{
  textproc_manip_case_string(str, out, bufsiz, TP_LOWER);
}

void textproc_upper_string(char *str, char *out, size_t bufsiz)
{
  textproc_manip_case_string(str, out, bufsiz, TP_UPPER);
}
