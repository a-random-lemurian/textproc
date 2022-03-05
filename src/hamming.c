#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t textproc_hamming_distance(char *s1, char *s2)
{
  size_t dist = 0;
  size_t s1_siz = strlen(s1);
  size_t s2_siz = strlen(s2);
  size_t pos;


  if (s1_siz != s2_siz) {
    fprintf(stderr,
            "textproc_hamming_distance: s1 and s2 lengths not same "
            "(s1 len %ld, s2 len %ld)\n",
            s1_siz, s2_siz);
    abort();
  }

  for (pos = 0; pos < (s1_siz + s2_siz) / 2; pos++) {
    if (s1[pos] != s2[pos]) {
      dist++;
    }
  }

  return dist;
}
