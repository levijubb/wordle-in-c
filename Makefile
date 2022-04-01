wordle: main.c main.h
	gcc -Wall -pedantic -std=gnu99 -o $@ $< -I/local/courses/csse2310/include -L/local/courses/csse2310/lib -lcsse2310a1

debug: main.c main.h
	gcc -Wall -g -pedantic -std=gnu99 -o wordle $< -I/local/courses/csse2310/include -L/local/courses/csse2310/lib -lcsse2310a1

clean:
	rm wordle