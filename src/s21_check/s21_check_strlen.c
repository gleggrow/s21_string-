#include "s21_check.h"

START_TEST(test1) {
  char dest[] = "123456789105645";
  ck_assert(strlen(dest) == s21_strlen(dest));
}
END_TEST

Suite *s21_strlen_suite() {
  Suite *suite = suite_create("strlen");
  TCase *tcase_core = tcase_create("strlen");

  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
