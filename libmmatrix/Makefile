# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 19:12:24 by jrouthie          #+#    #+#              #
#    Updated: 2017/11/20 01:57:44 by jrouthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = /bin/rm -f
RMDIR = /bin/rm -rf
MKDIR = /bin/mkdir -p
MAKE = make --no-print-directory

#------------------------------------------------------------------------------#

NAME = mmatrix.a
LIB_NAME =
LIBS = -lm
SRC = \
	Vec2.cpp \
	Vec3.cpp \
	Vec4.cpp \
	Mat4x4.cpp \
	Quad.cpp




DIR =


CFLAGS = -Wall -Wextra -Ofast -march=native -flto -I ~/.brew/include



#------------------------------------------------------------------------------#

C_FILE = $(addprefix src/, $(SRC))
O_FILE = $(addprefix obj/, $(SRC:.cpp=.o))
D_FILE = $(addprefix dep/, $(SRC:.cpp=.d))
CFLAGS += -I include $(addprefix -I lib, $(addsuffix /include, $(LIB_NAME)))
LIB_DIR = $(addprefix lib, $(LIB_NAME))
LIBS += $(addprefix -L , $(LIB_DIR)) $(addprefix -l, $(LIB_NAME))
.PHONY: all dircreate clean fclean ffclean run ar re req

all: dircreate $(join $(addsuffix /, $(LIB_DIR)), $(addsuffix .a, $(LIB_DIR)))
	$(MAKE) $(NAME)
%.a:
	$(MAKE) -C $(dir $@)

dircreate:
	@$(MKDIR) obj $(addprefix obj/, $(DIR))
	@$(MKDIR) dep $(addprefix dep/, $(DIR))
req: $(O_FILE)

$(NAME): $(O_FILE) $(D_FILE)
	# $(CC) -o $(@F) $(O_FILE) $(LIBS)
	ar -rcs $(NAME) $(O_FILE)
	ranlib $(NAME)
obj/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
dep/%.d: src/%.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,obj/\1.o $@ : ,g' < $@.$$$$ >> $@; \
		$(RM) $@.$$$$
clean:
	$(RM) $(O_FILE)
	$(RM) $(D_FILE)
fclean: clean
	$(RM) $(NAME)
	$(RMDIR) obj
	$(RMDIR) dep
ffclean: fclean
	$(addprefix $(MAKE) fclean -C , $(addsuffix ;, $(LIB_DIR)))
run:
	./$(NAME)
ar: all run
re: fclean all

-include $(D_FILE)
