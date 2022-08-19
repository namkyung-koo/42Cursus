#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int num, int len)
{
	if (len == 1)
	{
		ft_putchar(num + '0');
		return ;
	}
	ft_putint(num / 10, len - 1);
	ft_putchar(num % 10 + '0');
}

void	ft_combn(int comb, int cur, int n)
{
	int	cnt;

	if (cur > n)
	{
		if (comb % 10 != n - 1)
			write(1, ", ", 2);
		ft_putint(comb, n);
		return ;
	}

	if (cur == 1)
		cnt = 0;
	else
		cnt = comb % 10 + 1;

	while (cnt < 10)
	{
		ft_combn(comb * 10 + cnt, cur + 1, n);
		cnt++;
	}
}

void	ft_print_combn(int n)
{
	ft_combn(0, 1, n);
}
