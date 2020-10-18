#include<unistd.h>                                                                                                
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc, char* argv[]) {
	  if (argc != 3) {
	     printf("input ERROR\n");
	     exit(1);
		
	}
	  int fd_src = open(argv[1], O_RDONLY);
	  if (fd_src == -1) {
		    printf("open_src ERROR\n");
		    exit(1);
		
	}
	   int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
	  if (fd_dst == -1) {
		    printf("open_dst ERROR\n");
		    exit(1);
		
	}
	  char buf[1025];
	  while (1) {
		    memset(buf, 0x00, 1025);
		    int ret = read(fd_src, buf, 1024);
		    if (ret == -1) {
			       printf("read ERROR\n");
				   exit(1);
				   
			}
			else if (ret == 0)
				break;
			if (write(fd_dst, buf, ret) == -1) {
				printf("write ERROR\n");
				exit(1);
			}
	  }
	  close(fd_dst);
	  close(fd_src);
	  return 0;
	  
}
