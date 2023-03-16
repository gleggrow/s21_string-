#include "s21_check.h"

START_TEST(test1) {
  char src[20] = "abradabra";
  char res[20] = "abrakadabra";
  char str[20] = "ka";
  s21_size_t position = 4;
  char *result;
  result = s21_insert(src, str, position);
  for (int i = 0; i < strlen(result); i++) {
    ck_assert(result[i] == res[i]);
  }
  free(result);
  result = s21_insert(src, s21_NULL, position);
  ck_assert(result == s21_NULL);
  free(result);
  result = s21_insert(s21_NULL, str, position);
  ck_assert(result == s21_NULL);
  free(result);
  result = s21_insert(src, str, 10);
  ck_assert(result == s21_NULL);
  free(result);
}
END_TEST

Suite *s21_insert_suite() {
  Suite *suite = suite_create("insert");
  TCase *tcase_core = tcase_create("insert");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}