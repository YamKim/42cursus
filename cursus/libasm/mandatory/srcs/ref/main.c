#include <stdio.h>

int	ft_atoi_base(char *nbr, char *base);

int main(void) {
	printf("nbr: %d\n", ft_atoi_base("  -123 a", "0123456789"));	

	return (0);
}
