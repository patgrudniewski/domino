/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_BOARDPOSITIONEXCEPTION_H
#define DOMINO_EXCEPTION_BOARDPOSITIONEXCEPTION_H

#include <stdexcept>
#include <utility>

#include "../BoardPosition.h"

namespace Domino::Exception {
    class BoardPositionException : public std::runtime_error
    {
        public:
            /**
             * @param BoardPosition* position
             * @param const char* what_arg
             */
            BoardPositionException(BoardPosition* position, const char* what_arg);

            /**
             * @return BoardPosition*
             */
            BoardPosition* getPosition();

        private:
            /**
             * @var BoardPosition*
             */
            BoardPosition* position;
    };
}

#endif
