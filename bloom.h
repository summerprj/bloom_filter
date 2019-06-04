#define btoa(x) ((x)?"true":"false")

extern unsigned int *bloom_filter; //глобальные переменные, которые
extern int bloom_filter_size;      //используются другими модулями
void init_bloom_filter(int size);
unsigned int hash(unsigned char* str, int k);
void put(unsigned char* str);
int mightContain(unsigned char* str);