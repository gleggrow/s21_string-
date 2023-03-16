CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11 $(shell pkg-config --cflags check)
TST_LIBS = $(shell pkg-config --libs check)
LIB = s21_string
LIB2 = s21_sprintf
TEST = test

all:$(LIB).a

$(TEST): gcov$(LIB).a
	$(CC) s21_check/*.c -c -g
	$(CC) $(FLAGS) *.o -L. gcov$(LIB).a --coverage $(TST_LIBS) -o $(TEST)
	rm -rf *.o *.a

$(LIB).a: *.c $(LIB).h $(LIB2).h
	$(CC) -c *.c
	ar rc $(LIB).a *.o
	ranlib $(LIB).a

gcov$(LIB).a: *.c $(LIB).h $(LIB2).h
	$(CC) -c *.c --coverage $(TST_LIBS) $(FLAGS) -g
	ar rc gcov$(LIB).a *.o
	ranlib gcov$(LIB).a
	rm -rf *.o

gcov_report:$(TEST)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf *.gcda *.gcno $(TEST)
	make show_report

memory_test_linux:$(TEST)
	valgrind --quiet ./test

memory_test_mac:$(TEST)
	leaks -atExit -- ./test

all_tests_linux:style_test memory_test_linux
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf *.gcda *.gcno $(TEST)
	make show_report

all_tests_mac:style_test memory_test_mac
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf *.gcda *.gcno $(TEST)
	make show_report

show_report: report/index.html
	chmod +x show.sh
	./show.sh

clean:
	rm -rf *.o $(TEST) *.a test.info report *.gcda *.gcno

rebuild: clean $(LIB).a

style:
	clang-format -i -style=Google *.c *.h s21_check/*.c s21_check/*.h

style_test:
	clang-format -n -style=Google *.c *.h s21_check/*.c s21_check/*.h