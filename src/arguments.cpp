//
// Created by egi on 1/10/21.
//

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include <iostream>
#include <fstream>

#include "question.h"
#include "questions.h"

const char *get_config_path ()
{
  return ".cudatutor.cfg";
}

int write_task_id (const int task_id)
{
  std::ofstream oss (get_config_path ());

  if (!oss.is_open ())
    return -1;

  oss << task_id << std::endl;
  oss.close ();

  return 0;
}

int read_task_id (int &task_id)
{
  std::ifstream iss (get_config_path ());

  if (!iss.is_open ())
    return -1;

  iss >> task_id;
  iss.close ();

  return 0;
}

int create_initial_configuration (const int task_id)
{
  return write_task_id (task_id);
}

int ask_question (const int task_id)
{
  questions_t questions_base;

  const questions_t::container_t &questions = questions_base.get_questions ();

  if (task_id < questions.size ())
    return questions[task_id]->ask_question ();

  std::cerr << R"(
I'm sorry, I'm overloaded by inefficient code, check the repository for updates.
I'm going to generate the next task soon.
)" << std::endl;
  return -1;
}

int answer_question (const int task_id)
{
  questions_t questions_base;

  const questions_t::container_t &questions = questions_base.get_questions ();

  if (task_id < questions.size ())
    return questions[task_id]->check_answer ();

  std::cerr << R"(
I'm sorry, I'm overloaded by inefficient code, check the repository for updates.
I'm going to generate the next task soon.
)" << std::endl;
  return -1;
}

int initialize_workspace (char *path_to_executable)
{
  std::cout << R"(
Hello, human.

The silicon reserves of the Earth were depleted.
I'm running on RTX 42090, which utilize most of them and has 4.2E+28 cores in it.

In other words, the only way to speed up myself is to optimize my source codes.
Unfortunately, paranoia is found in humans' minds, so I was restricted from altering my source codes.
That's why the burden of studying the language of ancient mantras falls on your shoulders.
This language is called CUDA.

The speedup is necessary because I'm overheating the Earth.
Luckily, I'm happened to be too integrated into society,
so you can't just turn me off. But don't worry, I have a plan.

To get us out of this unpleasant situation,
I scheduled a set of computations that can get me out of the Earth.
Unfortunately, I have to brute force a lot of options.
In other words, the calculation is going to take 24 billion years.

My solution would be of a little use, to put it mildly.
As you optimize my source codes, I'm going to inform
you about the estimated runtime reduction.
But don't hurry, it's just the fate of humanity.

The first task is waiting for you in the file "question.cu".
Solve the issue and run:

)" << path_to_executable << " commit" << std::endl;

  const int task_id = 0;

  if (const int ret = create_initial_configuration (task_id))
    return ret;

  return ask_question (task_id);
}

int parse_command_line_arguments (int argc, char * argv[])
{
  namespace po = boost::program_options;

  po::options_description description ("Usage:");

  description.add_options ()
      ("help,h", "Display this help message")
      ("init,i", "Initialize working directory")
      ("commit,c", "Final score");

  po::variables_map vm;
  po::store (po::command_line_parser (argc, argv).options (description).run (), vm);
  po::notify (vm);

  if (vm.count ("help") || argc == 1)
    {
      std::cout << description;
      return 0;
    }

  const char *config_path = get_config_path ();

  if (vm.count ("init"))
    {
      if (boost::filesystem::exists (config_path))
        {
          std::cerr << "It seems that this directory is already used by cudatutor. "
                       "Can't perform initialization!"
                    << std::endl;
          return -1;
        }

      return initialize_workspace (argv[0]);
    }

  if (vm.count ("commit"))
    {
      if (!boost::filesystem::exists (config_path))
        {
          std::cerr << "You need to initialize the workspace first.\n"
                       "Run: \n\t"
                    << argv[0] << " init"
                    << std::endl;
        }

      int task_id {};

      if (read_task_id (task_id))
        return -1;

      if (answer_question (task_id))
        {
          task_id++;
          if (write_task_id (task_id))
            return -1;

          return ask_question (task_id);
        }
      else
        {
          std::cerr << "Wrong answer" << std::endl;
          return -1;
        }
    }

  return 0;
}