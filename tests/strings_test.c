#include "strings.h"
#include "unity.h"
#include <stdlib.h>

void setUp(void) {}

void tearDown(void) {}

void string_reverse_test(void) {
  char reversed[] = "something";
  revstr(reversed);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(reversed, "gnihtemos", 9);

  // Show that we don't crash!
  revstr(NULL);
}

void string_reverse_copy_test(void) {
  char str[] = "another something";
  char *reversed = revstr_copy(str);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(reversed, "gnihtemos rehtona", 18);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str, "another something", 9);
  TEST_ASSERT_NULL(revstr_copy(NULL));

  free(reversed);
}

void string_length_test(void) {
  TEST_ASSERT_EQUAL_INT(strlength("something"), 9);
  TEST_ASSERT_EQUAL_INT(strlength("hello"), 5);
  TEST_ASSERT_EQUAL_INT(strlength(NULL), 0);
  TEST_ASSERT_EQUAL_INT(strlength(""), 0);
}

void string_str_slice_test(void) {
  char str[] = "Hello, World";
  char str2[] = "This is a longer string, which is going to test if there is a "
                "memory leak when getting a str_slice from it.";
  char *sub1 = str_slice(str, 0, 5);
  char *sub2 = str_slice(str, 5, -1);
  char *sub3 = str_slice(str2, 10, -1);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(sub1, "Hello", 5);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(sub2, ", World", 7);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(
      sub3,
      "longer string, which is going to test if there is a memory leak when "
      "getting a str_slice from it.",
      98);
  TEST_ASSERT_NULL(str_slice(str, 5, 3));
  TEST_ASSERT_NULL(str_slice(str, 5, 15));

  free(sub1);
  free(sub2);
  free(sub3);
}

void string_ends_with_test(void) {
  TEST_ASSERT_EQUAL_INT(str_ends_with("Ice Cream", "ream"), 1);
  TEST_ASSERT_EQUAL_INT(str_ends_with("Superman", "uper"), 0);
}

void string_char_index_test(void) {
  TEST_ASSERT_EQUAL_INT(char_index("What's up?", '?'), 9);
  TEST_ASSERT_EQUAL_INT(char_index("Umbrella", '?'), -1);
  TEST_ASSERT_EQUAL_INT(char_index(NULL, '?'), -1);
}

void string_index_test(void) {
  TEST_ASSERT_EQUAL_INT(str_index("Hello", "ell"), 1);
  TEST_ASSERT_EQUAL_INT(str_index("Bye", "Byebye"), -1);
  TEST_ASSERT_EQUAL_INT(str_index("bellelk", "elk"), 4);
  TEST_ASSERT_EQUAL_INT(str_index("apple", "banana"), -1);
}

void string_equal_test(void) {
  TEST_ASSERT_EQUAL_INT(streql("yoyo", "yoyo"), 1);
  TEST_ASSERT_EQUAL_INT(streql(NULL, NULL), 0);
  TEST_ASSERT_EQUAL_INT(streql("banana", NULL), 0);
  TEST_ASSERT_EQUAL_INT(streql(NULL, "water"), 0);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(string_reverse_test);
  RUN_TEST(string_reverse_copy_test);
  RUN_TEST(string_length_test);
  RUN_TEST(string_str_slice_test);
  RUN_TEST(string_ends_with_test);
  RUN_TEST(string_char_index_test);
  RUN_TEST(string_index_test);
  RUN_TEST(string_equal_test);
  return UNITY_END();
}
