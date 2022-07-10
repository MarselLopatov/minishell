#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;

	close (3);
	fd = open ("filename.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("%d\n", fd);
}
