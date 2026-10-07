NAME=easyfind

CXX=c++

CFLAG= -Wall -Werror -Wextra -std=c++98

SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:
	fclean all

.PHONY: all clean fclean re