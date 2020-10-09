#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 3

void main(int argc, char *argv[]){

  int pid[5];
  int status;
  int i;
 
  for(i = 0; i < MAX; i++){
    pid[i] = fork();  //creates a child
    srandom(getpid());
 
    switch(pid[i]){
      case 0:    //child
        printf("In child, pid = %d, parent pid = %d ...\n", getpid(), getppid());
        sleep(random() % 3);
        printf("Child executing \"ls -l\"...\n");
        execl("/bin/ls","ls","-l", (char *)0);
        break;

      case -1:  //error
        break;

      default:  //parent process, PID is child's pid
        break;
    }
   
  }
  for(i = 0; i < MAX; i++){
    printf("Parent waiting on Child pid = %d...\n", pid[i]);
    wait(&status);  //parent waits until child terminates, then reaps the child
    printf("Child pid = %d terminated with status %d\n", pid[i], status);
  }
  printf("Parent terminating: Child status = %d\n",status);
/*  
  IN CLASS
 
  int val;
 
  if(argc < 2){
    printf("Warning Arg: must be > 2\n");
  }
 
  else{
    printf("Number of args = %d\n", argc);
   
    printf("Arg[%d] = %s\n", 0, argv[0]);
   
    val = atoi(argv[1]);
    printf("Arg[%d] = %d\n", 1, val);
  }
*/

}

