#include "s21_check.h"

START_TEST(test1) {
  char str[20] = "abradabra12345";
  char str2[20] = "ABRADABRA12345";
  char *result = s21_to_upper(str);
  for (int i = 0; i < strlen(str2); i++) {
    ck_assert(result[i] == str2[i]);
  }
  free(result);
  result = s21_to_upper(s21_NULL);
  ck_assert(result == s21_NULL);
  free(result);
}
END_TEST

Suite *s21_to_upper_suite() {
  Suite *suite = suite_create("to_upper");
  TCase *tcase_core = tcase_create("to_upper");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}