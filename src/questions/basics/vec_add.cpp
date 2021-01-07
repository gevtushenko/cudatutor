//
// Created by evtus on 1/8/2021.
//

#include "question.h"
#include "questions.h"

class vec_add_question_t : public question_t
{
private:
  static bool is_registered;

protected:
  const char *get_question_content () const final
  {
    return R"(
#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT

extern "C" BOOST_SYMBOL_EXPORT int run ()
{
  return 42;
}
)";
  }

  bool check_the_answer_implementation () const final
  {
    return true;
  }

public:
};

bool vec_add_question_t::is_registered =
    questions_t::get_instance ().register_question ("vec_add", std::make_unique<vec_add_question_t> ());
