/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_FIELD_H
#define DOMINO_FIELD_H

#include <cstdlib>
#include <stdexcept>
#include <utility>
#include <vector>

#include "BoardPosition.h"
#include "Exception/BoardOverflowException.h"
#include "Exception/BoardPositionException.h"
#include "Exception/BoardPositionNotEmptyException.h"
#include "Exception/BoardPositionOutOfBoundsException.h"
#include "Exception/InvalidTileLocationException.h"
#include "TileLocation.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Domino {
    class Board
    {
        public:
            /**
             * @param unsigned int size_x
             * @param unsigned int size_y
             */
            Board(unsigned int size_x, unsigned int size_y);

            /**
             * @apram Board* board
             */
            Board(Board* board);

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
             * @param BoardPosition* coordinates
             * @return void
             */
            void addTile(bool vertical, BoardPosition* coordinates);

            /**
             * @param TileLocation* location
             * @return void
             * @throws Exception::InvalidTileLocationException
             */
            void addTile(TileLocation* location);

            /**
             * @return void
             */
            void clean();

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
             * @var std::vector<TileLocation*>
             */
            std::vector<TileLocation*> tiles;

            /**
             * @return BoardPosition*
             */
            BoardPosition* findEmptySpace();

            /**
             * @param BoardPosition* position
             * @return bool
             */
            bool isPositionFree(BoardPosition* position);

            /**
             * @param BoardPosition* position
             * @return bool
             */
            bool isPositionValid(BoardPosition* position);

            /**
             * @param TileLocation* location
             * @return void
             */
            void mapLocation(TileLocation* location);

            /**
             * @param TileLocation* location
             * @return void
             */
            void unmapLocation(TileLocation* location);

            /**
             * @param BoardPosition* position
             * @return void
             * @throws Exception::BoardPositionNotEmptyException
             * @throws Exception::BoardPositionOutOfBoundsException
             */
            void mapPosition(BoardPosition* position);

            /**
             * @param BoardPosition* position
             * @return void
             */
            void unmapPosition(BoardPosition* position);

            /**
             * @return void
             */
            void allocMap();
    };
}

#endif
