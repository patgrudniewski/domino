/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_TILE_H
#define DOMINO_TILE_H

namespace Domino {
    class Tile {
        public:
            /**
             * @param bool vertical
             */
            Tile(bool vertical);

        private:
            /**
             * @var bool
             */
            bool vertical;
    };
}

#endif
