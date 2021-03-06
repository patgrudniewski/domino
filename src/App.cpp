/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
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
    for (vector<Arg*>::iterator arg = this->cli_args.begin(); arg != this->cli_args.end(); arg++) {
        delete *arg;
    }

    delete this->cli;
}

/**
 * @param int argc
 * @param char** argv
 * @return void
 */
void App::run(int argv, char** argc)
{
    try {
        unsigned int width, height;
        vector<unsigned int> *hashes;
        Board *board;
        SetComposer *composer;

        this->cli->parse(argv, argc);

        width = ((UnlabeledValueArg<unsigned int>*) this->cli_args[0])->getValue();
        height = ((UnlabeledValueArg<unsigned int>*) this->cli_args[1])->getValue();

        board = new Board(width, height);
        composer = new SetComposer(board);
        hashes = composer->getAllPossibleCompositionHashes();

        cout << "Number of possible domino sets with board of size " << width << " x " << height << ":" << endl;
        cout << hashes->size();

        delete board;
        delete composer;
        delete hashes;
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
    this->cli_args.push_back(new UnlabeledValueArg<int>(
            "width",
            "Domino field's size",
            true,
            2,
            "width"
            ));

    this->cli_args.push_back(new UnlabeledValueArg<int>(
            "height",
            "Domino field's size",
            true,
            2,
            "height"
            ));

    for (vector<Arg*>::iterator arg = this->cli_args.begin(); arg != this->cli_args.end(); arg++) {
        this->cli->add(*arg);
    }
}
