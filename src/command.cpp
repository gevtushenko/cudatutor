//
// Created by evtus on 1/7/2021.
//

#include "command.h"

#include <boost/process.hpp>

using namespace boost::process;

std::string pipe_to_str (ipstream &pipe_stream)
{
  std::string line;
  std::string output;

  while (pipe_stream && std::getline (pipe_stream, line) && !line.empty ())
    output += line;

  return output;
}

execution_result execute (const std::string &command)
{
  ipstream std_pipe_stream;
  ipstream error_pipe_stream;

  child c (command, std_out > std_pipe_stream, std_err > error_pipe_stream);

  const std::string std_output = pipe_to_str (std_pipe_stream);
  const std::string err_output = pipe_to_str (error_pipe_stream);

  c.wait ();

  return { c.exit_code (), std_output + err_output };
}
