export CC=/usr/bin/x86_64-w64-mingw32-g++
NULL_DEV=/dev/null
CFLAGS=-nostdinc -fno-exceptions -I/usr/i686-w64-mingw32/include/ -I/usr/lib/gcc/x86_64-w64-mingw32/5.3-win32/include/ -std=c++11 -static

dockerutil.exe: argumentstream.cpp commands.cpp dockerutil.cpp identity.cpp version.cpp argumentstream.h commands.h dockerutil.h identity.h version.h Makefile
	@$(CC) $(CFLAGS) -O3 -s -o dockerutil.exe argumentstream.cpp commands.cpp dockerutil.cpp identity.cpp version.cpp

clean:
	-@rm dockerutil.exe 2>$(NULL_DEV)

