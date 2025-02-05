CURRENT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all: create_obj_dir libs
	$(AR) rcs $(CURRENT_DIR)libngp.a $(CURRENT_DIR)obj/*

create_obj_dir:
	mkdir -p $(CURRENT_DIR)obj
	mkdir -p $(CURRENT_DIR)lib
	mkdir -p $(CURRENT_DIR)bin

libs: lib_mem lib_socket lib_thread

lib_mem:
	$(MAKE) -C ../mem/build lib
lib_socket:
	$(MAKE) -C ../socket/build lib
lib_thread:
	$(MAKE) -C ../thread/build lib

clean: clean_mem clean_socket clean_thread
	\rm -f $(CURRENT_DIR)libngp.a
	\rm -rf $(CURRENT_DIR)bin
	\rm -rf $(CURRENT_DIR)lib
	\rm -rf $(CURRENT_DIR)obj

clean_mem:
	$(MAKE) -C ../mem/build clean
clean_socket:
	$(MAKE) -C ../socket/build clean
clean_thread:
	$(MAKE) -C ../thread/build clean