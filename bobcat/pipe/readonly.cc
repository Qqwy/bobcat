#include "pipe.ih"

int Pipe::readOnly()
{
    close(d_fd[WRITE]);
    return d_fd[READ];
}
