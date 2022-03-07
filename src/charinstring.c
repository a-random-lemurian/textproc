#include <textproc.h>

int textproc_char_in_string(char* str, char trgt_char, size_t str_siz)
{
  size_t i;
  for (i = 0; i < str_siz; i++) {
    if (str[i] == trgt_char) {
      return 1;
    }		
  }
  return 0;
}

