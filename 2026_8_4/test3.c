#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    const char* msg0 = "hello printf\n";
    const char* msg1 = "hello fwrite\n";
    const char* msg2 = "hello write\n";

    printf("%s", msg0);
    fwrite(msg1, 1, strlen(msg1), stdout);
    write(STDOUT_FILENO, msg2, strlen(msg2));

    fork();
    return 0;
}
