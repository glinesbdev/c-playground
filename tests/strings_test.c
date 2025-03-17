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
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str, "another something", 18);
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

void string_starts_with_test(void) {
  TEST_ASSERT_EQUAL_INT(str_starts_with("Ice Cream", "Ice"), 1);
  TEST_ASSERT_EQUAL_INT(str_starts_with("Superman", "man"), 0);
  TEST_ASSERT_EQUAL_INT(str_starts_with("Superman", "Ssssuperman"), 0);
  TEST_ASSERT_EQUAL_INT(str_starts_with(NULL, NULL), 0);
  TEST_ASSERT_EQUAL_INT(str_starts_with("Something", NULL), 0);
  TEST_ASSERT_EQUAL_INT(str_starts_with(NULL, "Something"), 0);
}

void string_ends_with_test(void) {
  TEST_ASSERT_EQUAL_INT(str_ends_with("Ice Cream", "ream"), 1);
  TEST_ASSERT_EQUAL_INT(str_ends_with("Superman", "uper"), 0);
  TEST_ASSERT_EQUAL_INT(str_ends_with("Superman", "Ssssuperman"), 0);
  TEST_ASSERT_EQUAL_INT(str_ends_with(NULL, NULL), 0);
  TEST_ASSERT_EQUAL_INT(str_ends_with("Something", NULL), 0);
  TEST_ASSERT_EQUAL_INT(str_ends_with(NULL, "Something"), 0);
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

void string_str_trim_test(void) {
  char str[] = "   Hello, there  ";
  char *trimmed = str_trim(str);

  char str2[] = "Space in back    ";
  char *trimmed2 = str_trim(str2);

  char str3[] = "     Space in front";
  char *trimmed3 = str_trim(str3);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed, "Hello, there", 13);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed2, "Space in back", 14);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed3, "Space in front", 15);

  free(trimmed);
  free(trimmed2);
  free(trimmed3);
}

void string_str_trim_start_test(void) {
  char str[] = "   Hello, there";
  char *trimmed = str_trim_start(str);

  char str2[] = "Space in back    ";
  char *trimmed2 = str_trim_start(str2);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed, "Hello, there", 13);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed2, "Space in back    ", 14);

  free(trimmed);
  free(trimmed2);
}

void string_str_trim_end_test(void) {
  char str[] = "Hello, there   ";
  char *trimmed = str_trim_end(str);

  char str2[] = "    Space in front";
  char *trimmed2 = str_trim_end(str2);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed, "Hello, there", 13);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(trimmed2, "    Space in front", 19);

  free(trimmed);
  free(trimmed2);
}

void string_str_lower_test(void) {
  char str[] = "THIS SHOULD BE LOWER CASE!";
  str_lower(str);

  char str2[] = "This should ALSO be LoWeR casE!";
  str_lower(str2);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(str, "this should be lower case!", 27);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str2, "this should also be lower case!", 32);
}

void string_str_upper_test(void) {
  char str[] = "this should be upper case!";
  str_upper(str);

  char str2[] = "THIS should ALSO be uPpEr Case!";
  str_upper(str2);

  TEST_ASSERT_EQUAL_CHAR_ARRAY(str, "THIS SHOULD BE UPPER CASE!", 27);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str2, "THIS SHOULD ALSO BE UPPER CASE!", 32);
}

void string_str_append_test(void) {
  char *str = str_append("One day, a boy went", " out to eat at a restaurant");
  char *str2 = str_append("This is all she wrote", NULL);
  char *str3 = str_append(NULL, "kinda magic, right?");

  TEST_ASSERT_EQUAL_CHAR_ARRAY(
      str, "One day, a boy went out to eat at a restaurant", 47);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str2, "This is all she wrote", 22);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str3, "kinda magic, right?", 20);

  free(str);
  free(str2);
  free(str3);
}

void string_str_prepend_test(void) {
  char *str = str_prepend(" and this is in back", "This is in front");
  char *str2 = str_prepend("This is all she wrote", NULL);
  char *str3 = str_prepend(NULL, "kinda magic, right?");

  TEST_ASSERT_EQUAL_CHAR_ARRAY(str, "This is in front and this is in back", 37);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str2, "This is all she wrote", 22);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str3, "kinda magic, right?", 20);

  free(str);
  free(str2);
  free(str3);
}

void string_str_pad_start(void) {
  char *padded = str_pad_start("123", 8, "xyz");
  char *padded2 = str_pad_start("1234567890", 15, "*");

  TEST_ASSERT_EQUAL_CHAR_ARRAY(padded, "xyzxy123", 8);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(padded2, "*****1234567890", 15);
  TEST_ASSERT_NULL(str_pad_end("123", 1, "0"));

  free(padded);
  free(padded2);
}

void string_str_pad_end(void) {
  char *padded = str_pad_end("123", 8, "xyz");
  char *padded2 = str_pad_end("1234567890", 15, "*");

  TEST_ASSERT_EQUAL_CHAR_ARRAY(padded, "123xyzxy", 8);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(padded2, "1234567890*****", 15);
  TEST_ASSERT_NULL(str_pad_end("123", 1, "0"));

  free(padded);
  free(padded2);
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
  RUN_TEST(string_str_trim_test);
  RUN_TEST(string_str_trim_start_test);
  RUN_TEST(string_str_trim_end_test);
  RUN_TEST(string_str_lower_test);
  RUN_TEST(string_str_upper_test);
  RUN_TEST(string_str_append_test);
  RUN_TEST(string_str_prepend_test);
  RUN_TEST(string_str_pad_start);
  RUN_TEST(string_str_pad_end);
  return UNITY_END();
}
