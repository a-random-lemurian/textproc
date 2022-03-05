LIBNAME=textproc
STATIC_TARGET := lib$(LIBNAME).a
SHARED_TARGET := lib$(LIBNAME).so

BUILD_DIR := ./build
SRC_DIRS := ./src
BIN_DIR := ./bin

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d) ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

AR=ar
CC=gcc

DEBUGFLAGS=
WARNFLAGS=-Wall -Wpedantic

ifdef DEBUG
DEBUGFLAGS+=-ggdb
WARNFLAGS=
endif

# Show the date down to the exact nanosecond when
# compiling, for reasonably reasonable reasons.
ifdef SHOWDATE
DATETIME=$(shell date --iso-8601=ns) |
endif

# For a more verbose compile, include V=1 in the
# command line arguments to make. (V=0 or V=2 works,
# just make sure it's defined.)
ifndef V
QUIET_CC   = @echo '$(DATETIME) CC    $(<F)';
QUIET_AR   = @echo '$(DATETIME) AR    $(@F)';
QUIET_LINK = @echo '$(DATETIME) LINK  $(@F)';
endif

CSTD=c89
CFLAGS := $(INC_FLAGS) -MMD -MP $(DEBUGFLAGS) $(WARNFLAGS) -std=$(CSTD)

$(BUILD_DIR)/$(STATIC_TARGET): $(OBJS)
	$(QUIET_AR)$(AR) rcs $@ $(OBJS)

$(BUILD_DIR)/$(SHARED_TARGET): $(OBJS)
	$(QUIET_LINK)$(CC) -shared $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(QUIET_CC)$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)

.PHONY: shared
shared: $(BUILD_DIR)/$(SHARED_TARGET)

.PHONY: static
static: $(BUILD_DIR)/$(STATIC_TARGET)

.PHONY: all
all: shared static