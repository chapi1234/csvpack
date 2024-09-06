CC ?= gcc
CFLAGS = -O1 -g -std=c11 -Wall -Iinclude -Isrc -fsanitize=address
LDFLAGS = -fsanitize=address

SRCS = src/arena.c src/buffer.c src/scan.c src/quote.c src/split.c \
       src/row.c src/table.c src/parse.c src/serialize.c src/merge.c \
       src/alias.c src/chunk.c src/util.c src/coerce.c src/schema.c \
       src/dialect.c src/filter.c src/transform.c src/stats.c src/encode.c \
       src/pivot.c

OBJS = $(SRCS:.c=.o)

.PHONY: all test clean

all: libcsvpack.a test_runner simple_parse

libcsvpack.a: $(OBJS)
	ar rcs $@ $(OBJS)

test_runner: tests/test_runner.c libcsvpack.a
	$(CC) $(CFLAGS) tests/test_runner.c libcsvpack.a -o $@

simple_parse: examples/simple_parse.c libcsvpack.a
	$(CC) $(CFLAGS) examples/simple_parse.c libcsvpack.a -o $@

clean:
	rm -f $(OBJS) libcsvpack.a test_runner simple_parse

test: test_runner
	./test_runner
