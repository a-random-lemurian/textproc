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

/*
 * Return the number of English vowels in str.
 */
size_t textproc_en_vowel_count(char *str);

/*
 * Return the number of English consonants in str.
 */
size_t textproc_en_consonant_count(char *str);

/*
 * Count the number of times a letter in trgt_chars is present in str.
 *
 * str: aeioum
 * trgt_chars: m
 * returns: 1
 * 
 * The trgt_chars variable was "m", and there was only one occurence of "m"
 * in "aeioum", therefore the return value is 1.
 * 
 * str: aeioum
 * trgt_chars: am
 * returns 2
 * 
 * There is one occurence of "a" and "m", the sum of these occurences is 2,
 * therefore this function returns 2.
 */
size_t textproc_letterset_count(char *str, char *trgt_chars);

/*
 * Same as textproc_letterset_count, but with an additional str_l variable to
 * explicitly specify the size of str.
 * 
 * textproc_letterset_count calls this function, with the return value of
 * strlen with str as the argument to strlen passed to the str_l variable.
 */
size_t textproc_letterset_count_n(char *str, char *trgt_chars, size_t str_l);


/*****************************************************************************/
/** CHARACTER TABLE TRANSLATION FUNCTIONS ************************************/
/*
 * The purpose of these functions is to establish a lookup table to convert
 * characters (i.e the string AB becomes Alfa Bravo when sent through a NATO
 * character table translation function.)
 * 
 * Please use chartbl instead of chartable to prevent misleading-sounding
 * names (chartable may be interpreted as the English word chartable, as in
 * something that can be charted). tbl is clearly an abbreviation for table
 * and will eliminate ambiguity.
 */

typedef struct chartbl_lookup_row_t {
  char key;    /* Key (e.g A)      */
  char* value; /* Value (e.g Alfa) */
} chartbl_lookup_row;

/**
 * Translate all characters that can be translated in str based on a lookup
 * table supplied via the `clr` argument, and write the result to out. If
 * out_siz is 0, this function returns the size of the buffer required to
 * accomodate the translated version.
 */
size_t textproc_chartbl_translate(
  char* str,
  char* out,
  size_t out_siz,
  const chartbl_lookup_row* clr
);

/**
 * Same as textproc_chartbl_translate_n, but with an additional bufsiz
 * parameter, specifying the size of str.
 */
size_t textproc_chartbl_translate_n(
  char* str,
  char* out,
  size_t bufsiz,
  size_t out_siz,
  const chartbl_lookup_row* clr
);

/**
 * Translate a single character, and write the translated version to out. If
 * out_siz is 0, this function returns the size of the buffer required to
 * accomodate the translated version
 * 
 * Examples:
 * Assuming a table of a -> Alfa, b -> Bravo, and c -> Charlie, and parameters
 * marked ? are insignificant:
 *
 * 'a', ?, (valid), 0 -> 5
 * 'a', ?, (valid), 5 -> 0 ('Alfa' is written to the `(valid)` char*).
 */
int textproc_chartbl_translate_char(
  char c,
  size_t clr_siz,
  char* out,
  size_t out_siz,
  const chartbl_lookup_row* clr
);

/**** Ciphers ****/

/**
 * Write a version of str encoded using the NATO phonetic alphabet to out.
 *
 * Example: ab -> Alfa Bravo.
 */
size_t textproc_nato_translate(char* str, char* out, size_t outsiz);

/**
 * Write a version of str encoded using the NATO phonetic alphabet to out.
 * This function has an additional bufsiz parameter, for explicitly
 * specifying the size of str.
 */
size_t textproc_nato_translate_n(char* str, char* out,
                                  size_t outsiz, size_t bufsiz);

/**
 * Write a Morse code version of str to out.
 */
size_t textproc_morse_encode(char* str, char* out, size_t outsiz);

/**
 * Same as textproc_morse_encode, with an additional bufsiz
 * parameter for the size of str.
 */
size_t textproc_morse_encode_n(char* str, char* out, size_t outsiz,
                            size_t bufsiz);

/*****************************************************************************/

#ifdef TEXTPROC_INCLUDE_STRNCPY_NT
/*
 * Wrapper function for strcpy(), automatically terminates new strings
 * with a NULL character.
 */
char* tp_strncpyn(char* dest, const char* src, size_t n);
#endif

#endif /* TEXTPROC_H */
