#include <unitytest/unity.h>
#include <textproc.h>
#include <string.h>

void setUp() {}
void tearDown() {}


struct tcase {
  char* expected;
  char* input;
};

struct tcase encode_tcases[] = {
  {"ebg13", "rot13"},
  {"qrovna", "debian"},
  {"69420", "69420"},
  {"vnwdv", "iajqi"},
  {"debian", "qrovna"}
};


void test_rot13_encode_tests(void)
{
  int i;
  for (i = 0; i < sizeof(encode_tcases)/sizeof(encode_tcases[0]); i++) {
    char out[strlen(encode_tcases[i].input) + 1];

    textproc_rot13_encode(
      encode_tcases[i].input, out,
      strlen(encode_tcases[i].input) + 1);

    TEST_ASSERT_EQUAL_STRING(encode_tcases[i].expected, out);
  }
}

void test_rot13_decode_tests(void) {}

int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_rot13_encode_tests);
  RUN_TEST(test_rot13_decode_tests);
  return UNITY_END();
}
