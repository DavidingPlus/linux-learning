#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


static void childWork()
{
    int value = 10;
    value += 5;

    std::cout << "child: pid=" << getpid() << ", ppid=" << getppid() << ", value=" << value << std::endl;
}


int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        std::perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid)
    {
        childWork();
        return EXIT_SUCCESS;
    }

    int status;
    while (-1 == waitpid(pid, &status, 0))
    {
        if (errno != EINTR)
        {
            std::perror("waitpid");
            return EXIT_FAILURE;
        }
    }
    if (!WIFEXITED(status) || 0 != WEXITSTATUS(status))
    {
        std::cerr << "child did not exit successfully\n";
        return EXIT_FAILURE;
    }

    std::cout << "parent: pid=" << getpid() << ", child=" << pid << ", exit=" << WEXITSTATUS(status) << std::endl;
}
