#include <iostream>

#include "answer.h"
#include "question.h"
#include "questions.h"

int main ()
{
  questions_t ().get_questions ().front ()->ask_the_question ();
  auto run = load_answer<int()> ("answer.so", "run");
  std::cout << run () << "\n";
}
