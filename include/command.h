//
// Created by evtus on 1/7/2021.
//

#ifndef CUDATUTOR_COMMAND_H
#define CUDATUTOR_COMMAND_H

#include <string>
#include <optional>

class execution_result
{
  bool success = false;
  const std::string command_output;

public:
  execution_result (int error_code, std::string &&output)
      : success (error_code == 0)
      , command_output (std::move (output))
  {
  }

  operator bool () const
  {
    return !success;
  }

  const char *get_error () const
  {
    return command_output.c_str ();
  }
};

execution_result execute (const std::string &command);

#endif //CUDATUTOR_COMMAND_H
