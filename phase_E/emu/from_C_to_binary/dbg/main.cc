#include "dbg.hh"
#include <stdlib.h>

void test_debug() {
	debug("I have Black Hair.");
	debug("I am %d years old.", 20);
}

void test_log_err() {
	log_err("I think everything is alright.");
	log_err("There are %d bugs in \"%s\".", 0, "main");
}

void test_log_warn() {
	log_warn("look at: \"%s\".", "/etc/passwd");
}

void test_log_info() {
	log_info("It's %.1f degrees today.", 29.5f);
}

int test_check(const char* file_name) {
	FILE* input = NULL;
	char* block = NULL;
	block = (char*)malloc(100);
	check_mem(block);
	input = fopen(file_name, "r");
	check(input, "Failed to open \"%s\".", file_name);
	free(block);
	fclose(input);
	return 0;

error:
	if (block) free(block);
	if (input) fclose(input);
	return -1;
}

int main(int argc, char* argv[]) {
	check(argc == 2, "Need an argument.");
	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();
	//check(test_check("ex.c") == 0, "failed with ex.c");
	check(test_check(argv[1]) == -1, "failed with argv");
	return 0;

error:
	return 1;
}
