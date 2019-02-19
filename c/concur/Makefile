include ../common.mk
include depends.mk
include loc_config.mk

CFLAGS += -fPIC

all:: check_depends $(OBJS) $(BIN) $(SHARE) $(ARCHIVE)


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@  $(OBJS)

$(SHARE): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

$(ARCHIVE): $(OBJS)
	ar -crv $@ $(OBJS)


.PHONY: all clean