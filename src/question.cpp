//
// Created by evtus on 1/8/2021.
//

#include "question.h"
#include "command.h"
#include "config.h"

#include <iostream>
#include <fstream>

std::string gen_compilation_command (const char *question_path, const char *answer_path)
{
  std::string cmd = "nvcc -O3 --shared -o ";
  cmd += answer_path;
  cmd += " -I";
  cmd += get_boost_include_dir ();
  cmd += " ";
  cmd += question_path;

  return cmd;
}

bool question_t::write_question (const char *question_path) const
{
  std::ofstream question (question_path);

  if (!question.is_open ())
    return true;

  question << get_question_content () << std::endl;
  question.close ();

  return false;
}

bool question_t::ask_question () const
{
  const char *question_path = "question.cu";
  const char *answer_path = "answer.so";

  if (write_question (question_path))
    {
      std::cerr << "Error: Can't write question to disk." << std::endl;
      return true;
    }

  if (execution_result result = execute (gen_compilation_command (question_path, answer_path)))
    {
      std::cerr << "Error: " << result.get_error () << std::endl;
      return true;
    }

  return false;
}
