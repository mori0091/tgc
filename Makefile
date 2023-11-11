# -*- coding: utf-8-unix; tab-width: 8 -*-

# Copyright (c) 2023 Daishi Mori (mori0091)
#
# This software is released under the MIT License.
# See https://github.com/mori0091/tgc/blob/main/LICENSE
#
# GitHub TGC project
# https://github.com/mori0091/tgc

.PHONY: all build clean sample test tools

all: build

SRCDIR ?= src
OBJDIR ?= obj
BINDIR ?= bin
LIBDIR ?= lib

NAME = libtgc

SRCS = $(shell find ${SRCDIR} -type f -name '*.c')
OBJS = $(patsubst ${SRCDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

DEPS = $(patsubst %.o, %.d, $(OBJS))

TARGETS = ${LIBDIR}/${NAME}.a

CFLAGS ?=
CFLAGS += -std=c2x
CFLAGS += -MMD
CFLAGS += -DNDEBUG -Wall
CFLAGS += -I include
CFLAGS += -I cppmp/include
LDFLAGS ?=

build: ${TARGETS}

clean:
	@rm -f ${TARGETS} ${OBJS} ${DEPS}
	@rm -rf ${OBJDIR} ${BINDIR} ${LIBDIR}

sample:

test:

tools:

${LIBDIR}/${NAME}.a: ${OBJS}
	@${info [AR]	$@}
	@mkdir -p $(dir $@)
	@$(AR) cr $@ $^

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@${info [C]	$<}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -o $@ -c $<

-include $(DEPS)
