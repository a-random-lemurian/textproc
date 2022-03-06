#include <textproc.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static chartbl_lookup_row nato_alphabet[26] = {
  {'A', "Alfa "},
  {'B', "Bravo "},
  {'C', "Charlie "},
  {'D', "Delta "},
  {'E', "Echo "},
  {'F', "Foxtrot "},
  {'G', "Golf "},
  {'H', "Hotel "},
  {'I', "India "},
  {'J', "Juliett "},
  {'K', "Kilo "},
  {'L', "Lima "},
  {'M', "Mike "},
  {'N', "November "},
  {'O', "Oscar "},
  {'P', "Papa "},
  {'Q', "Quebec "},
  {'R', "Romeo "},
  {'S', "Sierra "},
  {'T', "Tango "},
  {'U', "Uniform "},
  {'V', "Victor "},
  {'W', "Whiskey "},
  {'X', "X-ray "},
  {'Y', "Yankee "},
  {'Z', "Zulu "}
};

int textproc_nato_translate(char* str, char* out, size_t outsiz)
{
  return textproc_nato_translate_n(str, out, outsiz, strlen(str));
}

int textproc_nato_translate_n(char* str, char* out, size_t outsiz, size_t bufsiz)
{
  char upper_str[bufsiz];

  textproc_upper_string(str, upper_str, bufsiz);

  return textproc_chartbl_translate((char*)upper_str, out, outsiz, nato_alphabet);
}
