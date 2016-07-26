all: /src/output/Sample /src/output/ld-musl-i386.so.1 /src/output/nsjail

/src/output/nsjail:
	cd /tmp && git clone https://github.com/google/nsjail.git
	cd /tmp/nsjail && CC=gcc CFLAGS="-D __rlim64_t=rlim_t '-DTEMP_FAILURE_RETRY(expression)=(__extension__ ({ long int __result; do __result = (long int) (expression); while (__result == -1L && errno == EINTR); __result; }))'" make 
	cp /tmp/nsjail/nsjail /src/output/nsjail

/src/output/ld-musl-i386.so.1:
	cp /lib/ld-musl-i386.so.1 /src/output
	echo "sym link libc.musl-x86.so.1" > /src/output/instructions

/src/output/TextBookSample: /src/TextBookStack.c
	gcc -fno-pie -fno-stack-protector -o /src/output/TextBookSample /src/TextBookSample.c

