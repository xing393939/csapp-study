#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main (int argc, char **argv)
{
    struct stat st;
    char *type, *readok;

    if (stat(argv[1], &st) < 0) {
        perror("stat error");
    }
    if (S_ISREG(st.st_mode)) // 确定文件类型
        type = "regular";
    else if (S_ISDIR(st.st_mode))
        type = "directory";
    else
        type = "other";

    if ((st.st_mode & S_IRUSR)) // 检查读权限
        readok = "yes";
    else
        readok = "no";

    printf("type: %s, read: %s\n", type, readok);
    _exit(0);
}
