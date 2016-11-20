/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_BOARDPOSITIONNOTEMPTYEXCEPTION_H
#define DOMINO_EXCEPTION_BOARDPOSITIONNOTEMPTYEXCEPTION_H

#include "../BoardPosition.h"
#include "BoardPositionException.h"

namespace Domino::Exception {
    class BoardPositionNotEmptyException : public BoardPositionException
    {
        public:
            /**
             * @param BoardPosition* position
             */
            BoardPositionNotEmptyException(BoardPosition* position);
    };
}

#endif
