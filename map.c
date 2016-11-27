#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include "comparator.h"
#include "merge_sort.h"

int main(int argc, char **argv)
{
	clock_t tic = clock();
	if(argc != 3) exit(1);
	int fd, strings_amount;
	struct stat file_info;
	if((fd = open(argv[2], O_RDONLY, 0)) < 0)
	 {
	 	printf("error");
	 	exit(1);
	 }
	if(fstat(fd, &file_info) < 0)
	{
		printf("Unable to read file parameters");
		exit(1);

	}
	if(!file_info.st_size)
	{
		printf("File's empty");
		exit(1);
	}
	char *file = (char*)mmap(0, file_info.st_size , PROT_READ, MAP_PRIVATE, fd, 0) ;
	printf("%ld\n", file_info.st_size);
	if(file == MAP_FAILED)
	{
		fprintf(stdout, "Error, mmap file failed.\n");
    		exit(1);
	}
	strings_amount = atoi(argv[1]);
	char **strings = (char**)malloc(sizeof(char*) * strings_amount);
	int i = 1, j = 0;
	strings[0] = &(file[0]);
	while( (i!= strings_amount) && (j != file_info.st_size))
	{
		if((file[j++] == '\n') || (j == file_info.st_size -1)) 
		{
			strings[i++] = &(file[j]);
		}
	}
	strings_amount = i;
	merge_sort(strings, strings_amount);
	i = 0;
	j = 0;
	while((i < strings_amount) && (j < file_info.st_size -1))
	{
		while(strings[i][j] != '\n')
		{
			printf("%c", strings[i][j++]);
		}
		i++;
		j = 0;
		printf("\n");
	}

	free(strings);
	clock_t tac = clock();
	printf("%f\n", (double)(tac-tic)/CLOCKS_PER_SEC);
	return 0;

}