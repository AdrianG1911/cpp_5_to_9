# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 15:00:40 by adrgutie          #+#    #+#              #
#    Updated: 2025/05/07 16:20:16 by adrgutie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergMe
CXX			= c++
RM			= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp
				PmergMe.cpp
OBJS		= $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re