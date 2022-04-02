#include <textproc.h>
#include <string.h>
#include <stdio.h>

size_t textproc_common_prefix_2strings(char* str1, char* str2, char* out,
                                       size_t outsiz)
{

  /*
   * Initialize out to NULL if str1 and str2
   * have no common prefix.
   */
  /*out = NULL;*/

  size_t i = 0;
  size_t rc = 0;

  while (str1[i] == str2[i]) {
    /*
     * If outsiz is 0, return the required
     * size of the buffer.
     */
    if (outsiz == 0 || out == NULL) {
      rc++;
    }
    else {
      out[i] = str1[i];
    }

    i++;

    /*
     * Stop filling out with the common prefix
     * characters (if the calling function needs
     * only a few characters of the common prefix,
     * not all of it.).
     */
    if (i > outsiz) {
      break;
    }

  }

  return rc;
}
