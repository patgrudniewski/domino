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
             * @param unsigned int pos_x
             * @param unsigned int pos_y
             * @return void
             * @throws std::invalid_argument
             * @throws Exception::BoardPositionNotEmptyException
             */
            void addTile(bool vertical, unsigned int pos_x, unsigned int pos_y);
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
             * @return std::pair<unsigned int, unsigned int>*
             */
            std::pair<unsigned int, unsigned int>* findEmptySpace();
    };
}

#endif
