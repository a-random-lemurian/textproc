#ifndef TEXTPROC_H
#define TEXTPROC_H

#include <stddef.h>


#define TP_LOWER 0
#define TP_UPPER 1


void textproc_reverse_string(char *str, char *out, size_t bufsiz);
void textproc_rot13_encode(char *str, char *out, size_t bufsiz);
void textproc_rot13_decode(char *str, char *out, size_t bufsiz);
void textproc_shift_text(char *str, char *out, size_t bufsiz, int offset);
void textproc_upper_string(char *str, char *out, size_t bufsiz);
void textproc_lower_string(char *str, char *out, size_t bufsiz);
void textproc_manip_case_string(char *str, char *out, size_t bufsiz, int mode);

#endif /* TEXTPROC_H */
