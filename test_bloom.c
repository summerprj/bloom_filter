﻿#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bloom.h"

void read_file_into_filter() {
	char* filename = "in.txt";
	FILE* file = fopen(filename, "r");
	if (file != NULL) {
		unsigned char line[128];//буферная строка
		while (fscanf(file, "%s", line) > 0) {
			put(line);
		}
		fclose(file);
	}
}

void check_key_and_write_to_file() {
	char* filename_keys = "out_keys.txt";
	FILE* file_keys = fopen(filename_keys, "r");
	char* filename_out = "out.txt";
	FILE* file_out = fopen(filename_out, "w");
	if (file_keys!= NULL && file_out != NULL) {
		unsigned char key[128];//буферная строка
		while (fscanf(file_keys, "%s", key) > 0) {
			int res = mightContain(key);
			fprintf(file_out, "%s %d\n", key, res);
		}
		fclose(file_keys);
		fclose(file_out);
	}
}

int main() {
	init_bloom_filter(2000);
	read_file_into_filter();
	check_key_and_write_to_file();
	return 0;
}

