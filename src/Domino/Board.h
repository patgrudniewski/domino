/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_FIELD_H
#define DOMINO_FIELD_H

#include <cstdlib>

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
             */
            void addTile(bool vertical);
        private:
            /**
             * @var int[]
             */
            int size[2];

            /**
             * @var int**
             */
            int** map;
    };
}

#endif
