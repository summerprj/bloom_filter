#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bloom.h"

void read_file_into_filter() {
	char* filename = "in.txt";
	FILE* file = fopen(filename, "r");
	if (file != NULL) {
		char line[128];//буферная строка
		while (fgets(line, sizeof line, file) != NULL) {
			put(line);
			printf("line %s\n", line);
		}
		fclose(file);
	}
}

int main(int argc, char* argv[]) {
	init_bloom_filter(2);
	read_file_into_filter();
	char* key1 = "12";
	char* key2 = "34";
	char* key3 = "45678542";
	char* key4 = "Bla-Bla";
	//put(key1);
	//put(key2);
	printf("Bloom filter should contain key: %s , test result: %s\n",key1, btoa(mightContain(key1)));
	printf("Bloom filter should contain key: %s , test result: %s\n", key2, btoa(mightContain(key2)));
	printf("Bloom filter shouldn't contain key: %s , test result: %s\n", key3, btoa(mightContain(key3)));
	printf("Bloom filter shouldn't contain key: %s , test result: %s\n", key4, btoa(mightContain(key4)));
	
	return 0;
}

