#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("THIS SHOULD NOT PRINT ON THE TERMINAL\n");
    } else {
        wait(NULL);
        printf("Success\n");
        printf("Some post processing goes here\n");
    }

    return 0;
}

/*
int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
        if (err == -1) {
            printf("Could not find program to execute or other error ocurred\n");
            return 2;
        }
    } else {
        int wstatus;
        wait(&wstatus);
        
        if (WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus);
            if (statusCode == 0) {
                printf("Success\n");
            } else {
                printf("Failure with status code %d\n", statusCode);
            }
        }
    }

    return 0;
}
*/

/*
int main(int argc, char* argv[]) {
    char* arr[] = {
        "ping",
        "google.com",
        NULL
    };
    
    char* env[] = {
        "TEST=environment variables",
        NULL
    };
    
    // Without env and PATH variable
    _execv("C:\\Windows\\System32\\ping.exe", "C:\\Windows\\System32\\ping.exe", "google.com", NULL);
    _execl("C:\\Windows\\System32\\ping", arr);
    
    // Without env but with PATH variable
    _execvp("ping", "ping", "google.com", NULL);
    _execlp("ping", arr);
    
    // With env and PATH variable
    _execvpe("ping", "ping", "google.com", NULL, env);		// THIS ONE
    _execlpe("ping", arr, env);
    

    return 0;
}
*/