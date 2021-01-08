//

#include "questions/vec_add.h"

#include "answer.h"

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

bool vec_add_question_t::check_answer () const
{
  auto run = load_answer<int()> ("answer.so", "run");
  return run () == 42;
}
