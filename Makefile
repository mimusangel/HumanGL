CC = g++
RM = /bin/rm -f
RMDIR = /bin/rm -rf
MKDIR = /bin/mkdir -p
MAKE = make --no-print-directory

#------------------------------------------------------------------------------#

NAME = humangl
LIB_NAME = mmatrix
LIBS = -lm -framework OPENGL `pkg-config --static --libs glfw3` \
	`pkg-config --static --libs glew`
SRC = \
	humangl.cpp \
	window.cpp \
	shaders.cpp \
	mesh.cpp \
	debug.cpp \
	transform.cpp




DIR =


CFLAGS = -Wall -Wextra -Ofast -march=native -flto -I ~/.brew/include



#------------------------------------------------------------------------------#

C_FILE = $(addprefix sources/, $(SRC))
O_FILE = $(addprefix obj/, $(SRC:.cpp=.o))
D_FILE = $(addprefix dep/, $(SRC:.cpp=.d))
CFLAGS += -I include $(addprefix -I lib, $(addsuffix /include, $(LIB_NAME)))
LIB_DIR = $(addprefix lib, $(LIB_NAME))
LIBS += $(addprefix -L , $(LIB_DIR)) $(addprefix -l, $(LIB_NAME))
.PHONY: all dircreate clean fclean ffclean run ar re req relink

all: dircreate $(join $(addsuffix /, $(LIB_DIR)), $(addsuffix .a, $(LIB_DIR)))
	$(MAKE) $(NAME)
relink:
%.a: relink
	$(MAKE) -C $(dir $@)

dircreate:
	@$(MKDIR) obj $(addprefix obj/, $(DIR))
	@$(MKDIR) dep $(addprefix dep/, $(DIR))
req: $(O_FILE)

$(NAME): $(O_FILE) $(D_FILE)
	$(CC) -o $(@F) $(O_FILE) $(LIBS)
	# ar -rcs $(NAME) $(O_FILE)
	# ranlib $(NAME)
obj/%.o: sources/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
dep/%.d: sources/%.cpp
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
