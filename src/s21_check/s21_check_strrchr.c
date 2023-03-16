#include "s21_check.h"

START_TEST(test1) {
  char *str1 = "zzzaba";
  char *empty = "";
  for (int c = 0; c < 127; c++) {
    ck_assert_ptr_eq(strrchr(str1, c), s21_strrchr(str1, c));
    ck_assert_ptr_eq(strrchr(empty, c), s21_strrchr(empty, c));
  }
}
END_TEST

Suite *s21_strrchr_suite() {
  Suite *suite = suite_create("strrchr");
  TCase *tcase_core = tcase_create("strrchr");

  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
