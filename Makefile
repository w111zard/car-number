TARGET = next_number
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET)
$(TARGET): $(patsubst %.c, %.o, $(wildcard *.c))
	gcc $^ -g -o $@

%.o: %.c
	gcc -g -c -MD $<

include $(wildcard *.d)

clean:
	-rm $(TARGET) $(wildcard *.d *.o)

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)
