#include <textproc.h>
#include <unitytest/unity.h>

void setUp() {}
void tearDown() {}


void test_nato_alphabet()
{
  char* str = "ab";

  char out[30];

  textproc_nato_translate_n(str, out, 30, 3);

  TEST_ASSERT_EQUAL_STRING("Alfa Bravo", out);
}


int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_nato_alphabet);
  return UNITY_END();
}
