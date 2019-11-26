#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * This program demonstates the use of exec and fork
 */
int main(int argc, char const *argv[])
{
    printf("About to create new process hello\n");
    //first I will  call fork() to make a copy of myself
    //from that copy I'll call exec
    //exec will then get loaded into the forked process not the main process
    int pid = fork();
    //child process gets assigned pid 0
    if(pid == 0)
    {
        int ret = execl("/home/os1600/vsc_workspace/week5_exec_struct/hello",
    "/home/os1600/vsc_workspace/week5_exec_struct/hello","Kat",NULL);
   // int ret = execl("/bin/ls","/bin/ls",NULL);

    }
    

    //wait for the child process to terminate and then continue main process
    //parent process takes itself out of ready queue when it calls wait
    //parent is put back in ready queue when child terminates
    wait(NULL);
    printf("parent process still running\n");
    //if we want this process to continue to run with the new one use fork before exec
    return 0;
}