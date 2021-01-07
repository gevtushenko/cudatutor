//
// Created by evtus on 1/7/2021.
//

#ifndef CUDATUTOR_ANSWER_H
#define CUDATUTOR_ANSWER_H

#include <boost/function.hpp>
#include <boost/dll.hpp>

enum class answer_load_state
{
  failed_loading_library,
  failed_loading_function,
  success
};

bool is_in_error_state (answer_load_state state);
void print_error_message (answer_load_state state);

answer_load_state check_dll (const char *library_path, const char *function_name);

template <typename action_type>
boost::function<action_type> load_answer (const char *library_path, const char *function_name)
{
  const answer_load_state load_state = check_dll (library_path, function_name);

  if (is_in_error_state (load_state))
    {
      print_error_message (load_state);
      return {};
    }

  return boost::dll::import<action_type> (library_path, function_name);
}

#endif // CUDATUTOR_ANSWER_H
