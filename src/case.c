#include <textproc.h>

char textproc_manip_case_letter(char c, int mode)
{
  if (mode == TP_UPPER) {
    if (c >= 'a' && c <= 'z') {
      c -= 32;
    }
  }
  else if (mode == TP_LOWER) {
    if (c >= 'A' && c <= 'z') {
      c += 32;
    }
  }

  return c;
}

void textproc_manip_case_string(char *str, char *out, size_t bufsiz, int mode)
{
  size_t i;
  out[bufsiz] = '\0';

  for (i = 0; i < bufsiz - 1; i++) {
    char c = str[i];
    out[i] = textproc_manip_case_letter(c, mode);
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

/*
 * Replacements for standard library function isupper() and islower(), just
 * in case.
 */


int textproc_is_lowercase_char(char c)
{
  if (c >= 'a' && c <= 'z') {
    return 1;
  }
  else {
    return 0;
  }
  
}

int textproc_is_uppercase_char(char c)
{
  if (c >= 'A' && c <= 'Z') {
    return 1;
  }
  else {
    return 0;
  }
}


char textproc_invert_char_case(char c)
{
  if (textproc_is_lowercase_char(c)) {
    c -= 32;
  }
  else if (textproc_is_uppercase_char(c)) {
    c += 32;
  }

  return c;
}

void textproc_invert_string_case(char* str, char* out, size_t bufsiz)
{
  size_t i;
  for (i = 0; i < bufsiz; i++) {
    out[i] = textproc_invert_char_case(str[i]);
  }
}
