#include <textproc.h>

/*
 * The textproc_rot13_encode and decode functions are essentially wrappers
 * for textproc_shift_text, with an offset of 13.
 */

void textproc_rot13_encode(char *str, char *out, size_t bufsiz)
{
  textproc_shift_text(str, out, bufsiz, 13);
}

void textproc_rot13_decode(char *str, char *out, size_t bufsiz)
{
  textproc_shift_text(str, out, bufsiz, 13);
}
