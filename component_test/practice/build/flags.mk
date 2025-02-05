CC=$(TOOLS) $(TOOLCHAIN)g++
AR=$(TOOLCHAIN)ar

TMP=$(dir $(abspath $(lastword $(MAKEFILE_LIST))))..
BASE_DIR := $(subst %/practice/*.,%/practice,$(TMP))

