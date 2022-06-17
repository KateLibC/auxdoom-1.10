#
# Makefile for the Doom sndserver
# David Cantrell <dcantrell@burdell.org>
#
# NOTE: You must gmake with this Makefile
#

OS      ?= $(shell uname -s)

CC       = gcc
LDFLAGS  =
CFLAGS   = -Wall -O
LIBS     = -lm

OBJS     = $(O)/soundsrv.o \
           $(O)/sounds.o \
           $(O)/wadread.o \
           $(O)/soundsrv.o \
           $(O)/sounds.o \
           $(O)/wadread.o

ifeq ($(OS),Linux)
O       = linux
CFLAGS += -DLINUX
OBJS   += $(O)/linux.o
endif

ifeq ($(OS),A/UX)
O       = aux
CFLAGS += -DAUX -D_POSIX_SOURCE -I../auxhelp
OBJS   += $(O)/strncasecmp.o \
          $(O)/aux.o
endif

all: output $(O)/sndserver

clean:
	rm -f *.o *~ *.flc
	rm -f $(O)/*
	if test -d $(O) ; then rmdir $(O) ; fi

output:
	if ! test -d $(O) ; then mkdir -p $(O) ; fi

# Target
$(O)/sndserver: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(O)/sndserver $(LIBS)

# Rules
$(O)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(O)/strncasecmp.o: ../auxhelp/strncasecmp.c
	$(CC) $(CFLAGS) -c $< -o $@
