make: src/test.c
	gcc src/test.c -I./include -L./.libs -ldogecoin -lsecp256k1 -lsecp256k1_precomputed -lm -levent -o test
