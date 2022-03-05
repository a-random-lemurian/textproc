#include <textproc.h>

/* NT: [n]ull-[t]erminated*/
#ifdef TEXTPROC_INCLUDE_STRNCPY_NT
#include <string.h>
char* tp_strncpyn(char* dest, const char* src, size_t n)
{
  char* retval = strncpy(dest, src, n);
  dest[n] = '\0';

  return retval;
}
#endif