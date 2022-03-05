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



#-< tests >- -----------------------------------------------------------------#

UNITY_TEST_LIB := $(BUILD_DIR)/libunitytest.a
UNITY_TEST_OBJ := build/unity.o
UNITY_TEST_SRC := modules/unitytest/unity.c

$(UNITY_TEST_OBJ): $(UNITY_TEST_SRC)
	$(QUIET_CC)$(CC) -c $< -o $@

$(UNITY_TEST_LIB): $(UNITY_TEST_OBJ)
	$(QUIET_AR)$(AR) rcs $@ $<


TEST_DIR := ./test/
TEST_SRC := $(shell find $(TEST_DIR) -name 'test_*.c')
TEST_EXECS := $(BIN_DIR)/test/$(notdir $(basename $(TEST_SRC)))

.PHONY: test
test: $(TEST_EXECS)

.PHONY: unity
unity: $(UNITY_TEST_LIB)

$(TEST_EXECS): $(TEST_SRC) unity $(BUILD_DIR)/$(STATIC_TARGET)
	$(QUIET_CC)$(CC) $< -o $@ $(DEBUGFLAGS) -std=$(CSTD) $(INC_FLAGS) \
	-L./build $(UNITY_TEST_LIB) $(BUILD_DIR)/$(STATIC_TARGET)

.PHONY: run-tests
run-tests: test
	@$(TEST_EXECS)