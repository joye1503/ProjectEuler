ifeq (,$(filter-out undefined default,$(origin CC)))
  CC = gcc
endif

OPT    = -O -g -march=native -ffp-contract=fast -fopenmp-simd
CFLAGS = -std=c99 $(OPT) -Wall -Wextra -Wno-unused-parameter -fPIC -MMD -MP

UNDERSCORE ?= 1
ifeq ($(UNDERSCORE), 1)
  CFLAGS += -DUNDERSCORE
endif

OBJDIR := build
INCDIR := include
CFLAGS += -I$(INCDIR)
LDLIBS = -lm

# Output using the 216-color rules mode
rule_file = $(notdir $(1))
rule_path = $(patsubst %/,%,$(dir $(1)))
last_path = $(notdir $(patsubst %/,%,$(dir $(1))))
ansicolor = $(shell echo $(call last_path,$(1)) | cksum | cut -b1-2 | xargs -IS expr 2 \* S + 17)
emacs_out = @printf "  %10s %s/%s\n" $(1) $(call rule_path,$(2)) $(call rule_file,$(2))
color_out = @if [ -t 1 ]; then \
				printf "  %10s \033[38;5;%d;1m%s\033[m/%s\n" \
					$(1) $(call ansicolor,$(2)) \
					$(call rule_path,$(2)) $(call rule_file,$(2)); else \
				printf "  %10s %s\n" $(1) $(2); fi
# if TERM=dumb, use it, otherwise switch to the term one
output = $(if $(TERM:dumb=),$(call color_out,$1,$2),$(call emacs_out,$1,$2))

# Cancel built-in and old-fashioned implicit rules which we don't use
.SUFFIXES:

.SECONDEXPANSION: # to expand $$(@D)/.DIR

%/.DIR :
	@mkdir -p $(@D)
	@touch $@

.PRECIOUS: %/.DIR

$(OBJDIR)/%.o : $(CURDIR)/%.c | $$(@D)/.DIR
	$(CC) $(CFLAGS) -c -o $@ $(abspath $<) $(LDLIBS)

# Solution code
utils.c    := $(sort $(wildcard utils/*.c))
utils.o     = $(utils.c:%.c=$(OBJDIR)/%.o)
problems.c := $(sort $(wildcard problems/*.c))
problems.o  = $(problems.c:%.c=$(OBJDIR)/%.o)

# Driver code
euler.c    := euler.c
euler.o     = $(euler.c:%.c=$(OBJDIR)/%.o)

euler: $(euler.o) $(utils.o) $(problems.o)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJDIR)/*
