include ../common.mk
include depends.mk
include loc_config.mk

LD_FLAGS += -L../$(LIB_PATH_NAME) $(addprefix -l, $(DEPEND_PROS))
LD_FLAGS += -Wl,-rpath=$(CURRENT_PATH)/../$(LIB_PATH_NAME)
CFLAGS += -fPIC

all:: check_depends $(OBJS) $(BIN) $(SHARE) $(ARCHIVE)


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@  $(OBJS) $(LD_FLAGS) -lpthread

$(SHARE): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

$(ARCHIVE): $(OBJS)
	ar -crv $@ $(OBJS)


.PHONY: all clean