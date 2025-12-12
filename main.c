/***************************************************************************************\
|												|										|
|   	    THIS MAIN TEST ONLY MANDATORY PART - BONUS PART IS EXECLUDED             	|
|   libft.h in my libftprintf.h should called "libft/" in the root of your repository	|
|												|										|
\***************************************************************************************/
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define TEST_COUNT 1000
#define STR_COUNT 5

int main(void)
{
	int ret_std, ret_ft;
	srand(time(NULL));

	const char *samples[STR_COUNT] = {"", "hello", "world", "ft_printf", NULL};

	printf("===== SUPER MULTI-STRING STRESS TEST =====\n\n");

	for (int i = 0; i < TEST_COUNT; i++) {
		int di = rand() % (INT_MAX / 2) - (INT_MAX / 4);
		unsigned int u = rand();
		char c = (char)(rand() % 128);
		const char *s1 = samples[rand() % STR_COUNT];
		const char *s2 = samples[rand() % STR_COUNT];
		const char *s3 = samples[rand() % STR_COUNT];
		void *p = (i % 10 == 0) ? NULL : (void *)(uintptr_t)(rand() % 0xFFFFF);
		unsigned int x = rand();
		unsigned int X = rand();

		ret_std = printf(
			"std %%d %%u %%c %%s %%s %%s %%p %%x %%X: |%d|%u|%c|%s|%s|%s|%p|%x|%X|\n",
			di, u, c,
			s1 ? s1 : "(null)",
			s2 ? s2 : "(null)",
			s3 ? s3 : "(null)",
			p, x, X
		);

		ret_ft = ft_printf(
			"ft  %%d %%u %%c %%s %%s %%s %%p %%x %%X: |%d|%u|%c|%s|%s|%s|%p|%x|%X|\n",
			di, u, c, s1, s2, s3, p, x, X
		);

		if (ret_std != ret_ft) {
			int fd = open("error.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
			if (fd == -1)
				return 1;

			int save = dup(1);
			dup2(fd, 1);
			printf("std  %%d %%u %%c %%s %%s %%s %%p %%x %%X: |%d|%u|%c|%s|%s|%s|%p|%x|%X|\n", di, u, c, s1, s2, s3, p, x, X);
			ft_printf("ft   %%d %%u %%c %%s %%s %%s %%p %%x %%X: |%d|%u|%c|%s|%s|%s|%p|%x|%X|\n", di, u, c, s1, s2, s3, p, x, X);
			printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! RET MISMATCH at iteration %d !!!\n", i);
			printf("ft:%d\nstd:%d\n", ret_ft, ret_std);

			fflush(stdout);
			dup2(save, 1);
			close(fd);
			close(save);
		}
	}

	printf("===== MULTI-STRING STRESS TEST COMPLETE =====\n");
	return 0;
}