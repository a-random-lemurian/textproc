#ifndef TEXTPROC_H
#define TEXTPROC_H

#include <stddef.h>

/*
 * The TP_LOWER and TP_UPPER macros are meant to be arguments to the
 * int mode parameter of textproc_manip_case_string.
 */
#define TP_LOWER 0
#define TP_UPPER 1

/*
 * Reverse str and write the reversed string to out.
 */
void textproc_reverse_string(char *str, char *out, size_t bufsiz);

/*
 * Perform rot13 encoding on str, and write it to out.
 */
void textproc_rot13_encode(char *str, char *out, size_t bufsiz);

/*
 * Decode a rot13-encoded string in str, and write it to out.
 */
void textproc_rot13_decode(char *str, char *out, size_t bufsiz);

/*
 * Shift letters in a string by a certain number of characters. The
 * textproc_rot13_encode and decode functions call this function with
 * an offset of 13.
 */
void textproc_shift_text(char *str, char *out, size_t bufsiz, int offset);

/*
 * Write an uppercase version of str to out.
 */
void textproc_upper_string(char *str, char *out, size_t bufsiz);

/*
 * Write a lowercase version of str to out.
 */
void textproc_lower_string(char *str, char *out, size_t bufsiz);

/*
 * Manipulate the case of a string.
 *
 * The mode parameter has two options:
 * TP_LOWER: write a lowercase version of str to out.
 * TP_UPPER: write an uppercase version of str to out.
 */
void textproc_manip_case_string(char *str, char *out, size_t bufsiz, int mode);

#endif /* TEXTPROC_H */
