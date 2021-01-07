#include <iostream>

#include <command.h>
#include <answer.h>
#include <config.h>

std::string gen_compilation_command ()
{
  std::string cmd = "nvcc -O3 --shared -o answer.so -I";
  cmd += get_boost_include_dir ();
  cmd += " question.cu";

  return cmd;
}

int main ()
{
  if (execution_result result = execute (gen_compilation_command ()))
    {
      std::cerr << "Error: " << result.get_error () << std::endl;
      return 1;
    }

  auto run = load_answer<int()> ("answer.so", "run");
  std::cout << run () << "\n";
}
