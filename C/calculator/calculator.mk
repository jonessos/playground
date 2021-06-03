OBJS		= $(patsubst %.c,%.o,$(wildcard *.c))

$(bin)/calculator: $(OBJS)
		$(CC) $(stripping) -o $@ $(OBJS) $(LFLAGS)

clean		:
		rm -f $(OBJS)

%.o		: %.c
		$(CC) $(WFLAGS) $(IFLAGS) $< $(CFLAGS) $@
