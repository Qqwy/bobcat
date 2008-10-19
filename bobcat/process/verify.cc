#include "process.ih"

bool Process::verify()
{
    static fstream null(0);

    if (d_waiter.pid != 0)
    {
        int retWaiter = waitpid(d_waiter.pid, &d_waiter.ret, WNOHANG);

        if (retWaiter == d_waiter.pid)
        {
            d_waiter.pid = 0;               // process has ended
            discontinue(d_child);
        }
    }
    else if (d_child.pid)
    {
        int retChild = waitpid(d_child.pid, &d_child.ret, WNOHANG);
        if (retChild == d_child.pid)
        {
            d_child.pid = 0;               // process has ended
            discontinue(d_waiter);
        }
    }

    if (d_child.pid == 0)
        open(null, null);
        
    return d_child.pid;
}


