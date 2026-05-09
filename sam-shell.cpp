#include <iostream>
#include <sstream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <cstring>

using namespace std;

int main() {

  cout << "=====================\n";
  cout << "   SAM SHELL v1.1\n";
  cout << "=====================\n";
  cout << "Welcome Samar!\n\n";

  while (true) {

    // show prompt
    cout << "myshell> ";

    // read full line
    string command;
    getline(cin, command);

    // split command into tokens
    stringstream ss(command);

    string token;

    vector<char *> args;

    while (ss >> token) {

      args.push_back(strdup(token.c_str()));
    }

    // execvp needs NULL at end
    args.push_back(NULL);

    //safety check
    if(args.size() == 1) {
    continue;
}

    // create child process
    pid_t pid = fork();

    if (pid == 0) {

      // child process executes command
      execvp(args[0], args.data());

      // only runs if exec fails
      cout << "Command failed\n";
      exit(1);
    } else {

      // parent waits
      waitpid(pid, NULL, 0);
    }
  }

  return 0;
}