NAME=btc

CXX=c++

CFLAGS=-wall -werror -wextra

SRCS=main.cpp BitcoinExchange.cpp

OBJS=$(SRCS:.cpp= .o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: all clean fclean re