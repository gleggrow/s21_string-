#include "s21_check.h"

void do_suite(Suite *suite, int *res) {
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  *res += srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int res = 0;
  do_suite(s21_strcmp_suite(), &res);
  do_suite(s21_strncmp_suite(), &res);
  do_suite(s21_strchr_suite(), &res);
  do_suite(s21_strcpy_suite(), &res);
  do_suite(s21_strncpy_suite(), &res);
  do_suite(s21_strstr_suite(), &res);
  do_suite(s21_strncat_suite(), &res);
  do_suite(s21_memcmp_suite(), &res);
  do_suite(s21_memmove_suite(), &res);
  do_suite(s21_strcat_suite(), &res);
  do_suite(s21_strlen_suite(), &res);
  do_suite(s21_strpbrk_suite(), &res);
  do_suite(s21_strspn_suite(), &res);
  do_suite(s21_strerror_suite(), &res);
  do_suite(s21_memset_suite(), &res);
  do_suite(s21_strrchr_suite(), &res);
  do_suite(s21_memchr_suite(), &res);
  do_suite(s21_memcpy_suite(), &res);
  do_suite(s21_sprintf_suite(), &res);
  do_suite(s21_sprintf_suite2(), &res);
  do_suite(s21_insert_suite(), &res);
  do_suite(s21_to_lower_suite(), &res);
  do_suite(s21_to_upper_suite(), &res);
  do_suite(s21_trim_suite(), &res);
  do_suite(s21_strcspn_suite(), &res);
  do_suite(s21_strtok_suite(), &res);

  if (res) {
    printf("\e[0;31m");
  } else {
    printf("\e[0;32m");
  }
  return (res == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
