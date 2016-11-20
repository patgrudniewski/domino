/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_TILELOCATION_H
#define DOMINO_TILELOCATION_H

#include "BoardPosition.h"

#include <cstdlib>
#include <iostream>

namespace Domino {
    class TileLocation
    {
        public:
            /**
             * @param BoardPosition* position
             * @param bool vertical
             */
            TileLocation(BoardPosition* position, bool vertical);

            /**
             * @param BoardPosition* pos1
             * @param BoardPosition* pos2
             */
            TileLocation(BoardPosition* pos1, BoardPosition* pos2);

        private:
            BoardPosition position[2];
    };
}

#endif
