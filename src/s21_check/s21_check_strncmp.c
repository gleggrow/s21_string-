#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good";
  char b[30] = "good";
  char c[30] = "bad";
  char d[30] = "goodbad";
  char e[30] = "\0";
  ck_assert((s21_strncmp(a, b, 3) % (s21_strncmp(a, b, 3) + 1)) ==
            (strncmp(a, b, 3) % (strncmp(a, b, 3) + 1)));
  ck_assert((s21_strncmp(a, b, 0) % (s21_strncmp(a, b, 0) + 1)) ==
            (strncmp(a, b, 0) % (strncmp(a, b, 0) + 1)));
  ck_assert((s21_strncmp(a, b, 5) % (s21_strncmp(a, b, 5) + 1)) ==
            (strncmp(a, b, 5) % (strncmp(a, b, 5) + 1)));
  ck_assert((s21_strncmp(a, c, 2) / s21_strncmp(a, c, 2)) ==
            (strncmp(a, c, 2) / strncmp(a, c, 2)));
  ck_assert((s21_strncmp(a, d, 4) % (s21_strncmp(a, d, 4) + 1)) ==
            (strncmp(a, d, 4) % (strncmp(a, d, 4) + 1)));
  ck_assert((s21_strncmp(a, e, 2) / (s21_strncmp(a, e, 2))) ==
            (strncmp(a, e, 2) / (strncmp(a, e, 2))));
  ck_assert((s21_strncmp(e, b, 2) / (s21_strncmp(e, b, 2))) ==
            (strncmp(e, b, 2) / (strncmp(e, b, 2))));
}
END_TEST

Suite *s21_strncmp_suite() {
  Suite *suite = suite_create("strncmp");
  TCase *tcase_core = tcase_create("strncmp");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
