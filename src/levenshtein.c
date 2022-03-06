#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <textproc.h>

/*
 * Based on https://github.com/wooorm/levenshtein.c
 */

size_t textproc_levenshtein_n(char *s1, size_t s1l, char *s2, size_t s2l)
{
  size_t idx1 = 0;
  size_t idx2 = 0;
  size_t dist1 = 0;
  size_t dist2 = 0;
  size_t result;
  size_t* mtrx = calloc(s1l, sizeof(size_t));
  char code;

  while (idx1 < s1l) {
    mtrx[idx1] = idx1 + 1;
    idx1++;
  }

  while (idx2 < s2l) {
    code = s2[idx2];
    result = dist1 = idx2++;
    idx1 = SIZE_MAX;
    while (++idx1 < s1l) {
      if (code == s1[idx1]) {
        dist2 = dist1;
      }
      else {
        dist2 = dist1 + 1;
      }

      dist1 = mtrx[idx1];

      mtrx[idx1] = result = dist1 > result ? dist2 > result ? result + 1 : dist2
                                           : dist2 > dist1 ? dist1 + 1 : dist2;
    }
  }

  free(mtrx);

  return result;
}

size_t textproc_levenshtein(char *s1, char *s2)
{
  return textproc_levenshtein_n(s1, strlen(s1), s2, strlen(s2));
}
