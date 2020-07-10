#include <stdio.h>
#include <signal.h>

void sigproc(){
    //signal( SIGINT, sigproc );
    printf("You pressed Ctrl C\n");
}
void quitproc(){
    printf("Quitting\n" );
    exit(0);
}

int main(){
    signal( SIGINT, sigproc );
    signal( SIGQUIT, quitproc );
    printf( "Ctrl C disabled, Use Ctrl \\ to quit\n" );
    while(1);
    return 0;
}
