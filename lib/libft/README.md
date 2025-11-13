
---

## **libft2.0**
```markdown
# Libft 2.0 - Enhanced C Library

The second, enhanced iteration of my personal standard C library. It recodes a wide array of standard `libc` functions, along with additional helper functions for linked lists, memory allocation, and string manipulation.

## 📚 Functions Included

### Standard Libc Functions
- **Memory**: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- **String**: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`
- **String**: `ft_strnstr`, `ft_strncmp`, `ft_atoi`
- **Character**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **Conversion**: `ft_toupper`, `ft_tolower`

### Memory Management
- `ft_calloc`, `ft_strdup`

### Additional Functions
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_itoa`, `ft_strmapi`, `ft_striteri`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Bonus (Linked Lists)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`
- `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## 🚀 Usage
```bash
make
# Include libft.a in your project compilation
gcc your_program.c -L. -lft
