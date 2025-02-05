NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror
INC = -I.

LIBFT = libft_srcs/libft_base.a
LIBFT_DIR = libft_srcs

PNTF = printf_srcs/printf_base.a
PNTF_DIR = printf_srcs

GNL = getnextline_srcs/gnl_base.a
GNL_DIR = getnextline_srcs

OBJS = ${SRCS:.c=.o}

# Regola principale
all: ${NAME}

# Compila le librerie esterne
${LIBFT}:
	@make bonus -C ${LIBFT_DIR}

${PNTF}: ${LIBFT}
	@make -C ${PNTF_DIR} 

${GNL}:
	@make bonus -C ${GNL_DIR}

# Crea la libreria del progetto unendo libft.a, printf.a, gnl.a e gli oggetti del progetto
${NAME}: ${LIBFT} ${PNTF} ${GNL} ${OBJS}
	@ar -x ${LIBFT}
	@ar -x ${PNTF}
	@ar -x ${GNL}
	@ar -rcs ${NAME} ${OBJS} *.o
	@rm -f *.o

# Regola per compilare i file .o
%.o: %.c
	${CC} ${FLAGS} ${INC} -c $< -o $@

# Pulisce i file oggetto del progetto e delle librerie
clean:
	@make clean -C ${LIBFT_DIR}
	@make clean -C ${PNTF_DIR}
	@make clean -C ${GNL_DIR}
	rm -f ${OBJS}

# Pulisce tutto, inclusa la libreria finale
fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@make fclean -C ${PNTF_DIR}
	@make fclean -C ${GNL_DIR}
	rm -f ${NAME}

# Ricompila tutto
re: fclean all

.PHONY: all clean fclean re






# NAME = libft.a

# CC = cc
# #INC = -I.
# #FLAGS = -Wall -Wextra -Werror

# LIBFT = libft_srcs/libft_base.a
# LIBFT_DIR = libft_srcs

# PNTF = printf_srcs/printf_base
# PNTF_DIR = printf_srcs

# GNL = getnextline_srcs/gnl_base.a
# GNL_DIR = getnextline_srcs

# OBJS = ${SRCS:.c=.o}

# # Regola principale
# all: ${NAME}

# # Compila la libreria libft
# ${LIBFT}:
# 	@make bonus -C ${LIBFT_DIR}

# ${PNTF}: ${LIBFT}
# 	@make -C ${PNTF_DIR} 

# ${GNL}:
# 	@make bonus -C ${GNL_DIR}

# # Crea la libreria del progetto unendo libft.a e i file oggetto del progetto
# ${NAME}: ${LIBFT} ${PNTF} ${GNL} ${OBJS}
# 	@cp ${LIBFT} ${PNTF} ${GNL} ${NAME}
# 	@ar -rcs ${NAME} ${OBJS}

# # Regola per compilare i file .o
# %.o: %.c
# 	${CC} ${FLAGS} -c $< -o $@
# #	${CC} ${FLAGS} ${INC} -c $< -o $@

# # Pulisce i file oggetto del progetto e della libreria
# clean:
# 	@make clean -C ${LIBFT_DIR} ${PNTF_DIR} ${GNL_DIR}
# 	rm -f ${OBJS}

# # Pulisce tutto, inclusa la libreria finale
# fclean: clean
# 	@make fclean -C ${LIBFT_DIR} ${PNTF_DIR} ${GNL_DIR}
# 	rm -f ${NAME}

# # Ricompila tutto
# re: fclean all

# .PHONY: all clean fclean re
