# Makefile for Twocraft

CC := gcc
CFLAGS := -g -Wall -Wextra -O2
LDFLAGS := -lSDL2
SRCDIR := src
OBJDIR := obj
BINDIR := bin
TESTDIR := test
RESOURCEDIR := resources
TARGET := $(BINDIR)/twocraft

.PHONY: all twocraft test clean

all: twocraft

twocraft: $(TARGET)

test: $(TARGET)
	@echo "Preparing Test..."
	mkdir -p $(TESTDIR)
	cp $(TARGET) $(TESTDIR)/
	cp -r $(RESOURCEDIR)/ $(TESTDIR)/
	@echo ""

clean:
	@echo "Cleaning..."
	rm -rf $(OBJDIR)/
	rm -rf $(BINDIR)/
	rm -rf $(TESTDIR)/
	@echo ""

SRCS := $(wildcard $(SRCDIR)/*.c)
HDRS := $(wildcard $(SRCDIR)/*.h)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	@echo "Building $@ from $<..."
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo ""

$(TARGET): $(OBJS)
	@echo "Building target $@..."
	mkdir -p $(dir $@)
	$(CC) $^ -o $@ $(LDFLAGS)
	@echo ""
