/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_SETCOMPOSER_H
#define DOMINO_SETCOMPOSER_H

#include "Board.h"
#include "Exception/InvalidBoardSizeException.h"

namespace Domino {
    class SetComposer
    {
        public:
            /**
             * @param Board* board
             * @throws Exception::InvalidBoardSizeException
             */
            SetComposer(Board* board);

        private:
            /**
             * @var Board*
             */
            Board* board;

            /**
             * @param Board* board
             * @return bool
             */
            bool verifyBoard(Board *board);
    };
}

#endif
