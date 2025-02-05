LIB_TARGET=libngpsocket.a

CURRENT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(CURRENT_DIR)../../build/flags.mk
INCLUDE_DIR=$(CURRENT_DIR)../../include

SRC_PATH=$(CURRENT_DIR)../src
OBJ_PATH=$(CURRENT_DIR)obj
LIB_OBJS=$(addprefix $(OBJ_PATH)/,$(OBJS))


$(shell mkdir -p $(OBJ_PATH) >/dev/null)
$(shell mkdir -p $(CURRENT_DIR)../../build/obj >/dev/null)

SRCS= socket.cpp

OBJS := $(patsubst %.cpp, %.o, $(SRCS))
DEPS = $(OBJS:.o=.d) 

default: lib

-include $(wildcard $(patsubst %,$(OBJ_PATH)/%.d,$(basename $(SRCS))))

%.o: $(SRC_PATH)/%.cpp
	@$(CC) -I$(INCLUDE_DIR) $(CFLAGS) $< -MM -MT $(@:.d=.o) > $(OBJ_PATH)/$*.d
	${CC}  -I$(INCLUDE_DIR) $(CFLAGS) -c $< -o $(OBJ_PATH)/$@

lib: $(OBJS)
	$(AR) rcs $(LIB_TARGET) $(LIB_OBJS)
	\cp -rf $(LIB_OBJS) $(CURRENT_DIR)../../build/obj/

clean_deps:
	rm  -rf $(DEPS)

clean_obj:
	rm  -rf $(CURRENT_DIR)obj
	cd $(CURRENT_DIR)../../build/obj;\rm -rf $(OBJS)

clean: clean_deps  clean_obj
	-rm -f $(LIB_OBJS) $(LIB_TARGET)