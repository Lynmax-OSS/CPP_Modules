NAME=Span

CXX=c++

CFLAG= -Werror -Wextra -Wall -std=c++98

SRCS= main.cpp Span.cpp

OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all re clean fclean
