/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_SETCOMPOSER_H
#define DOMINO_SETCOMPOSER_H

#include <cmath>
#include <cstdlib>
#include <iterator>
#include <numeric>
#include <vector>

#include "Board.h"
#include "Exception/InvalidBoardSizeException.h"
#include "Set.h"

namespace Domino {
    class SetComposer
    {
        public:
            /**
             * @param Board* board
             * @throws Exception::InvalidBoardSizeException
             */
            SetComposer(Board* board);

            /**
             * @return std::vector<unsigned int>*
             */
            std::vector<unsigned int>* getAllPossibleCompositionHashes();

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
