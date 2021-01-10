//
// Created by evtus on 1/10/2021.
//

#include "questions/basics/vec_add.h"

const char *vec_add_question_t::get_question_content () const
{
  return R"(
#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT

extern "C" BOOST_SYMBOL_EXPORT int run ()
{
return 42;
}
)";
}

bool vec_add_question_t::check_answer_implementation () const
{
  return true;
}
