#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {

  cout << "=====================\n";
  cout << "   SAM SHELL v1.0\n";
  cout << "=====================\n";
  cout << "Welcome Samar!\n\n";

  while (true) {

    // show prompt
    cout << "myshell> ";

    // read input
    string command;
    getline(cin, command);

    // convert string to char*
    char *args[] = {const_cast<char *>(command.c_str()), NULL};

    // create child process
    pid_t pid = fork();

    if (pid == 0) {

      // child process
      execvp(args[0], args);

      // exec only reaches here if failed
      cout << "Command failed\n";
    } else {

      // parent waits
      waitpid(pid, NULL, 0);
    }
  }

  return 0;
}