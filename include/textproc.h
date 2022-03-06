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

/*
 * Manipulate the case of a char. The mode parameter has the same options as
 * textproc_manip_case_string's mode parameter. textproc_manip_case_string
 * acts as a wrapper for this function, operating on an entire char* instead
 * of a single character.
 */
char textproc_manip_case_letter(char c, int mode);


/*
 * Return 1 if c is lowercase, otherwise return 0.
 */
int textproc_is_lowercase_char(char c);

/*
 * Return 1 if c is uppercase, otherwise return 0.
 */
int textproc_is_uppercase_char(char c);

/*
 * Invert the case of a character. (a -> A)
 */
char textproc_invert_char_case(char c);

/*
 * Invert the case of a string. (lowerUPPER -> LOWERupper)
 */
void textproc_invert_string_case(char* str, char* out, size_t bufsiz);

/*
 * Calculate the Hamming distance of two strings, of the same length.
 */
size_t textproc_hamming_distance(char *s1, char *s2);

/*
 * Same as textproc_levenshtein, but you must explicitly specify the length
 * of both strings.
 */
size_t textproc_levenshtein_n(char *s1, size_t s1l, char *s2, size_t s2l);

/*
 * Return the Levenshtein distance between two strings, without having to
 * specify the length of both strings.
 */
size_t textproc_levenshtein(char *s1, char *s2);

/*
 * Return 1 if position 0 (the first character) of str is equal to c,
 * otherwise return 0.
 */
int textproc_starts_with(char* str, char c);

/*
 * Return 1 if the last character (excluding the terminating null byte '\0'),
 * is equal to c, otherwise return 0;
 */
int textproc_ends_with(char* str, char c);

/*
 * Check if a character at the index idx in str is equal to c. It is generally
 * cleaner and shorter to use something like:
 * 
 * if (str[i] == c) {
 *   code();
 * }
 * 
 * instead of
 * 
 * if (textproc_check_specific_pos(str, c, i)) {
 *   code();
 * }
 * 
 * as this method is primarily called by other textproc functions.
 */
int textproc_check_specific_pos(char* str, char c, size_t idx);


#ifdef TEXTPROC_INCLUDE_STRNCPY_NT
/*
 * Wrapper function for strcpy(), automatically terminates new strings
 * with a NULL character.
 */
char* tp_strncpyn(char* dest, const char* src, size_t n);
#endif

#endif /* TEXTPROC_H */
