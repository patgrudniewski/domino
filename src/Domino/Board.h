/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_FIELD_H
#define DOMINO_FIELD_H

namespace Domino {
    class Board {
        public:
            /**
             * @param int size_x
             * @param int size_y
             */
            Board(int size_x, int size_y);

            /**
             * @return int
             */
            int getWidth();

            /**
             * @return int
             */
            int getHeight();
        private:
            /**
             * @var int[]
             */
            int size[2];
    };
}

#endif
