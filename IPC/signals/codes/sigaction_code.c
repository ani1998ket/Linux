#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigint_handler( int sig ){
    /* Write is async-safe( safe to call within handler ) and not printf */
    write(0, "SIGINT!\n", 9 );
    //printf("%d\n", sig);
}

int main(){
    void sigint_handler( int sig );
    char s[200];
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sa.sa_flags = SA_RESTART; // if 0 is written then system call( here fgets ) would exit with error
    sigemptyset( &sa.sa_mask );

    if( sigaction( SIGINT, &sa, NULL ) == -1 ){
        perror( "sigaction" );
        exit(1); 
    }

    printf("Enter a string:\n");

    if (fgets(s, sizeof s, stdin) == NULL)
        perror("fgets");
    else 
        printf("You entered: %s\n", s);

    return 0;
}
