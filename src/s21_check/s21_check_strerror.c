#include "s21_check.h"

START_TEST(test1) {
  char *s21_res;
  char *res;
  for (int i = -1; i <= ERR_LEN; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(2147483647), strerror(2147483647));
  ck_assert_str_eq(s21_strerror(-2147483647), strerror(-2147483647));
}
END_TEST

Suite *s21_strerror_suite() {
  Suite *suite = suite_create("strerror");
  TCase *tcase_core = tcase_create("strerror");

  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
