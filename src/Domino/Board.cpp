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

        this->map = (bool**)malloc(this->size[0] * sizeof(bool*));
        for (int i = 0; i < this->size[0]; i++) {
            this->map[i] = (bool*)calloc(this->size[1], sizeof(bool));
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
        BoardPosition *coordinates;
        coordinates = this->findEmptySpace();
        if (NULL == coordinates) {
            throw new BoardOverflowException;
        }

        this->addTile(vertical, coordinates);
        free(coordinates);
    }

    /**
     * @param bool vertical
     * @param BoardPosition* coordinates
     * @return void
     */
    void Board::addTile(bool vertical, BoardPosition* coordinates)
    {
        TileLocation *location;
        location = new TileLocation(coordinates, vertical);

        try {
            this->addTile(location);
        } catch (BoardPositionException &e) {
            delete location;
            // @TODO: throw exception for further use (InvalidTileLocationException)
        }
    }

    /**
     * @param TileLocation* location
     * @return void
     * @throws BoardPositionNotEmptyException
     * @throws BoardPositionOutOfBoundsException
     */
    void Board::addTile(TileLocation* location)
    {
        BoardPosition *position[2];

        position[0] = location->getFirstSegmentPosition();
        position[1] = location->getSecondSegmentPosition();
        if (!this->isPositionValid(position[0])) {
            throw BoardPositionOutOfBoundsException(position[0]);
        }
        if (!this->isPositionValid(position[1])) {
            throw BoardPositionOutOfBoundsException(position[0]);
        }

        if (!this->isPositionFree(position[0])) {
            throw BoardPositionNotEmptyException(position[0]);
        }
        if (!this->isPositionFree(position[1])) {
            throw BoardPositionNotEmptyException(position[1]);
        }
        // @TODO: allocate tile positions
        // @TODO: add tile location to top of the list
    }

#ifdef DEBUG
    /**
     * @return void
     */
    void Board::printMap()
    {
        for (unsigned int i = 0; i < this->size[0]; i++) {
            for (unsigned int j = 0; j < this->size[1]; j++) {
                cout << this->map[i][j];
            }
            cout << endl;
        }
    }
#endif

    /**
     * @return BoardPosition*
     */
    BoardPosition* Board::findEmptySpace()
    {
        BoardPosition *coordinates;

        for (unsigned int i = 0; i < this->size[0]; i++) {
            for (unsigned int j = 0; j < this->size[1]; j++) {
                if (!this->map[i][j]) {
                    coordinates = (BoardPosition*)malloc(sizeof(BoardPosition));
                    coordinates->x = i;
                    coordinates->y = j;

                    return coordinates;
                }
            }
        }

        return NULL;
    }

    /**
     * @param BoardPosition* position
     * @return bool
     */
    bool Board::isPositionFree(BoardPosition* position)
    {
        return !this->map[position->x][position->y];
    }

    /**
     * @param BoardPosition* position
     * @return bool
     */
    bool Board::isPositionValid(BoardPosition* position)
    {
        return position->x < this->size[0] && position->y < this->size[1];
    }
}
