//
// Created by evtus on 1/7/2021.
//

#include <boost/dll.hpp>

#include <iostream>

namespace dll = boost::dll;

void load_answer ()
{
  std::cout << "Loading plugin: " << "answer.so" << '\n';
  dll::shared_library lib ("answer.so", dll::load_mode::append_decorations);

  if (lib.is_loaded ())
    std::cout << "loaded\n";

  dll::library_info info ("answer.so");
  for (auto &symbol: info.symbols ())
    std::cout << "s: " << symbol << std::endl;

  if (!lib.has ("run"))
    {
      std::cout << "-\n";
      // no such symbol
      return;
    }
  std::cout << "+\n";

  // library has symbol, importing...
  /*
  typedef boost::shared_ptr<my_plugin_api> (pluginapi_create_t) ();
  boost::function<pluginapi_create_t> creator =
      dll::import_alias<pluginapi_create_t> (boost::move (lib), "create_plugin");

  std::cout << "Matching plugin name: " << creator ()->name () << std::endl;
   */
}