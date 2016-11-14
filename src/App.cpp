/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "App.h"

using namespace std;
using namespace TCLAP;

const string App::VERSION = "0.0.1";

App::App()
{
    this->cli = new CmdLine("App for checking possible domino's tile sets for given domino's field size", ' ', App::VERSION);
}

/**
 * @param int argc
 * @param char** argv
 * @return void
 */
void App::run(int argv, char** argc)
{
    try {
        this->cli->parse(argv, argc);
    } catch (ArgException &e) {
        cerr << "Error: " << e.error() << " for argument " << e.argId() << endl;
    }
}
