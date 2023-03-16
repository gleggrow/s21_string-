#include "s21_check.h"

START_TEST(test1) {
  const char *s = "Abracadabra";
  const char *empty = "";
  ck_assert_ptr_eq(memchr(s, 'c', 100), s21_memchr(s, 'c', 100));
  ck_assert_ptr_eq(memchr(s, 'd', 1), s21_memchr(s, 'd', 1));
  ck_assert_ptr_eq(memchr(s, 'A', 1), s21_memchr(s, 'A', 1));
  ck_assert_ptr_eq(memchr(empty, 'A', 0), s21_memchr(empty, 'A', 0));
  for (char c = -128; c < 127; c++) {
    for (s21_size_t i = 0; i < 15; i++) {
      ck_assert_ptr_eq(memchr(s, c, i), s21_memchr(s, c, i));
      ck_assert_ptr_eq(memchr(empty, c, i), s21_memchr(empty, c, i));
    }
  }
}
END_TEST

Suite *s21_memchr_suite() {
  Suite *suite = suite_create("memchr");
  TCase *tcase_core = tcase_create("memchr");

  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
