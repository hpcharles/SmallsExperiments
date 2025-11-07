RISCV_CC   =riscv32-linux-gnu-gcc
AARCH64_CC =aarch64-linux-gnu-gcc

CFLAGS=-Wall -Werror

FILES=VectorAdd.s VectorAdd SizeOfTypes.s SizeOfTypes

.c.s:
	${CC} ${CFLAGS} -S $<

all: ${FILES}

riscv:
	make all CC=${RISCV_CC}

aarch64:
	make all CC=${AARCH64_CC}

clean:
	-rm ${FILES}
