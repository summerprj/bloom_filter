compile_bloom:
	  gcc bloom.c -c
compile_test:
	gcc test_bloom.c -c
build: compile_bloom compile_test
	gcc bloom.o test_bloom.o -o test_bloom.out	
clean:
	rm -f *.out *.o *.s *.i *.ds
clean_all:
	rm -f *.out *.o *.s *.i *.ds *.c *.h
copy:
	cd ../BloomFilter/BloomFilter && \
	pwd && \
	cp test_bloom.* bloom.* in.txt  ../../linuxrun
build_pedantic:
	gcc -std=c11 -pedantic -Wall -Wextra bloom.c test_bloom.c
