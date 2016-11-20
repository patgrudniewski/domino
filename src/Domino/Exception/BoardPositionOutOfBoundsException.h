/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_BOARDPOSITIONOUTOFBOUNDSEXCEPTION_H
#define DOMINO_EXCEPTION_BOARDPOSITIONOUTOFBOUNDSEXCEPTION_H

#include "../BoardPosition.h"
#include "BoardPositionException.h"

namespace Domino::Exception {
    class BoardPositionOutOfBoundsException : public BoardPositionException
    {
        public:
            /**
             * @param BoardPosition* position
             */
            BoardPositionOutOfBoundsException(BoardPosition* position);
    };
}

#endif
