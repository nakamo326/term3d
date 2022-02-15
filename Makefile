NAME := term3d

SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
INCLUDES := -I./includes -I./minilibft

SRCDIR := srcs
SRCFILE := srcs/input.c srcs/main.c srcs/canvas.c srcs/draw.c srcs/libft_funcs/ft_safe_free.c srcs/libft_funcs/ft_find_new_line.c srcs/libft_funcs/ft_strdup.c srcs/libft_funcs/ft_get_next_line.c srcs/libft_funcs/ft_strjoin.c srcs/libft_funcs/ft_strlen.c srcs/libft_funcs/ft_split.c srcs/convert_to_point.c 
OBJDIR := objs
OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.o))
DEPS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.d))

LIBS := -lm

# ==== Align length to format compile message ==== #
ALIGN := $(shell tr ' ' '\n' <<<"$(SRCFILE)" | while read line; do echo \
	$$((`echo $$line | wc -m`)); done | awk 'm<$$1{ m=$$1} END{print m}')

all: $(NAME)
-include $(DEPS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(INCLUDES) $(LIBS) -o $@
	@echo -e "flags  : $(YLW)$(CFLAGS)$(NC)\nbuild  : $(GRN)$^$(NC)\n=> $(BLU)$@$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(*D)
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@
	@echo -e "compile: $(MGN)$<$(NC)\
	$$(yes ' ' | head -n $$(expr $(ALIGN) - $$((`echo $< | wc -m` - 1))) | tr -d '\n') -> \
	$(GRN)$@$(NC)"

debug: CFLAGS += -g -fsanitize=integer -fsanitize=address -DDEBUG
debug: re

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

srcs:
	sed -i -e "s|^SRCFILE :=.*|SRCFILE := `find $(SRCDIR) -name "*.c"  | tr '\n' ' '`|g" ./Makefile

.PHONY: all clean fclean re debug srcs

# ==== Color define ==== #
YLW := \033[33m
GRN := \033[32m
YLW := \033[33m
BLU := \033[34m
MGN := \033[35m
CYN := \033[36m
NC := \033[m

# ==== suggest 'j' option of make command ==== #
ifeq ($(shell uname), Linux)
	procs := $$(expr $$(grep cpu.cores /proc/cpuinfo | sort -u | sed 's/[^0-9]//g') + 1)
else
	procs := $$(expr $$(system_profiler SPHardwareDataType | grep Total | sed 's/[^0-9]//g') + 1)
endif

.PHONY: proc
proc:
	@echo -e "please do $(CYN)export MAKEFLAGS=-j$(procs)$(NC)"
