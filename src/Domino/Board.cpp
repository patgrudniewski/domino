/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Board.h"

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

    /**
     * @return int
     */
    int Board::getSurface()
    {
        return this->size[0] * this->size[1];
    }

    /**
     * @return int
     */
    int Board::getMaxTilesCount()
    {
        return this->getSurface() / 2;
    }

    /**
     * @param bool vertical
     * @return void
     */
    void Board::addTile(bool vertical)
    {
        //@TODO: add tile to the board
    }
}
