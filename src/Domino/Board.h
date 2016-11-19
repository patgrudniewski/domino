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

namespace Domino {
    class Board
    {
        public:
            /**
             * @param int size_x
             * @param int size_y
             */
            Board(int size_x, int size_y);

            ~Board();

            /**
             * @return int
             */
            int getWidth();

            /**
             * @return int
             */
            int getHeight();

            /**
             * @return int
             */
            int getSurface();

            /**
             * @return int
             */
            int getMaxTilesCount();

            /**
             * @param bool vertical
             * @return void
             * @throws Exception::BoardOverflowException
             */
            void addTile(bool vertical);

            /**
             * @param bool vertical
             * @param int pos_x
             * @param int pos_y
             * @return void
             * @throws std::invalid_argument
             * @throws Exception::BoardPositionNotEmptyException
             */
            void addTile(bool vertical, int pos_x, int pos_y);
        private:
            /**
             * @var int[]
             */
            int size[2];

            /**
             * @var int**
             */
            int** map;

            /**
             * @return std::pair<int, int>*
             */
            std::pair<int, int>* findEmptySpace();
    };
}

#endif
