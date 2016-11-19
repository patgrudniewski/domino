/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_SET_H
#define DOMINO_SET_H

#include <cmath>
#include <vector>

#include "Board.h"

namespace Domino {
    class Set {
        public:
            /**
             * @param Board* board
             * @param std::vector<int>::const_iterator hash
             */
            Set(Board *board, std::vector<int>::const_iterator hash);
    };
}

#endif
