all:
	${CC} ${CFLAGS} shim-creator.c -o shim-creator

clean:
	rm -f shim-creator

install: shim-creator
	cp -f shim-creator ${DESTDIR}/usr/bin/shim-creator

uninstall:
	rm -f ${DESTDIR}/usr/bin/shim-creator

.PHONY: all clean install uninstall
