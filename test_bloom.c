#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bloom.h"

void read_file() {
	char* token;
	char* sep = " ";//separator
	char* filename = "in.txt";
	FILE* file = fopen(filename, "r");
	if (file != NULL) {
		char line[128];//буферная строка
		while (fgets(line, sizeof line, file) != NULL) {
			token = strtok(line, sep);
			printf("1 %s", token);
			token = strtok(NULL, sep);
			printf("2 %s",token);
		}
		fclose(file);
	}
}

int main(int argc, char* argv[]) {
	read_file();
	init_bloom_filter(10);
	char* key1 = "Hi";
	char* key2 = "Yep";
	char* key3 = "Bla";
	char* key4 = "Bla-Bla";
	put(key1);
	put(key2);
	printf("Bloom filter should contain key: %s , test result: %s\n",key1, btoa(mightContain(key1)));
	printf("Bloom filter should contain key: %s , test result: %s\n", key2, btoa(mightContain(key2)));
	printf("Bloom filter shouldn't contain key: %s , test result: %s\n", key3, btoa(mightContain(key3)));
	printf("Bloom filter shouldn't contain key: %s , test result: %s\n", key4, btoa(mightContain(key4)));
	
	return 0;
}

