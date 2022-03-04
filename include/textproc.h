#ifndef TEXTPROC_H
#define TEXTPROC_H

#include <stddef.h>

void textproc_reverse_string(char *str, char *out, size_t bufsiz);
void textproc_rot13_encode(char *str, char *out, size_t bufsiz);
void textproc_rot13_decode(char *str, char *out, size_t bufsiz);
void textproc_shift_text(char *str, char *out, size_t bufsiz, int offset);

#endif /* TEXTPROC_H */
