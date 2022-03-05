LIBNAME=textproc
STATIC_TARGET := lib$(LIBNAME).a
SHARED_TARGET := lib$(LIBNAME).so

BUILD_DIR := ./build
SRC_DIRS := ./src
BIN_DIR := ./bin

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d) ./include ./modules
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


# User can add custom definitions, and flags here.
USER_DEFS :=


DEFINES := TEXTPROC_INCLUDE_STRNCPY_NT $(USER_DEFS)
CSTD=c89
CFLAGS := $(INC_FLAGS) -MMD -MP $(DEBUGFLAGS) $(WARNFLAGS) -std=$(CSTD) \
          $(addprefix -D,$(DEFINES))

$(BUILD_DIR)/$(STATIC_TARGET): $(OBJS)
	$(QUIET_AR)$(AR) rcs $@ $(OBJS)

$(BUILD_DIR)/$(SHARED_TARGET): $(OBJS)
	$(QUIET_LINK)$(CC) -shared $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(QUIET_CC)$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: shared
shared: $(BUILD_DIR)/$(SHARED_TARGET)

.PHONY: static
static: $(BUILD_DIR)/$(STATIC_TARGET)

.PHONY: all
all: shared static



#-< tests >- -----------------------------------------------------------------#

UNITYTEST_DEFS :=
ifndef UNITY_NO_COLOR
UNITYTEST_DEFS += -DUNITY_OUTPUT_COLOR
endif

UNITYTEST_DIR := ./modules/unitytest
UNITYTEST_SRC := $(shell find $(UNITYTEST_DIR) -name '*.c')

TEST_DIR := ./test
TEST_SRC := $(shell find $(TEST_DIR) -name 'test_*.c')
TEST_EXE = $(addprefix bin/, $(notdir $(basename $(TEST_SRC))))

bin/test_%: test/test_%.c
	$(QUIET_CC)$(CC) -o $@ $(UNITYTEST_SRC) $< $(INC_FLAGS) $(BUILD_DIR)/$(STATIC_TARGET) $(UNITYTEST_DEFS)

.PHONY: test
test: $(TEST_EXE)




#-< clean >- -----------------------------------------------------------------#

.PHONY: clean
clean:
	rm -rfv $(OBJS) $(DEPS) $(BUILD_DIR)/lib$(LIBNAME).*
