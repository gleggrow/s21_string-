#ifndef SRC_S21_CHECK_H_
#define SRC_S21_CHECK_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_error.h"
#include "../s21_string.h"

void do_suite(Suite *suite, int *res);

Suite *s21_strcmp_suite();
Suite *s21_strncmp_suite();
Suite *s21_strchr_suite();
Suite *s21_strcpy_suite();
Suite *s21_strncpy_suite();
Suite *s21_strstr_suite();
Suite *s21_strncat_suite();
Suite *s21_memcmp_suite();
Suite *s21_memmove_suite();
Suite *s21_strcat_suite();
Suite *s21_strlen_suite();
Suite *s21_strpbrk_suite();
Suite *s21_strspn_suite();
Suite *s21_strerror_suite();
Suite *s21_memset_suite();
Suite *s21_strrchr_suite();
Suite *s21_memchr_suite();
Suite *s21_memcpy_suite();
Suite *s21_strcspn_suite();
Suite *s21_strtok_suite();

Suite *s21_insert_suite();
Suite *s21_to_lower_suite();
Suite *s21_to_upper_suite();
Suite *s21_trim_suite();

Suite *s21_sprintf_suite();
Suite *s21_sprintf_suite2();

#endif  // SRC_S21_CHECK_H_