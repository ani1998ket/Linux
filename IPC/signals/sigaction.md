## Sigaction

    int sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);

> Handler function must be async safe( man signal-safety )

### Important fields in struct sigaction

* sa_handler    : Signal Handler( SIG_IGN to ignore )
* sa_mask       : set of signals to block when this is handled
* sa_flags      : flags to modify behaviour of handler, or 0

### Set operations for sa_mask

* sigemptyset()
* sigfillset()
* sigaddset()
* sigdelset()
* sigismember()


### Intution behind sa_flags = SA_RESTART

    restart:
    if (some_system_call() == -1) {
        if (errno == EINTR) goto restart;
        perror("some_system_call");
        exit(1);
    }
