#include <textproc.h>
#include <unitytest/unity.h>

void setUp() {}
void tearDown() {}


void test_morse_encode()
{
  char* str = "e";
  char out[2];

  textproc_morse_encode(str, out, 2);

  TEST_ASSERT_EQUAL_STRING(".", out);
}

void test_morse_decode_1tok()
{
  char* str = ".";
  char out[2];

  textproc_morse_decode_n(str, out, 2, 2, " ");

  TEST_ASSERT_EQUAL_STRING("e", out);
}

void test_morse_decode_several_tok()
{
  char* str = ". . . .";
  char out[5];

  textproc_morse_decode_n(str, out, 5, 5, " ");

  TEST_ASSERT_EQUAL_STRING("eeee", out);
}

int main(int argc, char* argv[])
{
  UNITY_BEGIN();
  RUN_TEST(test_morse_encode);
  RUN_TEST(test_morse_decode_1tok);
  RUN_TEST(test_morse_decode_several_tok);
  return UNITY_END();
}
