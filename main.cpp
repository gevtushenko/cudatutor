#include <iostream>

#include <command.h>

int main ()
{
  if (execution_result result = execute ("nvcc code.cu"))
    {
      std::cerr << "Error: " << result.get_error () << std::endl;
      return 1;
    }
}
