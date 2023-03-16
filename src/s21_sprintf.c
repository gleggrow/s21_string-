#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  s21_string new_string;
  va_list pointer;
  va_start(pointer, format);
  new_string.letter = s21_NULL;
  new_string.length = 0;
  for (s21_size_t i = 0; format[i]; i++) {
    if (format[i] == '%') {
      i++;
      if (format[i] != '%') {
        paste_arg(&new_string, format, &i, pointer);
      } else {
        add_letter(&new_string, format[i]);
      }
    } else {
      add_letter(&new_string, format[i]);
    }
  }
  add_letter(&new_string, '\0');
  va_end(pointer);
  for (s21_size_t i = 0; i < new_string.length; i++) {
    str[i] = new_string.letter[i];
  }
  if (new_string.letter != s21_NULL) free(new_string.letter);
  if (new_string.length != 0) {
    new_string.length = (int)new_string.length - 1;
  }
  return new_string.length;
}

void add_letter(s21_string *new_string, char symbol) {
  char *tmp = s21_NULL;
  new_string->length = new_string->length + 1;
  while ((tmp = realloc(tmp, sizeof(char) * new_string->length + 1)) ==
         s21_NULL) {
  }
  for (s21_size_t i = 0;
       i < new_string->length && new_string->letter != s21_NULL; i++) {
    tmp[i] = new_string->letter[i];
  }
  tmp[new_string->length - 1] = symbol;
  if (new_string->letter != s21_NULL) free(new_string->letter);
  new_string->letter = tmp;
}
void paste_arg(s21_string *new_string, const char *format, s21_size_t *position,
               va_list pointer) {
  // [flags][width][.precision][length]specifier
  line_parameters new_line_parameters;
  init_parameters(&new_line_parameters);
  check_flag(&new_line_parameters, format, position);
  check_width(&new_line_parameters, format, position);
  check_precision(&new_line_parameters, format, position);
  check_length(&new_line_parameters, format, position);
  check_specifier(&new_line_parameters, format, position);
  change_new_string(new_line_parameters, new_string, pointer);
}
void init_parameters(line_parameters *new_line_parameters) {
  for (int i = 0; i < flags_counter; i++) {
    new_line_parameters->flag[i] = 0;
  }
  new_line_parameters->width = 0;
  new_line_parameters->precision = 6;
  new_line_parameters->precision_is_set = 0;
  for (int i = 0; i < length_counter; i++) {
    new_line_parameters->length[i] = 0;
  }
  new_line_parameters->specifier = '\0';
}
void check_flag(line_parameters *new_line_parameters, const char *format,
                s21_size_t *position) {
  while (format[*position] == '-' || format[*position] == '+' ||
         format[*position] == ' ') {
    if (format[*position] == '-') {
      new_line_parameters->flag[flag_minus] = 1;
    } else if (format[*position] == '+') {
      new_line_parameters->flag[flag_plus] = 1;
    } else {
      new_line_parameters->flag[flag_space] = 1;
    }
    *position += 1;
  }
  if (new_line_parameters->flag[flag_plus]) {
    new_line_parameters->flag[flag_space] = 0;
  }
}
void check_width(line_parameters *new_line_parameters, const char *format,
                 s21_size_t *position) {
  for (s21_size_t i = 0; format[*position] >= '0' && format[*position] <= '9';
       i++, *position += 1) {
    if (i > 0) {
      new_line_parameters->width *= 10;
    }
    new_line_parameters->width += (format[*position] - '0');
  }
}
void check_precision(line_parameters *new_line_parameters, const char *format,
                     s21_size_t *position) {
  if (format[*position] == '.') {
    new_line_parameters->precision_is_set = 1;
    new_line_parameters->precision = 0;
    *position += 1;
    for (s21_size_t i = 0; format[*position] >= '0' && format[*position] <= '9';
         i++, *position += 1) {
      if (i > 0) {
        new_line_parameters->precision *= 10;
      }
      new_line_parameters->precision += (format[*position] - '0');
    }
  }
  if (new_line_parameters->precision) {
    new_line_parameters->precision += 1;
  }
}
void check_length(line_parameters *new_line_parameters, const char *format,
                  s21_size_t *position) {
  while (format[*position] == 'h' || format[*position] == 'l') {
    if (format[*position] == 'h') {
      new_line_parameters->length[length_h] += 1;
    } else {
      new_line_parameters->length[length_l] += 1;
    }
    *position += 1;
  }
}
void check_specifier(line_parameters *new_line_parameters, const char *format,
                     s21_size_t *position) {
  char specifiers[specifiers_counter] = specs_parm;
  for (int i = 0; i < specifiers_counter; i++) {
    if (format[*position] == specifiers[i]) {
      new_line_parameters->specifier = format[*position];
      break;
    }
  }
}
void change_new_string(line_parameters new_line_parameters,
                       s21_string *new_string, va_list pointer) {
  switch (new_line_parameters.specifier) {
    case 'c':
      handle_char(new_line_parameters, new_string, pointer);
      break;
    case 'd':
      handle_int(new_line_parameters, new_string, pointer);
      break;
    case 'i':
      handle_int(new_line_parameters, new_string, pointer);
      break;
    case 'f':
      handle_double(new_line_parameters, new_string, pointer);
      break;
    case 's':
      handle_string(new_line_parameters, new_string, pointer);
      break;
    case 'u':
      handle_int(new_line_parameters, new_string, pointer);
      break;
  }
}
void handle_char(line_parameters new_line_parameters, s21_string *new_string,
                 va_list pointer) {
  char letter = va_arg(pointer, int);
  long long int padding = new_line_parameters.width - 1;
  if (new_line_parameters.flag[flag_minus]) {
    add_letter(new_string, letter);
  }
  for (s21_size_t i = 0; i < (s21_size_t)padding && padding > 0; i++) {
    add_letter(new_string, ' ');
  }
  if (new_line_parameters.flag[flag_minus] == 0) {
    add_letter(new_string, letter);
  }
}
void handle_string(line_parameters new_line_parameters, s21_string *new_string,
                   va_list pointer) {
  char *string = va_arg(pointer, char *);
  long long int padding = new_line_parameters.width - s21_strlen(string);
  if (new_line_parameters.precision_is_set &&
      (new_line_parameters.precision - 1 < s21_strlen(string)))
    padding += (s21_strlen(string) - new_line_parameters.precision + 1);
  if (new_line_parameters.flag[flag_minus]) {
    for (s21_size_t i = 0;
         string[i] && ((i < new_line_parameters.precision - 1) ||
                       new_line_parameters.precision_is_set == 0);
         i++) {
      add_letter(new_string, string[i]);
    }
  }
  for (s21_size_t i = 0; i < (s21_size_t)padding && padding > 0; i++) {
    add_letter(new_string, ' ');
  }
  if (new_line_parameters.flag[flag_minus] == 0) {
    for (s21_size_t i = 0;
         string[i] && ((i < new_line_parameters.precision - 1) ||
                       new_line_parameters.precision_is_set == 0);
         i++) {
      add_letter(new_string, string[i]);
    }
  }
}
void handle_int(line_parameters new_line_parameters, s21_string *new_string,
                va_list pointer) {
  s21_size_t start_position = new_string->length;
  int letters_amount = 0;
  long long int number = va_arg(pointer, long long int);
  if (new_line_parameters.length[length_l] == 1) {
    number = (long)number;
  } else if (new_line_parameters.length[length_h] == 1) {
    number = (short)number;
  } else if (new_line_parameters.length[length_h] == 2) {
    number = (char)number;
  } else {
    number = (int)number;
  }
  if (new_line_parameters.specifier == 'u') {
    number = (unsigned)number;
  }
  calculate_int_length(number, &letters_amount);
  if (number < 0 || new_line_parameters.flag[flag_plus] ||
      new_line_parameters.flag[flag_space]) {
    new_line_parameters.width -= 1;
  }
  new_line_parameters.width -= letters_amount;
  if (letters_amount == 0) {
    new_line_parameters.width -= 1;
  }
  handle_int_start_sign_flags(new_line_parameters, new_string, number);
  add_int_to_string(number, letters_amount, new_string);
  add_width_chars(new_line_parameters, new_string, start_position);
}
void handle_int_start_sign_flags(line_parameters new_line_parameters,
                                 s21_string *new_string, long long int number) {
  if (number < 0) {
    add_letter(new_string, '-');
  } else if (new_line_parameters.flag[flag_plus]) {
    add_letter(new_string, '+');
  } else if (new_line_parameters.flag[flag_space]) {
    add_letter(new_string, ' ');
  }
}
void calculate_int_length(long long int number, int *letters_amount) {
  while (number) {
    *letters_amount += 1;
    number /= 10;
  }
}
void add_int_to_string(long long int number, int letters_amount,
                       s21_string *new_string) {
  char *tmp = s21_NULL;
  while ((tmp = malloc(sizeof(char) * letters_amount)) == s21_NULL) {
  }
  if (number < 0) {
    number = -number;
  }
  for (int i = 0; i < letters_amount; i++) {
    tmp[i] = number % 10 + '0';
    number /= 10;
  }
  if (letters_amount == 0) {
    add_letter(new_string, '0');
  } else if (letters_amount > 0) {
    for (int i = letters_amount - 1; i >= 0; i--) {
      add_letter(new_string, tmp[i]);
    }
  }
  if (tmp != s21_NULL) free(tmp);
}
void handle_double(line_parameters new_line_parameters, s21_string *new_string,
                   va_list pointer) {
  double number = va_arg(pointer, double);
  int left_letters_counter = 0;
  s21_size_t start_position = new_string->length;
  new_line_parameters.width -= new_line_parameters.precision;
  if (number < 0 || new_line_parameters.flag[flag_plus] ||
      new_line_parameters.flag[flag_space]) {
    new_line_parameters.width -= 1;
  }
  handle_double_start_sign_flags(new_line_parameters, new_string, number);
  add_double_to_string(number, &left_letters_counter,
                       new_line_parameters.precision, new_string);
  new_line_parameters.width -= left_letters_counter;
  add_width_chars(new_line_parameters, new_string, start_position);
}
void handle_double_start_sign_flags(line_parameters new_line_parameters,
                                    s21_string *new_string, double number) {
  if (number < 0) {
    add_letter(new_string, '-');
  } else if (new_line_parameters.flag[flag_plus]) {
    add_letter(new_string, '+');
  } else if (new_line_parameters.flag[flag_space]) {
    add_letter(new_string, ' ');
  }
}
void add_double_to_string(double number, int *left_letters_counter,
                          s21_size_t precision, s21_string *new_string) {
  char *tmp = s21_NULL;
  long long int ratio = 1;
  for (s21_size_t i = 1; i < precision; i++) {
    ratio *= 10;
  }
  long double number_clone = number;
  int booster = (long long int)(number_clone * ratio * 10) % 10 / 5;
  long long int tmp_int_number = (long long int)(number_clone * ratio);
  long long int int_number = tmp_int_number + booster;
  calculate_int_length(int_number / ratio, left_letters_counter);
  while ((tmp = malloc(sizeof(char) * (*left_letters_counter + precision))) ==
         s21_NULL) {
  }
  if (int_number < 0) {
    int_number = -int_number;
  }
  if ((int)number == 0 && take_tens(int_number) == take_tens(tmp_int_number)) {
    add_letter(new_string, '0');
  }
  for (s21_size_t i = 0; i < (*left_letters_counter + precision); i++) {
    if (i == precision - 1 && i != 0) {
      tmp[i] = '.';
    } else {
      tmp[i] = int_number % 10 + '0';
      int_number /= 10;
    }
  }
  for (int i = (*left_letters_counter + precision) - 1; i >= 0; i--) {
    add_letter(new_string, tmp[i]);
  }
  if (tmp != s21_NULL) free(tmp);
}
int take_tens(long long int num) {
  int res = 0;
  for (; num; num /= 10, res++)
    ;
  return res;
}
void *create_str(s21_size_t number, char symbol) {
  char *str = s21_NULL;
  if (number > 0) {
    while ((str = malloc(sizeof(char) * (number + 1))) == s21_NULL) {
    }
    for (s21_size_t i = 0; i < number; i++) {
      str[i] = symbol;
    }
    str[number] = '\0';
  }
  return str;
}
void add_string(s21_string *new_string, char *str) {
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    add_letter(new_string, str[i]);
  }
}
void *s21_insert_width(s21_string new_string, const char *str,
                       s21_size_t length_str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  s21_size_t length_new_string = 0;
  if (new_string.letter != s21_NULL && str != s21_NULL) {
    length_new_string = new_string.length;
  }
  if (start_index < (length_new_string + 1) &&
      (long long int)start_index >= 0) {
    new_str = malloc(sizeof(char) * (length_new_string + length_str + 1));
    for (s21_size_t i = 0, j = 0, k = 0; i < length_new_string + length_str;
         i++) {
      if (i == start_index && k < length_str) {
        new_str[i] = str[k];
        k++;
        start_index++;
      } else {
        new_str[i] = new_string.letter[j];
        j++;
      }
    }
  }
  return new_str;
}
void add_width_chars(line_parameters new_line_parameters,
                     s21_string *new_string, s21_size_t start_position) {
  char *final_str = s21_NULL, *width_str = s21_NULL, *tmp = s21_NULL;
  if ((int)new_line_parameters.width > 0) {
    width_str = create_str(new_line_parameters.width, ' ');
    if (width_str) {
      if (new_line_parameters.flag[flag_minus]) {
        add_string(new_string, width_str);
      } else {
        final_str = s21_insert_width(*new_string, width_str,
                                     new_line_parameters.width, start_position);
      }
      if (width_str != s21_NULL) free(width_str);
    }
    tmp = new_string->letter;
    if (final_str) {
      new_string->letter = final_str;
      new_string->length += new_line_parameters.width;
      if (tmp != s21_NULL) free(tmp);
    } else {
      if (final_str != s21_NULL) free(final_str);
    }
  }
}
