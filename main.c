/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:38 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/04 13:59:03 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Credit : Many thanks to R. Monnier for the test file.
*/

#include "incl/ft_printf.h"
#include <limits.h>
# include <stdio.h>
# include <locale.h>

int		main(int ac, char **av)
{
	int		n;
	int		m;
	int		i;
	int		j;
	unsigned char	k;
	int		i1;
	int		i2;
	char	*str;
	char	c;

	setlocale(LC_ALL, "");
	(void)ac;


/*

	printf("\n--intmax en hex--\n");
	n = 2147483647;
	i = ft_printf("Mon printf  : %x\n", n);
	j = printf("Vrai printf : %x\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n--%%--\n");
	i = ft_printf("Mon printf  : %%\n");
	j = printf("Vrai printf : %%\n");
	printf("Moi %d Le vrai : %d\n", i, j);


	printf("\n--intmax avec %%hlhx en hex--\n");
	n = 2147483647;
	i = ft_printf("Mon printf  : %hlhx\n", n);
	j = printf("Vrai printf : %hlhx\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n--unsigned char 128 en hex--\n");
	k = 128;
	i = ft_printf("Mon printf  : %hhx\n", k);
	j = printf("Vrai printf : %hhx\n", k);
	printf("Moi %d Le vrai : %d\n", i, j);



printf("\nprintf(\"%%S\", L\"我是一只猫。)\n");
	i = ft_printf("%S", L"我是一只猫。");
	printf(" -> %d for my PF\n", i);
	j = printf("%S", L"我是一只猫。");
	printf(" -> %d for LIBC PF\n", j);



	i = ft_printf("%x", -42);      // a revoir
	printf(" -> %d for my PF\n", i);
	j = printf("%x", -42);  
	printf(" -> %d for LIBC PF\n", j);   
	i = ft_printf("%X", -42);  
	printf(" -> %d for my PF\n", i);
	j = printf("%X", -42);  
	printf(" -> %d for LIBC PF\n", j);        



ft_printf("%#x", 0); 
printf("%#x", 0);  // a revoir


	printf("\n-- %%l15d --\n"); // a revoir
	n = 2147483647;
	i = ft_printf("Mon printf  : %15d\n", 2147483647);
	j = printf("Vrai printf : %15d\n", 2147483647);
	printf("Moi %d Le vrai : %d\n", i, j);

	

	printf("\n-- int with + and precision --\n"); // a revoir
	n = 13;
	i = ft_printf("Mon printf  : %+.5d\n", n);
	j = printf("Vrai printf : %+.5d\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);




printf("\n--pointeur--\n");
	i = ft_printf("Mon printf  : %p\n", &k);
	j = printf("Vrai printf : %p\n", &k);
	printf("Moi %d Le vrai : %d\n", i, j);


	printf("\n-- invalid identifier --\n");     
	j = printf("Vrai printf : %010y\n");
	i = ft_printf("Mon printf  : %010y\n");
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- %%n --\n");
	j = printf("Vrai printf : %5n\n", &i2);
	printf("%d\n", i2);
	i = ft_printf("Mon printf  : %5n\n", &i1);
	printf("%d\n", i1);
	printf("Moi %d Le vrai : %d\n", i, j);
	
	printf("\n-- int with 0 and precision --\n");
	n = 13;
	i = ft_printf("Mon printf  : %0.5d\n", n);
	j = printf("Vrai printf : %0.5d\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);



	printf("\n-- X with # --\n");
	n = 13;
	i = ft_printf("Mon printf  : %#X\n", n);
	j = printf("Vrai printf : %#X\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);




	printf("\n-- %%color --\n");                     
	i = ft_printf("%{red}haha\n");
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- int with 0 and width --\n");     
	n = 13;
	i = ft_printf("Mon printf  : %05d\n", n);
	j = printf("Vrai printf : %05d\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);




	printf("\n-- ld puis Ld avec int int int --\n");
	n = 13;
	i = ft_printf("Mon printf  : %ld et %Ld\n", 10, 11, 12);
	j = printf("Vrai printf : %ld et %Ld\n", 10, 11, 12);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- test --\n");
	n = 13;
	i = ft_printf("");
	j = printf("");
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- string --\n");
	str = "Félin";
	i = ft_printf("Mon printf  : %s\n", str);
	j = printf("Vrai printf : %s\n", str);
	printf("Moi %d Le vrai : %d\n", i, j);









	printf("\n-- character --\n");                   
	c = 'z';
	i = ft_printf("Mon printf  : %c\n", c);
	j = printf("Vrai printf : %c\n", c);
	printf("Moi %d Le vrai : %d\n", i, j);



	printf("\n-- %% tout seul --\n");
	i = ft_printf("%");
	j = printf("%");
	printf("Moi %d Le vrai : %d\n", i, j);



	printf("\n-- %%+n --\n");                     
	i = ft_printf("%+10.0d\n", 0);
	j = printf("%+10.0d\n", 0);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- %%f --\n");                          
	i = ft_printf("{%f}{%F}\n", 1.42, 1.42);
	j = printf("{%f}{%F}\n", 1.42, 1.42);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- %%Lf --\n");                      
	long double ld = 46.646;
	i = ft_printf("{%f}\n{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	j = printf("{%f}\n{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\nprintf(\"%%#08x\", 42)\n"); // a revoir
	i = ft_printf("%#08x", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%#08x", 42);
	printf(" -> %d for LIBC PF\n", j);




	printf("\n-- %%5%% --\n");
	i = ft_printf("%5%");
	printf(" -> %d for my PF\n", i);
	j = printf("%5%");
	printf(" -> %d for LIBC PF\n", j);
		

	printf("\n-- %%10x%% --\n");
	i = ft_printf("%10x", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%10x", 42);
	printf(" -> %d for LIBC PF\n", j);

	printf("\n-- %%-10x%% --\n");
	i = ft_printf("%-10x", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%-10x", 42);
	printf(" -> %d for LIBC PF\n", j);


printf("\nprintf(\"%%010x\", 542)\n");
	i = ft_printf("%010x", 542);
	printf(" -> %d for my PF\n", i);
	j = printf("%010x", 542);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"%%-10x\", 42)\n");
	i = ft_printf("%-10x", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%-10x", 42);
	printf(" -> %d for LIBC PF\n", j);


	printf("\nprintf(\"%%10x\", 42)\n");
	i = ft_printf("%10x", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%10x", 42);
	printf(" -> %d for LIBC PF\n", j);

		printf("\nprintf(\"%%2x\", 542)\n");
	i = ft_printf("%2x", 542);
	printf(" -> %d for my PF\n", i);
	j = printf("%2x", 542);
	printf(" -> %d for LIBC PF\n", j);

		
	printf("\nprintf(\"%%c\", 'c')\n");
	i = ft_printf("%c", 'c');
	printf(" -> %d for my PF\n", i);
	j = printf("%c", 'c');
	printf(" -> %d for LIBC PF\n", j);



	printf("\nprintf(\"%%d\", -42)\n");
	i = ft_printf("%d", -42);
	printf(" -> %d for my PF\n", i);
	j = printf("%d", -42);
	printf(" -> %d for LIBC PF\n", j);


	printf("\nprintf(\"%% d\", -9999)\n");
	i = ft_printf("% d", -9999);
	printf(" -> %d for my PF\n", i);
	j = printf("% d", -9999);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"%%15.4s\", \"42\")\n");
	i = ft_printf("%15.4s", "42");
	printf(" -> %d for my PF\n", i);
	j = printf("%15.4s", "42");
	printf(" -> %d for LIBC PF\n", j);

		printf("\nprintf(\"{%%s}\", \"abc\")\n");
j = printf("%s", "abc");
	printf(" -> %d for LIBC PF\n", j);
	i = ft_printf("%s", "abc");
	printf(" -> %d for my PF\n", i);

	printf("\nprintf(\"%%D\", LONG_MAX)\n");
	i = ft_printf("%D", LONG_MAX);
	printf(" -> %d for my PF\n", i);
	j = printf("%D", LONG_MAX);
	printf(" -> %d for LIBC PF\n", j);




	printf("\nprintf(\"{%%5p}\", 0) \n");
	i = ft_printf("{%5p}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%5p}", 0);
	printf(" -> %d for LIBC PF\n", j);

	


		printf("\nprintf(\"{%%4d}\", 10000)\n");
	i = ft_printf("{%4d}", 10000);
	printf(" -> %d for my PF\n", i);
	j = printf("{%4d}", 10000);
	printf(" -> %d for LIBC PF\n", j);

		printf("\nprintf(\"{%%10d}\", 42)\n");
	i = ft_printf("{%10d}", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("{%10d}", 42);
	printf(" -> %d for LIBC PF\n", j);
	
printf("\nprintf(\"%%O\", LONG_MIN)\n");
	i = ft_printf("%O", LONG_MIN);
	printf(" -> %d for my PF\n", i);
	j = printf("%O", LONG_MIN);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"{%%03c}\", 0)\n");
	i = ft_printf("{%03c}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%03c}", 0);
	printf(" -> %d for LIBC PF\n", j);


	printf("\nprintf(\"{%%05.c}\", 0)\n");
	i = ft_printf("{%05.c}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%05.c}", 0);
	printf(" -> %d for LIBC PF\n", j);


		printf("\nprintf(\"{%%5}\", 0)\n");
	i = ft_printf("{%d}", -5);
	printf(" -> %d for my PF\n", i);
	j = printf("{%d}", -5);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"{%%.4d}\", 42)\n");
	i = ft_printf("{%.4d}", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("{%.4d}", 42);
	printf(" -> %d for LIBC PF\n", j);


	
printf("\nprintf(\"{%%03.2d}\", 5)\n");
	i = ft_printf("{%03.2d}", 5);
	printf(" -> %d for my PF\n", i);
	j = printf("{%03.2d}", 5);
	printf(" -> %d for LIBC PF\n", j);
	
printf("\nprintf(\"%%.4d\", 424242)\n");
	i = ft_printf("%.4d", 424242);
	printf(" -> %d for my PF\n", i);
	j = printf("%.4d", 424242);
	printf(" -> %d for LIBC PF\n", j);

printf("\nprintf(\"{%%05.s}\", 0)\n");
	i = ft_printf("{%05.s}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%05.s}", 0);
	printf(" -> %d for LIBC PF\n", j);

printf("\nprintf(\"{%%05s}\", \"abc\")\n");
	i = ft_printf("{%05s}", "abc");
	printf(" -> %d for my PF\n", i);
	j = printf("{%05s}", "abc");
	printf(" -> %d for LIBC PF\n", j);


printf("\nprintf(\"%%15.4s\", \"I am 42\")\n");
	i = ft_printf("%15.4s", "I am 42");
	printf(" -> %d for my PF\n", i);
	j = printf("%15.4s", "I am 42");
	printf(" -> %d for LIBC PF\n", j);
	
printf("\nprintf(\"{%%1RA}\")\n");
	i = ft_printf("{%1RA}");
	printf(" -> %d for my PF\n", i);
	j = printf("{%1RA}");
	printf(" -> %d for LIBC PF\n", j);
	
		printf("\nprintf(\"%% Zoooo\")\n");
	i = ft_printf("% Zoooo");
	printf(" -> %d for my PF\n", i);
	j = printf("% Zoooo");
	printf(" -> %d for LIBC PF\n", j);

printf("\nprintf(\"%%+o\", 0)\n");
	i = ft_printf("%+o", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("%+o", 0);
	printf(" -> %d for LIBC PF\n", j);



printf("\nprintf(\"%%+d\", 42)\n");
	i = ft_printf("%+d", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%+d", 42);
	printf(" -> %d for LIBC PF\n", j);
	
	printf("\nprintf(\"%%10R\");\n");
	i = ft_printf("%10R");
	printf(" -> %d for my PF\n", i);
	j = printf("%10R");
	printf(" -> %d for LIBC PF\n", j);

printf("\nprintf(\"%%4.15s\", \"I am 42\")\n");
	i = ft_printf("%4.15s", "I am 42");
	printf(" -> %d for my PF\n", i);
	j = printf("%4.15s", "I am 42");
	printf(" -> %d for LIBC PF\n", j);

printf("\nprintf(\"%% u\", 9999)\n");
	i = ft_printf("% u", 9999);
	printf(" -> %d for my PF\n", i);
	j = printf("% u", 9999);
	printf(" -> %d for LIBC PF\n", j);



printf("\nprintf(\"%%c\", 200)\n");
	i = ft_printf("%c", 200);
	printf(" -> %d for my PF\n", i);
	j = printf("%c", 200);
	printf(" -> %d for LIBC PF\n", j);


	printf("\nprintf(\"%% u|%%+u\", 42, 42)\n");
	i = ft_printf("% u|%+u", 42, 42);
	printf(" -> %d for my PF\n", i);
	j = printf("% u|%+u", 42, 42);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"{%%-15Z}\", 123)\n");
	i = ft_printf("{%-15Z}", 123);
	printf(" -> %d for my PF\n", i);
	j = printf("{%-15Z}", 123);
	printf(" -> %d for LIBC PF\n", j);
	printf("\nprintf(\"{%%05.%%}\", 0)\n");
	i = ft_printf("{%05.%}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%05.%}", 0);
	printf(" -> %d for LIBC PF\n", j);


	printf("\nprintf(\"{%%05.Z}\", 0)\n");
	i = ft_printf("{%05.Z}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%05.Z}", 0);
	printf(" -> %d for LIBC PF\n", j);
	
	printf("\nprintf(\"{%%#.5x}\", 1)\n");
	i = ft_printf("{%#.5x}", 1);
	printf(" -> %d for my PF\n", i);
	j = printf("{%#.5x}", 1);
	printf(" -> %d for LIBC PF\n", j);
	






	printf("\nprintf(\"%%+d\", -42)\n");
	i = ft_printf("%+d", -42);
	printf(" -> %d for my PF\n", i);
	j = printf("%+d", -42);
	printf(" -> %d for LIBC PF\n", j);
	
		printf("\n-- %%color --\n");                     
	i = ft_printf("%{red}haha\n");
	printf(" -> %d for my PF\n", i);
	j = printf("%{red}haha\n");
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"{%% S}\", NULL);\n");
	j = printf("{% S}", NULL);
	printf(" -> %d for LIBC PF\n", j);
	i = ft_printf("{% S}", NULL);
	printf(" -> %d for my PF\n", i);
	
	printf("\nprintf(\"{%%05.S}\", L\"42 c est cool\")\n");
	i = ft_printf("{%05.S}", L"42 c est cool");
	printf(" -> %d for my PF\n", i);
	j = printf("{%05.S}", L"42 c est cool");
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"%%.4S\", L\"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B\")\n");
	i = ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for my PF\n", i);
	j = printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"%%.4S\", L\"我是一只猫。\")\n");
	i = ft_printf("%.4S", L"我是一只猫。");
	printf(" -> %d for my PF\n", i);
	j = printf("%.4S", L"我是一只猫。");
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"{%% S}\", L\"(null)\")\n");
	i = ft_printf("{% S}", L"(null)");
	printf(" -> %d for my PF\n", i);
	j = printf("{% S}", L"(null)");
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf((\"%%4.1S\", L\"Jambon\")\n");
	i = ft_printf("%4.1S", L"Jambon");
	printf(" -> %d for my PF\n", i);
	j = printf("%4.1S", L"Jambon");
	printf(" -> %d for LIBC PF\n", j);
	
printf("\nprintf(\"{%% S}\", L\"(null)\")\n");
	i = ft_printf("{% S}", L"(null)");
	printf(" -> %d for my PF\n", i);
	j = printf("{% S}", L"(null)");
	printf(" -> %d for LIBC PF\n", j);
	
	printf("\nprintf(\"%%.4S\", L\"我是一只猫。\")\n");
	i = ft_printf("%.4S", L"我是一只猫。");
	printf(" -> %d for my PF\n", i);
	j = printf("%.4S", L"我是一只猫。");
	printf(" -> %d for LIBC PF\n", j);


printf("\nprintf(\"{%%05p}\", 0)\n");
	i = ft_printf("{%05p}", 0);
	printf(" -> %d for my PF\n", i);
	j = printf("{%05p}", 0);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"{%% S}\", L\"(null)\")\n");
	i = ft_printf("{% S}", L"(null)");
	printf(" -> %d for my PF\n", i);
	j = printf("{% S}", L"(null)");
	printf(" -> %d for LIBC PF\n", j);






	printf("\nprintf(\"{%%S}\", NULL)\n");
	i = ft_printf("{%S}", NULL);
	printf(" -> %d for my PF\n", i);
	j = printf("{%S}", NULL);
	printf(" -> %d for LIBC PF\n", j);        



			printf("\n-- %%O, LONG_MAX --\n");            
	i = ft_printf("%O", LONG_MAX);
	printf(" -> %d for my PF\n", i);
	j = printf("%O", LONG_MAX);
	printf(" -> %d for LIBC PF\n", j);
	
		printf("\n  \n");
	i = ft_printf("%X", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%X", 42);
	printf(" -> %d for LIBC PF\n", j);


   



			printf("\n  \n");
	i = ft_printf("%X", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%X", 42);
	printf(" -> %d for LIBC PF\n", j);

	
printf("\nprintf(\"%%s\", \"abc\")\n");
	i = ft_printf("%s", "abc");
	printf(" -> %d for my PF\n", i);
	j = printf("%s", "abc");
	printf(" -> %d for LIBC PF\n", j);

	//	printf("\nprintf(\"%%*d\", 5, 42);\n"); 

		i = ft_printf("%15.4d", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%15.4d", 42);
	printf(" -> %d for LIBC PF\n", j);


i = ft_printf("{%.*s}", -5, "42");
	printf(" -> %d for my PF\n", i);
	j = printf("{%.*s}", -5, "42");
	printf(" -> %d for LIBC PF\n", j); 

		i = ft_printf("{%.*s}", 0, "42");
	printf(" -> %d for my PF\n", i);
	j = printf("{%.*s}", 0, "42");
	printf(" -> %d for LIBC PF\n", j);  


	i = ft_printf("{%*d}", -5, 42);
	printf(" -> %d for my PF\n", i);
	j = printf("{%*d}", -5, 42);
	printf(" -> %d for LIBC PF\n", j);

	i = ft_printf("%*.*d", 0, 3, 0);
	printf(" -> %d for my PF\n", i);
	j = printf("%*.*d", 0, 3, 0);
	printf(" -> %d for LIBC PF\n", j);

	 		i = ft_printf("{%.*s}", 0, "42");
	printf(" -> %d for my PF\n", i);
	j = printf("{%.*s}", 0, "42");
	printf(" -> %d for LIBC PF\n", j);  
	
	i = ft_printf("{%f}{%F}", -1.42, -1.42);
	printf(" -> %d for my PF\n", i);
	j = printf("{%f}{%F}", -1.42, -1.42);
	printf(" -> %d for LIBC PF\n", j);


	  int val;
	i = ft_printf("blah %n blah\n", &val);
	printf(" -> %d for my PF\n", i);
	j = printf("blah %n blah\n", &val);
	printf(" -> %d for LIBC PF\n", j);
	
	//	printf("\nprintf(\"%%-5%%\");\n");
	i = ft_printf("%-5%");
	printf(" -> %d for my PF\n", i);
	j = printf("%-5%");
	printf(" -> %d for LIBC PF\n", j);

//printf("\nprintf(\"%%#08x\", 42);\n");
	i = ft_printf("%#08x", 42); 
	printf(" -> %d for my PF\n", i);
	j = printf("%#08x", 42); 
	printf(" -> %d for LIBC PF\n", j);



printf("\nprintf(\"%% \")\n");
	i = ft_printf("% ");  
	printf(" -> %d for my PF\n", i);
	j = printf("% ");  
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"%% h\")\n");
	i = ft_printf("% h"); 
	printf(" -> %d for my PF\n", i);
	j = printf("% h"); 
	printf(" -> %d for LIBC PF\n", j);
	
	
//printf("\nprintf(\"%%5+d\", 42)\n");
	i = ft_printf("%5+d", 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%5+d", 42);
	printf(" -> %d for LIBC PF\n", j);




	//printf("\nprintf(\"%%ll#x\", 9223372036854775807)\n");
	i = ft_printf("%ll#x", 9223372036854775807);
	printf(" -> %d for my PF\n", i);
	j = printf("%ll#x", 9223372036854775807);
	printf(" -> %d for LIBC PF\n", j);





	i = ft_printf("%4.S", L"我是一只猫。");
	printf(" -> %d for my PF\n", i);
	j = printf("%4.S", L"我是一只猫。");
	printf(" -> %d for LIBC PF\n", j);


	//	printf("\nprintf(\"{%%05p}\", 0)\n");   // OK as undefined
	j = printf("{%05p}", 0);
	printf(" -> %d for LIBC PF\n", j);
	i = ft_printf("{%05p}", 0);
	printf(" -> %d for my PF\n", i);

	printf("\nprintf(\"{%%s}\", 0)\n");
j = printf("{%s}", 0);
	printf(" -> %d for LIBC PF\n", j);
	i = ft_printf("{%s}", 0);
	printf(" -> %d for my PF\n", i);

		i = ft_printf("%d", 5);
	printf(" -> |%d| for my PF\n", i);
	j = printf("%d", 5);
	printf(" -> |%d| for LIBC PF\n\n", j);

	printf("\n--et -16 en hexa--\n");
	n = -16;
	i = ft_printf("Mon printf  : %x\n", n);
	j = printf("Vrai printf : %x\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n--13 et 16 en hexa--\n");
	n = 16;
	m = 13;
	i = ft_printf("Mon printf  : %x et %x\n", m, n);
	j = printf("Vrai printf : %x et %x\n", m, n);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n--13 et 15 en hexa--\n");
	n = 15;
	m = 13;
	i = ft_printf("Mon printf  : %x et %X\n", m, n);
	j = printf("Vrai printf : %x et %X\n", m, n);
	printf("Moi %d Le vrai : %d\n", i, j);

		printf("--16 en hexa--\n");
	i = ft_printf("Mon printf  : %x\n", 16);
	j = printf("Vrai printf : %x\n", 16);
	printf("Moi %d Le vrai : %d\n", i, j);




		printf("-- abc --\n");
	i = ft_printf("Mon printf  : %s\n", "abc");
	j = printf("Vrai printf : %s\n", "abc");
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- string unicode --\n"); 
	i = ft_printf("Mon printf  : %S\n", L"élodie");
	j = printf("Vrai printf : %S\n", L"élodie");
	printf("Moi %d Le vrai : %d\n", i, j);

	//printf("\nprintf(\"%%15.4S\", L\"我是一只猫。\");\n");
	i = ft_printf("%15.4S", L"我是一只猫。");
	printf(" -> %d for my PF\n", i);
	j = printf("%15.4S", L"我是一只猫。");
	printf(" -> %d for LIBC PF\n", j);



	printf("\nprintf(\"%%S\", L\"Á±≥\")\n");
	i = ft_printf("%S", L"Á±≥");
	printf(" -> %d for my PF\n", i);
	j = printf("%S", L"Á±≥");
	printf(" -> %d for LIBC PF\n", j);


	printf("\n-- %%S 414 --\n"); 
	i = ft_printf("%lc\n", 414);
	j = printf("%lc\n", 414);
	printf("Moi %d Le vrai : %d\n", i, j);


	printf("\n-- %%S 414 --\n"); 
	i = ft_printf("%c\n", 414);
	j = printf("%c\n", 414);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\nprintf(\"%%15.4S\", L\"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B\")\n");
	i = ft_printf("%15.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for my PF\n", i);
	j = printf("%15.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for LIBC PF\n", j);


		printf("\nprintf(\"%%ls, %%ls\", L\"ÊM-^ZM-^VÁM-^BM-^I\", L\"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±\")\n");
	i = ft_printf("%ls, %ls", L"ÊM-^ZM-^VÁM-^BM-^I", L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±");
	printf(" -> %d for my PF\n", i);
	j = printf("%ls, %ls", L"ÊM-^ZM-^VÁM-^BM-^I", L"ŸM-^Dÿ≠ŸM-^E ÿÆŸM-^Fÿ≤ŸM-ÿ±");
	printf(" -> %d for LIBC PF\n", j); 


	printf("\nprintf(\"{%%30S}\", L\"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B\")\n"); 
	i = ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for my PF\n", i);
	j = printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for LIBC PF\n", j);
printf("\nprintf(\"{%%030S}\", L\"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B\")\n");
	i = ft_printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for my PF\n", i);
	j = printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf(" -> %d for LIBC PF\n", j);
	
	ft_dprintf("%05d\n", 42);
	dprintf("%05d\n", 42);

	i = ft_printf("blabla%d blabla %C", 5, 1334567); // a revoir
	printf(" -> %d for my PF\n", i);
	j = printf("blabla%d blabla %C", 5, 1234567);
	printf(" -> %d for LIBC PF\n", j);

	printf("\nprintf(\"%%*d\", 5, 42);\n");
	i = ft_printf("%*d", 5, 42);
	printf(" -> %d for my PF\n", i);
	j = printf("%*d", 5, 42);
	printf(" -> %d for LIBC PF\n", j);    

*/

	
	i = ft_printf("{%05.*d}", -15, 42);
	printf(" -> %d for my PF\n", i);
	j = printf("{%05.*d}", -15, 42);
	printf(" -> %d for LIBC PF\n", j);
  


	/*


	printf("\n  \n");
	i = ft_
	printf(" -> %d for my PF\n", i);
	j = 
	printf(" -> %d for LIBC PF\n", j);


	*/

}
