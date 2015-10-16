#include "flitter.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

void Help();

int main(int argc, char *argv[])
{
  Flitter* flitter = new Flitter();
  
  std::string command;
  
  while(command.compare("exit") != 0)
  {
    std::cout << "Enter a command or type help: ";
    std::cin >> command;
	getchar();
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    
    if(command.compare("adduser") == 0)
    {
      flitter->CreateUser();
    }
    else if(command.compare("fleet") == 0)
    {
      flitter->FleetMessage();
    }
    else if(command.compare("follow") == 0)
    {
      flitter->Follow();
    }
    else if(command.compare("showfleets") == 0)
    {
      flitter->SeeFleets();
    }
    else if(command.compare("unfollow") == 0)
    {
      flitter->Unfollow();
    }
    else if(command.compare("help") == 0)
    {
      Help();
    }
    else if(command.compare("exit") == 0)
    {
      std::cout << "Exiting" << std::endl;
    }
    else
    {
      std::cout << "Invild input!" << std::endl;
    }
  }
}

void Help()
{
}
