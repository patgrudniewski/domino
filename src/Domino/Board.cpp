/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Board.h"

#include <cstdlib>

namespace Domino {
    /**
     * @param int size_x
     * @param int size_y
     */
    Board::Board(int size_x, int size_y)
    {
        this->size[0] = size_x;
        this->size[1] = size_y;
    }

    /**
     * @return int
     */
    int Board::getWidth()
    {
        return this->size[0];
    }

    /**
     * @return int
     */
    int Board::getHeight()
    {
        return this->size[1];
    }
}
