#include <iostream>

#include "question.h"
#include "questions.h"

int main ()
{
  questions_t questions;

  question_t &question = *questions.get_questions ().front ();

  question.ask_question ();
  if (!question.check_answer ())
    std::cerr << "Wrong answer" << std::endl;

}
