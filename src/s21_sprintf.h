#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#define flags_counter 3
#define flag_plus 0
#define flag_minus 1
#define flag_space 2
#define specifiers_counter (6 + 1)
#define specs_parm "cdifsu"
#define length_counter 2
#define length_l 1
#define length_h 0

#include <stdarg.h>

#include "s21_string.h"

typedef struct s21_string {
  char *letter;
  s21_size_t length;
} s21_string;

typedef struct line_parameters {
  int flag[flags_counter];
  s21_size_t width;
  s21_size_t precision;
  s21_size_t precision_is_set;
  int length[length_counter];
  char specifier;
} line_parameters;

void add_letter(s21_string *new_string, char symbol);
void paste_arg(s21_string *new_string, const char *format, s21_size_t *position,
               va_list pointer);
void init_parameters(line_parameters *new_line_parameters);
void check_flag(line_parameters *new_line_parameters, const char *format,
                s21_size_t *position);
void check_width(line_parameters *new_line_parameters, const char *format,
                 s21_size_t *position);
void check_precision(line_parameters *new_line_parameters, const char *format,
                     s21_size_t *position);
void check_length(line_parameters *new_line_parameters, const char *format,
                  s21_size_t *position);
void check_specifier(line_parameters *new_line_parameters, const char *format,
                     s21_size_t *position);
void change_new_string(line_parameters new_line_parameters,
                       s21_string *new_string, va_list pointer);
void handle_char(line_parameters new_line_parameters, s21_string *new_string,
                 va_list pointer);
void handle_string(line_parameters new_line_parameters, s21_string *new_string,
                   va_list pointer);
void handle_int(line_parameters new_line_parameters, s21_string *new_string,
                va_list pointer);
void handle_double(line_parameters new_line_parameters, s21_string *new_string,
                   va_list pointer);
void calculate_int_length(long long int number, int *letters_amount);
void add_int_to_string(long long int number, int letters_amount,
                       s21_string *new_string);
void handle_int_start_sign_flags(line_parameters new_line_parameters,
                                 s21_string *new_string, long long int number);
void handle_double_start_sign_flags(line_parameters new_line_parameters,
                                    s21_string *new_string, double number);
void add_double_to_string(double number, int *left_letters_counter,
                          s21_size_t precision, s21_string *new_string);
int take_tens(long long int num);
void *create_str(s21_size_t number, char symbol);
void add_string(s21_string *new_string, char *str);
void *s21_insert_width(s21_string new_string, const char *str,
                       s21_size_t length_str, s21_size_t start_index);
void add_width_chars(line_parameters new_line_parameters,
                     s21_string *new_string, s21_size_t start_position);
#endif  // SRC_S21_SPRINTF_H_