## Signals in Unix

* man signal
* for portability use sigaction
* SIG_IGN ( ignore signal )
* SIG_DFL ( default signal )
* returns previous handler

----
    #include <signal.h>
    int raise( int sig ); // send a signal to the caller
    int kill( pid_t pid, int sig ); // send signal to process
    
    typedef void (*sighandler_t)(int);
    sighandler_t signal( int signum, sighandler_t handler ); // Handle signals
    
    int sigaction( int sig, const struct sigaction *act, struct sigaction *oldact );
    // Check man sigaction
----
> Valid signals

* SIGABRT   : Abnromal termination
* SIGFPE    : floating point error
* SIGILL    : illegal instruction
* SIGINT    : interrupt
* SIGSEGV   : segmentation fault
* SIGTERM   : termination request
* SIGBUS    : bus error
* SIGQUIT   : quit

> Cannot be handled

* SIGSTOP   : can be continued with SIGCONT
* SIGKILL

> Non Reserved Signals

* SIGUSR1
* SIGUSR2

> in Bash use **kill** command to send signals

> kill -L to list all signals
