NAME=MutantStack

CXX=c++

CFLAG= -Wall -Werror -Wextra -std=c++98

SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all re clean fclean
