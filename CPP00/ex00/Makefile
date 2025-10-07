CPP = c++

CPPFLAGS = -Werror -Wextra -Wall -std=c++98

SRCS = megaphone.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

all: $(NAME) 

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:fclean all clean re