/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_FIELD_H
#define DOMINO_FIELD_H

#include <cstdlib>
#include <stdexcept>
#include <utility>

#include "Exception/BoardOverflowException.h"
#include "Exception/BoardPositionNotEmptyException.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Domino {
    class Board
    {
        public:
            struct Position {
                /**
                 * @var unsigned int
                 */
                unsigned int x;

                /**
                 * @var unsigned int
                 */
                unsigned int y;
            };

            /**
             * @param unsigned int size_x
             * @param unsigned int size_y
             */
            Board(unsigned int size_x, unsigned int size_y);

            ~Board();

            /**
             * @return unsigned int
             */
            unsigned int getWidth();

            /**
             * @return unsigned int
             */
            unsigned int getHeight();

            /**
             * @return unsigned int
             */
            unsigned int getSurface();

            /**
             * @return unsigned int
             */
            unsigned int getMaxTilesCount();

            /**
             * @param bool vertical
             * @return void
             * @throws Exception::BoardOverflowException
             */
            void addTile(bool vertical);

            /**
             * @param bool vertical
             * @param Position* coordinates
             * @return void
             * @throws std::invalid_argument
             * @throws Exception::BoardPositionNotEmptyException
             */
            void addTile(bool vertical, Position* coordinates);

#ifdef DEBUG
            /**
             * @return void
             */
            void printMap();
#endif
        private:
            /**
             * @var unsigned int[]
             */
            unsigned size[2];

            /**
             * @var bool**
             */
            bool** map;

            /**
             * @var int
             */
            int tile_count = 0;

            /**
             * @return Position*
             */
            Position* findEmptySpace();
    };
}

#endif
