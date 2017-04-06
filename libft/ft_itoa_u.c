#include "libft.h"

static int get_conv_size(long long value, int base)
{
  int i;

  i = 0;
  if (value == 0)
	{
      i++;
      return(i);
	}
  while(value)
	{
      value /= base;
      i++;
	}
  return(i);
}

char	*ft_itoa_u(unsigned long long n)
{
  int size;
  char *ret;
  char *conv = "0123456789";

  size = get_conv_size(n, 10);
  ret = (char*)malloc(sizeof(char) * (size + 1));
  while(size >= 0)
	{
      ret[--size] = conv[n % 10];
      n /= 10;
	}
  return(ret);
}
