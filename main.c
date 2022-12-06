#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // linux specific file in order to use fork method


int main(int argc, char* argv){
    int id = fork();
    // printf("Hello World! from id: %d\n", id);
    if (id != 0){
        fork();
        printf("I am a parent process and I'm allowed to fork. The process id: %d\n",id);
    }else{
        printf("I am a child process. I am not forking\n");
    }
    
    // if( id == 0){
    //     printf("Hello from child process\n");
    // } else {
    //     printf("Hello from parent process\n");
    // }
    return 0;
}