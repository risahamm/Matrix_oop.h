CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17

all: clean check_style s21_matrix_oop.a gcov_report

s21_matrix_oop.a:
	$(CC) $(CFLAGS) *.cc -c
	ar rc s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

test: clean
	$(CC) $(CFLAGS) --coverage *.cc tests/*.cc -lgtest -pthread -o test
	./test

clean:
	rm -rf test *.gcda *.gcno *.o *.info *.a test.dSYM a.out gcov_report

gcov_report: test
	@lcov -t "Test_matrix_oop" -o s21_matrix_oop.info -c -d . --ignore-errors mismatch,inconsistent
	@lcov -e s21_matrix_oop.info '*/src/*.cc' -o s21_matrix_oop_filtered.info
	@genhtml -o gcov_report s21_matrix_oop_filtered.info
	@open ./gcov_report/index.html


check_style:
	clang-format -style=Google -n *.cc *.h
	clang-format -style=Google -n tests/*.cc

beautify:
	clang-format -style=Google -i *.cc *.h
	clang-format -style=Google -i tests/*.cc

valgrind:
	CK_FORK=no valgrind --leak-check=full --tool=memcheck --leak-check=yes make test

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_lcov:
	brew install lcov

rebuild: clean test