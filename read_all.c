#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

char *get_next_line(int fd)
{
	char buff[6];
	static char stack[5];
	int i = 0;
	int j = 0;
	int ret;

//	buff = (char *)malloc(5 * sizeof(char));
	while((ret = read(fd, buff, 5)) != 0){
		buff[5] = '\0';
		i = 0;
		while(buff[i])
		{
			stack[j] = buff[i];
			i++;
			j++;
		}
//		free(buff);
	}
	return (stack);
}

int main()
{
	int fd = open("/Users/fael-bou/Desktop/gnl/file.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
