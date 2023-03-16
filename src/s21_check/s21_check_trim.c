#include "s21_check.h"

START_TEST(test1) {
  char res[40] = "RADabra12345";
  char str[40] = "abRADabra12345bab";
  char str2[40] = "abRADabra12345bab\0";
  char tr[5] = "ba";
  char *result = trim(str, tr);
  for (int i = 0; i < strlen(result); i++) {
    ck_assert(result[i] == res[i]);
  }
  free(result);
  result = trim(s21_NULL, tr);
  ck_assert(result == s21_NULL);
  free(result);
  result = trim('\0', tr);
  ck_assert(result == s21_NULL);
  free(result);
  result = trim(str2, "\0");
  for (int i = 0; i < strlen(str2); i++) {
    ck_assert(result[i] == str2[i]);
  }
  free(result);
}
END_TEST

Suite *s21_trim_suite() {
  Suite *suite = suite_create("trim");
  TCase *tcase_core = tcase_create("trim");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}