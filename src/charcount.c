#include <string.h>
#include <textproc.h>

#define TEXTPROC_EN_VOWELS "aeiou"
#define TEXTPROC_EN_CONSONANTS "bcdfghjklmnpqrstvwxyz"

size_t textproc_en_vowel_count(char *str)
{
  return textproc_letterset_count(str, TEXTPROC_EN_VOWELS);
}

size_t textproc_en_consonant_count(char *str)
{
  return textproc_letterset_count(str, TEXTPROC_EN_CONSONANTS);
}

size_t textproc_letterset_count(char *str, char *trgt_chars)
{
  return textproc_letterset_count_n(str, trgt_chars, strlen(str));
}

size_t textproc_letterset_count_n(char *str, char *trgt_chars, size_t str_l)
{
  size_t i;
  size_t j;
  size_t found_chars;

  /* [t]rgt_[c]hars_[l]ength */
  size_t tc_l = strlen(trgt_chars);

  for (i = 0; i < str_l; i++) {
    for (j = 0; j < tc_l; j++) {
      if (str[i] == trgt_chars[j]) {
        found_chars++;
      }
    }
  }

  return found_chars;
}
