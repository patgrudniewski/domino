/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include <vector>

#include "App.h"

using namespace Domino;
using namespace Domino::Exception;
using namespace std;
using namespace TCLAP;

const string App::VERSION = "0.0.1";

App::App()
{
    this->cli = new CmdLine("App for checking possible domino's tile sets for given domino's field size", ' ', App::VERSION);

    this->buildCliArgs();
}

App::~App()
{
    free(this->cli_args);
}

/**
 * @param int argc
 * @param char** argv
 * @return void
 */
void App::run(int argv, char** argc)
{
    try {
        int width, height;
        SetComposer *composer;
        vector<int> *hashes;

        this->cli->parse(argv, argc);

        width = ((UnlabeledValueArg<int>*) this->cli_args[0])->getValue();
        height = ((UnlabeledValueArg<int>*) this->cli_args[1])->getValue();

        composer = new SetComposer(new Board(width, height));
        hashes = composer->getAllPossibleCompositionHashes();

        // @TODO: count hashes
        // @TODO: print number of correct hashes
    } catch (ArgException &e) {
        cerr << "Error: " << e.error() << " for argument " << e.argId() << endl;
    } catch (InvalidBoardSizeException &e) {
        cerr << "Error: " << e.what() << endl;
    }
}

/**
 * @return void
 */
void App::buildCliArgs()
{
    int arg_count = 2;

    this->cli_args = (Arg**) malloc(arg_count * sizeof(Arg*));

    this->cli_args[0] = new UnlabeledValueArg<int>(
            "width",
            "Domino field's size",
            true,
            2,
            "width"
            );

    this->cli_args[1] = new UnlabeledValueArg<int>(
            "height",
            "Domino field's size",
            true,
            2,
            "height"
            );

    for (int i = 0; i < arg_count; i++) {
        this->cli->add(this->cli_args[i]);
    }
}
