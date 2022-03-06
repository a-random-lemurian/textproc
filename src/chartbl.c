#include <stdlib.h>
#include <string.h>
#include <textproc-internal.h>
#include <textproc.h>

size_t __textproc_longest_chartbl_value_len(const chartbl_lookup_row *clr)
{
  return __textproc_longest_chartbl_value_len_n(
      clr, sizeof(chartbl_lookup_row) / sizeof(clr));
}

size_t __textproc_longest_chartbl_value_len_n(const chartbl_lookup_row *clr,
                                              size_t num_tbl_entries)
{
  size_t i;
  size_t highest_siz = 0;
  size_t siz = 0;

  for (i = 0; i < num_tbl_entries; i++) {
    siz = strlen(clr[i].value);
    if (siz > highest_siz) {
      highest_siz = siz;
    }
  }

  return siz;
}

size_t textproc_chartbl_translate(char *str, char *out, size_t out_siz,
                                       const chartbl_lookup_row *clr)
{
  return textproc_chartbl_translate_n(str, out, out_siz, strlen(str), clr);
}

size_t textproc_chartbl_translate_n(char *str, char *out, size_t out_siz,
                                         size_t bufsiz,
                                         const chartbl_lookup_row *clr)
{
  size_t i;

  /*
   * When out_siz is 0, we return the size of the
   * buffer needed to store the translated string,
   * so the calling program can allocate a string
   * that textproc will fill.
   */
  if (out_siz == 0) {

    size_t needed_size = 0;
    size_t char_value_size = 0;

    for (i = 0; i < bufsiz; i++) {
      char_value_size = textproc_chartbl_translate_char(str[i], bufsiz,
                                                        NULL, 0, clr);

      needed_size += char_value_size;
      char_value_size = 0;
    }

    return needed_size;
  }

  for (i = 0; i < bufsiz; i++) {
    size_t needed_siz = textproc_chartbl_translate_char(
        str[i], sizeof(chartbl_lookup_row) / sizeof(clr), NULL, 0, clr);
    char *translated_char = malloc(needed_siz);
    textproc_chartbl_translate_char(str[i],
                                    sizeof(chartbl_lookup_row) / sizeof(clr),
                                    translated_char, needed_siz, clr);

    strcat(out, translated_char);

    free(translated_char);
  }

  return 0;
}

int textproc_chartbl_translate_char(char c, size_t clr_siz,
                                    char* out, size_t out_siz,
                                    const chartbl_lookup_row *clr)
{
  size_t i;

  for (i = 0; i < clr_siz; i++) {
    if (c == clr[i].key) {
      /*
       * As always, out_siz of 0 is interpreted
       * as a request for the size of the array
       * required to store the translated string.
       */
      if (out_siz == 0) {
        return strlen(clr[i].value);
      }
      else {
        strncpy(out, clr[i].value, strlen(clr[i].value));
      }
    }
  }

  return 0;
}
