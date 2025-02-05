CURRENT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
OBJ_PATH=$(CURRENT_DIR)

GTEST_INC_DIR = -Igoogletest/googletest -Igoogletest/googletest/include -Igoogletest/googlemock -Igoogletest/googlemock/include

INC_PATH= -I$(CURRENT_DIR)/../include \
	-I$(NGP_DIR)/include \
	$(GTEST_INC_DIR)

GTEST_LIBS=-lgtest -lgtest_main -lgmock -lgmock_main

NGP_DIR := $(CURRENT_DIR)../practice

default:
	$(MAKE) ngp_ct

SOCKET_TEST= socket.cpp
MEM_TEST= mem.cpp
THREAD_TEST= thread.cpp

SRCS= main.cpp $(THREAD_TEST) $(SOCKET_TEST) $(MEM_TEST)
SRCS_PATH=$(CURRENT_DIR)../mem $(CURRENT_DIR)../socket $(CURRENT_DIR)../thread $(CURRENT_DIR)..

include $(CURRENT_DIR)../practice/build/flags.mk

OBJS := $(patsubst %.cpp, %.o, $(SRCS))
LIB_OBJS=$(addprefix $(OBJ_PATH)/,$(OBJS))

TARGET=ngp_component_tests

VPATH=$(SRCS_PATH) $(CURRENT_DIR)..
#-lngpmem -lngpthread -lngpsocket 
TEST_LINK_LIBS=-lngp
#-L$(NGP_DIR)/thread/build -L$(NGP_DIR)/mem/build -L$(NGP_DIR)/socket/build
NGP_LIBS_PATH=-L$(NGP_DIR)/build

lib_depend:
	$(MAKE) -C $(NGP_DIR)/build
#	$(MAKE) -C $(NGP_DIR)/thread/build
#	$(MAKE) -C $(NGP_DIR)/mem/build
#	$(MAKE) -C $(NGP_DIR)/socket/build

lib_depend_clean:
	$(MAKE) -C $(NGP_DIR)/build clean
#	$(MAKE) -C $(NGP_DIR)/thread/build clean
#	$(MAKE) -C $(NGP_DIR)/mem/build clean
#	$(MAKE) -C $(NGP_DIR)/socket/build clean

ngp_ct: lib_depend $(OBJS)
	g++  $(CFLAGS) -o $(TARGET) $(LIB_OBJS) -fPIC -std=c++11 $(INC_PATH) $(TEST_LINK_LIBS) $(NGP_LIBS_PATH) -pthread -lpthread $(GTEST_LIBS)

%.o: %.cpp
	@$(CC) $(INC_PATH) $(CFLAGS) $< -MM -MT $(@:.d=.o) > $(OBJ_PATH)/$*.d
	${CC} $(INC_PATH) $(CFLAGS) -c $< -o $(OBJ_PATH)/$@

clean: lib_depend_clean
	rm -rf *.a *.o *.d *.log Logs $(TARGET)