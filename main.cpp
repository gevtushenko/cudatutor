#include <iostream>

#include "answer.h"
#include "question.h"
#include "questions.h"

int main ()
{
  questions_t::get_instance ().get_questions ().at ("vec_add")->ask_the_question ();
  auto run = load_answer<int()> ("answer.so", "run");
  std::cout << run () << "\n";
}
