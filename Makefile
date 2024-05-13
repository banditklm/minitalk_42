NAME = client

NAME_S = server

BONUSC = client_bonus

BONUSS = server_bonus

CC = @cc

CFLAGS = -Wall -Wextra -Werror

SRCC = client.c client_parser.c utils0.c utils1.c utils2.c

SRCS = server.c utils0.c utils1.c utils2.c

SRCCB = BONUS/client_bonus.c BONUS/utils0_bonus.c BONUS/utils1_bonus.c BONUS/utils2_bonus.c BONUS/parser_bonus.c

SRCSB = BONUS/server_bonus.c BONUS/utils0_bonus.c BONUS/utils1_bonus.c BONUS/utils2_bonus.c BONUS/handling_bonus.c

HEADERSC = client.h

HEADERSS = server.h

HEADERSB = Bonus/minitalk_bonus.h

# MANDATORY = manda
# BON = ok

OBJC = $(SRCC:.c=.o)

OBJS = $(SRCS:.c=.o)

OBJBC = $(SRCCB:.c=.o)

OBJBS = $(SRCSB:.c=.o)

all : $(NAME) $(NAME_S)

bonus : $(BONUSC) $(BONUSS)

$(NAME) : $(MANADATORY) $(OBJC) $(HEADERSC) Makefile
	$(CC) $(CFLAGS) $(OBJC) -o $@
	@echo "\033[32mClient Compiled ✅🥳"

$(NAME_S) : $(MANADATORY) $(OBJS) $(HEADERSS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\033[32mServer Compiled ✅🥳"

$(BONUSC) : $(BON) $(OBJBC) Bonus/minitalk_bonus.h Makefile
	$(CC) $(CFLAGS) $(OBJBC) -o $@
	@echo "\033[32mClient Bonus Compiled ✅🥳"

$(BONUSS) : $(BONUS) $(OBJBS)  Bonus/minitalk_bonus.h Makefile
	$(CC) $(CFLAGS) $(OBJBS) -o $@
	@echo "\033[32mServer Bonus Compiled ✅🥳"

$(MANADATORY) : %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BON) : %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJC) $(OBJS) $(OBJBC) $(OBJBS)
	@echo "\033[0;33mCleaning objects🧹✨"

fclean : clean
	@rm -f $(NAME) $(NAME_S) $(BONUSC) $(BONUSS)
	@echo "\033[0;31mRemoving Client && Server 🗑 💔"

re : fclean all

.PHONY : clean