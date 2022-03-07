#include <textproc.h>
#include <string.h>

const static chartbl_lookup_row morse_code[] = {
  {'0', "----- "},
  {'1', ".---- "},
  {'2', "..--- "},
  {'3', "...-- "},
  {'4', "....- "},
  {'5', "..... "},
  {'6', "-.... "},
  {'7', "--... "},
  {'8', "---.. "},
  {'9', "----. "},
  {'a', ".- "},
  {'b', "-... "},
  {'c', "-.-. "},
  {'d', "-.. "},
  {'e', ". "},
  {'f', "..-. "},
  {'g', "--. "},
  {'h', ".... "},
  {'i', ".. "},
  {'j', ".--- "},
  {'k', "-.- "},
  {'l', ".-.. "},
  {'m', "-- "},
  {'n', "-. "},
  {'o', "--- "},
  {'p', ".--. "},
  {'q', "--.- "},
  {'r', ".-. "},
  {'s', "... "},
  {'t', "- "},
  {'u', "..- "},
  {'v', "...- "},
  {'w', ".-- "},
  {'x', "-..- "},
  {'y', "-.-- "},
  {'z', "--.. "},
  {'.', ".-.-.- "},
  {',', "--..-- "},
  {'?', "..--.. "},
  {'!', "-.-.-- "},
  {'-', "-....- "},
  {'/', "-..-. "},
  {'@', ".--.-. "},
  {'(', "-.--. "},
  {')', "-.--.- "},
};

size_t textproc_morse_encode(char* str, char* out, size_t outsiz)
{
  return textproc_morse_encode_n(str, out, outsiz, strlen(str));
}

size_t textproc_morse_encode_n(char* str, char* out, size_t outsiz, size_t bufsiz)
{
  char lower_str[bufsiz];
  int rc;

  textproc_upper_string(str, lower_str, bufsiz);

  rc = textproc_chartbl_translate((char*)lower_str, out,
                                  outsiz, morse_code);

  return rc;
}

size_t textproc_morse_decode(char* str, char* out, size_t outsiz, char* delim)
{
  return textproc_morse_decode_n(str, out, outsiz, strlen(str), delim);
}

size_t textproc_morse_decode_n(char* str, char* out, size_t outsiz,
                               size_t bufsiz, char* delim)
{
  size_t i;
  size_t rc;
  for (i = 0; i < bufsiz; i++) {
    if (bufsiz == 0) {
      rc += textproc_chartbl_reverse_translate_string(
        str, out, delim, outsiz, 0, morse_code);
    }
    else {
      textproc_chartbl_reverse_translate_string(
        str, out, delim, outsiz, bufsiz, morse_code
      );
    }
  }
}
