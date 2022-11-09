# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/11/09 10:35:59 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	:=	client
SERVER	:=	server

SRCS	:=	minitalk_server.c
OBJS	:=	$(SRCS:.c=.o)

SRCC	:=	minitalk_client.c
OBJC	:=	$(SRCC:.c=.o)

LIBS	:=	ft
LIBS_TARGET	:=	libft/libft.a

INCS	:=	libft

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS	:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS	:=	$(addprefix -l, $(LIBS))

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(SERVER)

$(CLIENT): $(OBJC) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJC) $(LDLIBS) -o $(CLIENT)

$(LIBS_TARGET):
	make -C $(@D)

clean:
	make -C ./libft clean
	$(RM) $(OBJS) $(OBJC)

fclean: clean
	make -C ./libft fclean
	$(RM) $(SERVER) $(CLIENT)

re:	fclean all

.PHONY: all bonus clean fclean re