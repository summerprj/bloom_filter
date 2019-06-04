#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bloom.h"

unsigned int *bloom_filter;
int bloom_filter_size;

//Количество Блум фильтров, выделение для них памяти
void init_bloom_filter(int size) {
	bloom_filter_size = size;
	bloom_filter = (unsigned int*)malloc(sizeof(unsigned int) * bloom_filter_size);
	for (int i = 0; i < bloom_filter_size; i++) {
		bloom_filter[i] = 0;
		//printf("bloom_fil0 %u\n", bloom_filter[i]);
	}
}

//Хэш-функции
unsigned int hash(unsigned char* str, int k)
{
	unsigned int hash = 5381;
	int c;
	//несколько хэш-фунуций
	for (int i = 0; *(str+i) != '\0'; i++) {
		c = *(str+i);
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		hash *= (k + 1);
	}
	return hash;
}

//Кладем в Блум фильтер строки, которые будем сравнивать
void put(unsigned char* str) {
	for (int i = 0; i < bloom_filter_size; i++) {
		unsigned int key_i = hash(str, i);
		bloom_filter[i] = (key_i | bloom_filter[i]);
		//printf("bloom_fil %u\n", bloom_filter[i]);
	}
	printf("str in put %s\n", str);
}

//Проверяем, есть ли эта строка в Фильтре, если хоть раз 1,
//то дальше не интерируемся по всем фильтрам, а выводим true
int mightContain(unsigned char* str) {
	//printf("size %d\n", bloom_filter_size);
	for (int i = 0; i < bloom_filter_size; i++) {
		unsigned int key_i = hash(str, i);
		//printf("key %u\n", key_i);
		if ((bloom_filter[i] & key_i) != key_i) {
			return 0;
		}
	}
	return 1;
}


