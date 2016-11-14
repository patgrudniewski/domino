/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>

#include "tclap/Arg.h"
#include "tclap/CmdLine.h"
#include "tclap/UnlabeledValueArg.h"

class App final
{
    public:
        static const std::string VERSION;

        App();

        ~App();

        /**
         * @param int argc
         * @param char** argv
         * @return void
         */
        void run(int argv, char** argc);

    private:
        /**
         * @var TCLAP::CmdLine*
         */
        TCLAP::CmdLine* cli;

        /**
         * @var TCLAP::Arg**
         */
        TCLAP::Arg** cli_args;

        /**
         * @return void
         */
        void buildCliArgs();
};

#endif
