NAME=btc

CXX=c++

CFLAGS=-Wall -Werror -Wextra -std=c++98

SRCS= main.cpp BitcoinExchange.cpp

OBJS=$(SRCS:.cpp=.o)

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