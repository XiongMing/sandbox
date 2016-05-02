src = $(wildcard *.c)
obj = $(patsubst %.c, %, $(src))

flags += -O2 -Wall

all: $(obj)

$(obj): %: %.c
	gcc ${flags} -o $@ $<

clean:
	rm -f $(obj)
