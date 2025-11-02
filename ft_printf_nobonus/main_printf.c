#include "includes/ft_printf.h"

int main(int argc, char const *argv[])
{
	int	i = INT_MAX + 1;
	int	d = INT_MIN - 1;
	int u = -UINT_MAX - 1;
	char c = '*';
	char *s = "Hello World";
	char *p = s;
	int	x = INT_MAX;
	int X = INT_MAX;
	
	ft_printf("%i\n", ft_printf("%i\n%d\n%u\n%c\n%s\n%p\n%x\n%X\n", i, d, u, c, s, &p, x ,X));
	ft_printf("%i\n", ft_printf(NULL));
	ft_printf("\n");
	printf("%i\n", printf("%i\n%d\n%u\n%c\n%s\n%p\n%x\n%X\n", i, d, u, c, s, &p, x ,X));
	printf("%i\n", printf(NULL));
	return 0;
}


int main(void)
{
	char *str;
	int i = 48;

	printf((char)i);
	str = (char *)malloc(sizeof(char) * 10);
}