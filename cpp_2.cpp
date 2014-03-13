/*#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <cstdio>
#endif

#define CHAR_C
#define CPP_FORMAT
#define ASCII_

int main()
{
	#ifdef CHAR_C
		#ifdef C_FORMAT
			char c = 0;
			printf("Please input a char:");
			scanf("%c", &c);
			printf("%c\n", c);
		#endif
		#ifdef CPP_FORMAT
			char c(0);
			std::cout << "Please input a char:";
			std::cin >> c;
			std::cout << "Char is " << c << std::endl;
		#endif
	#endif
	#ifdef INT_C
		#ifdef C_FORMAT
			int c = 0;
			printf("Please input a int:");
			scanf("%d", &c);
			printf("%d\n", c);
		#endif
		#ifdef CPP_FORMAT
			int c(0);
			std::cout << "Please input a int:";
			std::cin >> c;
			std::cout << "Int is " << c << std::endl;
		#endif
	#endif
	#ifdef ASCII_
		printf("ASCII is %d\n", c);
	#endif

	return 0;
}*/

#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <cstring>
#include <algorithm>
#endif
#define MAX_SIZE 100

int main()
{
	char str[MAX_SIZE];
	std::cin >> str ;
	char *p = str;
	std::sort(p, p+10);
	std::cout << p << std::endl;
	return 0;
}