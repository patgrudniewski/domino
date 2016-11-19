/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Board.h"

namespace Domino {
    using namespace std;
    using namespace Exception;

    /**
     * @param unsigned int size_x
     * @param unsigned int size_y
     */
    Board::Board(unsigned int size_x, unsigned int size_y)
    {
        this->size[0] = size_x;
        this->size[1] = size_y;

        this->map = (int**)malloc(this->size[0] * sizeof(int*));
        for (int i = 0; i < this->size[0]; i++) {
            this->map[i] = (int*)calloc(this->size[1], sizeof(int));
        }
    }

    Board::~Board()
    {
        for (int i = 0; i < this->size[0]; i++) {
            free(this->map[i]);
        }
        free(this->map);
    }

    /**
     * @return unsigned int
     */
    unsigned int Board::getWidth()
    {
        return this->size[0];
    }

    /**
     * @return unsigned int
     */
    unsigned int Board::getHeight()
    {
        return this->size[1];
    }

    /**
     * @return unsigned int
     */
    unsigned int Board::getSurface()
    {
        return this->size[0] * this->size[1];
    }

    /**
     * @return unsigned int
     */
    unsigned int Board::getMaxTilesCount()
    {
        return this->getSurface() / 2;
    }

    /**
     * @param bool vertical
     * @return void
     * @throws BoardOverflowException
     */
    void Board::addTile(bool vertical)
    {
        pair<unsigned int, unsigned int> *coordinates;
        coordinates = this->findEmptySpace();
        if (NULL == coordinates) {
            throw new BoardOverflowException;
        }

        this->addTile(vertical, coordinates->first, coordinates->second);

        free(coordinates);
    }

    /**
     * @param bool vertical
     * @param unsigned int pos_x
     * @param unsigned int pos_y
     * @return void
     * @throws invalid_argument
     * @throws BoardPositionNotEmptyException
     */
    void Board::addTile(bool vertical, unsigned int pos_x, unsigned int pos_y)
    {
        if (pos_x > this->size[0] || pos_y > this->size[1]) {
            throw new invalid_argument("Invalid board position");
        }
        if (this->map[pos_x][pos_y]) {
            throw new BoardPositionNotEmptyException(pos_x, pos_y);
        }
        //@TODO: add tile to the board
    }

    /**
     * @return pair<unsigned int, unsigned int>*
     */
    pair<unsigned int, unsigned int>* Board::findEmptySpace()
    {
        pair<unsigned int, unsigned int> *coordinates;

        for (unsigned int i = 0; i < this->size[0]; i++) {
            for (unsigned int j = 0; j < this->size[1]; j++) {
                if (!this->map[i][j]) {
                    coordinates = (pair<unsigned int, unsigned int>*)malloc(sizeof(pair<unsigned int, unsigned int>));
                    coordinates->first = i;
                    coordinates->second = j;

                    return coordinates;
                }
            }
        }

        return NULL;
    }
}
