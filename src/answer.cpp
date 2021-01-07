//
// Created by evtus on 1/7/2021.
//

#include <answer.h>

namespace dll = boost::dll;

bool is_in_error_state (answer_load_state state)
{
  return state != answer_load_state::success;
}

void print_error_message (answer_load_state state)
{

}

answer_load_state check_dll (const char *library_path, const char *function_name)
{
  dll::shared_library lib (library_path, dll::load_mode::append_decorations);

  if (!lib.is_loaded ())
    return answer_load_state::failed_loading_library;

  dll::library_info info (library_path);

  if (!lib.has (function_name))
    return answer_load_state::failed_loading_function;

  return answer_load_state::success;
}