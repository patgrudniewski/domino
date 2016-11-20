/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_TILELOCATION_H
#define DOMINO_TILELOCATION_H

#include "BoardPosition.h"

#include <cstdlib>

#ifdef DEBUG
#include <iostream>
#endif

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

#ifdef DEBUG
            /**
             * @return void
             */
            void printCoordinates();
#endif

        private:
            /**
             * @var BoardPosition[]
             */
            BoardPosition position[2];
    };
}

#endif
