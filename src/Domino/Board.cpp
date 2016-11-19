/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Board.h"

namespace Domino {
    using namespace std;
    using namespace Exception;

    /**
     * @param int size_x
     * @param int size_y
     */
    Board::Board(int size_x, int size_y)
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
     * @throws BoardOverflowException
     */
    void Board::addTile(bool vertical)
    {
        pair<int, int> *coordinates;
        coordinates = this->findEmptySpace();
        if (NULL == coordinates) {
            throw new BoardOverflowException;
        }

        this->addTile(vertical, coordinates->first, coordinates->second);
    }

    /**
     * @param bool vertical
     * @param int pos_x
     * @param int pos_y
     * @return void
     */
    void Board::addTile(bool vertical, int pos_x, int pos_y)
    {
        //@TODO: add tile to the board
    }

    /**
     * @return pair<int, int>*
     */
    pair<int, int>* Board::findEmptySpace()
    {
        pair<int, int> *coordinates;

        for (int i = 0; i < this->size[0]; i++) {
            for (int j = 0; j < this->size[1]; j++) {
                if (!this->map[i][j]) {
                    coordinates = (pair<int, int>*)malloc(sizeof(pair<int, int>));
                    coordinates->first = i;
                    coordinates->second = j;

                    return coordinates;
                }
            }
        }

        return NULL;
    }
}
