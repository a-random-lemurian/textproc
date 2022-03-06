#include <textproc.h>
#include <string.h>

int textproc_starts_with(char* str, char c)
{
  return textproc_check_specific_pos(str, c, 0);
}

int textproc_ends_with(char* str, char c)
{
  return textproc_check_specific_pos(str, c, strlen(str));
}

int textproc_check_specific_pos(char* str, char c, size_t idx)
{
  if (str[idx] == c) {
    return 1;
  }
  return 0;
}
