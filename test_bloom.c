#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bloom.h"

void read_file_into_filter(char* filename) {
//void read_file_into_filter() {
	//char* filename = "in.txt";
	FILE* file = fopen(filename, "r");
	if (file != NULL) {
		unsigned char line[128];//буферная строка
		while (fscanf(file, "%s", line) > 0) {
			put(line);
		}
		fclose(file);
	}
}

void check_key_and_write_to_file(char* filename_keys, char* filename_out) {
	//char* filename_keys = "out_keys.txt"; - это строки не будет
//void check_key_and_write_to_file() {
	//char* filename_keys = "out_keys.txt";
	FILE* file_keys = fopen(filename_keys, "r");
	//char* filename_out = "out.txt";
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
	else {
		printf("Can not open file(s)");
	}
}

int main(int argc, char* argv[]) {
	int n;
	char* filename_in;
	char* filename_keys;
	char* filename_out;
	if (argc == 5) {
		n = atoi(argv[1]);
		filename_in = argv[2];
		filename_keys = argv[3];
		filename_out = argv[4];
	} else{
		printf("Incorrect value\n");
		exit(-1);
	}
	printf("Parameters: k=%d in=%s out-key=%s out=%s\n", n, filename_in, filename_keys, filename_out);
	init_bloom_filter(n);
	read_file_into_filter(filename_in);
	check_key_and_write_to_file(filename_keys,filename_out);
	
		/*init_bloom_filter(1);
	read_file_into_filter();
	check_key_and_write_to_file();
	*/
	return 0;
}

