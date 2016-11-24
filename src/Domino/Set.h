/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_SET_H
#define DOMINO_SET_H

#include <cmath>
#include <vector>

#include "Board.h"
#include "Exception/InvalidHashException.h"

namespace Domino {
    class Set
    {
        public:
            /**
             * @param Board* board
             * @param std::vector<unsigned int>::const_iterator hash
             */
            Set(Board *board, std::vector<unsigned int>::const_iterator hash);

        private:
            /**
             * @var Board*
             */
            Board* board;
    };
}

#endif
