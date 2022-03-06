#include <textproc.h>
#include <unitytest/unity.h>

void setUp() {}
void tearDown() {}

void test_vowel_count()
{
  char* str = "arch";

  TEST_ASSERT_EQUAL_size_t(1, textproc_en_vowel_count(str));
}

void test_consonant_count()
{
  char* str = "arch";

  TEST_ASSERT_EQUAL_size_t(3, textproc_en_consonant_count(str));
}

int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_consonant_count);
  RUN_TEST(test_vowel_count);
  return UNITY_END();
}
