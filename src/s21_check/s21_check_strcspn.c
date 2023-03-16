#include "s21_check.h"

START_TEST(test1) {
  ck_assert(strcspn("this is a test", "isth a") ==
            s21_strcspn("this is a test", "isth a"));
}
END_TEST

START_TEST(test2) {
  ck_assert(strcspn("this is a test", "a") ==
            s21_strcspn("this is a test", "a"));
}
END_TEST

Suite *s21_strcspn_suite() {
  Suite *suite = suite_create("strcspn");
  TCase *tcase_core = tcase_create("strcspn");

  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
