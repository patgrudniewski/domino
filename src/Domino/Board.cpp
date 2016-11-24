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

        this->allocMap();
    }

    /**
     * @param Board* board
     */
    Board::Board(Board* board)
    {
        this->size[0] = board->getWidth();
        this->size[1] = board->getHeight();

        this->allocMap();
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

        this->addTile(location);
    }

    /**
     * @param TileLocation* location
     * @return void
     */
    void Board::addTile(TileLocation* location)
    {
        try {
            this->mapLocation(location);
        } catch (BoardPositionException &e) {
            this->unmapLocation(location);
            delete location;
            // @TODO: throw exception for further use (InvalidTileLocationException)
        }
        // @TODO: add tile location to top of the list
    }

    /**
     * @return void
     */
    void Board::clean()
    {
        for (int i = 0; i < this->size[0]; i++) {
            for (int j = 0; j < this->size[1]; j++) {
                this->map[i][j] = 0;
            }
        }
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

    /**
     * @param TileLocation* location
     * @return void
     */
    void Board::mapLocation(TileLocation* location)
    {
        this->mapPosition(location->getFirstSegmentPosition());
        this->mapPosition(location->getSecondSegmentPosition());
    }

    /**
     * @param TileLocation* location
     * @return void
     */
    void Board::unmapLocation(TileLocation* location)
    {
        this->unmapPosition(location->getFirstSegmentPosition());
        this->unmapPosition(location->getSecondSegmentPosition());
    }

    /**
     * @param BoardPosition* position
     * @return void
     * @throws BoardPositionNotEmptyException
     * @throws BoardPositionOutOfBoundsException
     */
    void Board::mapPosition(BoardPosition* position)
    {
        if (!this->isPositionValid(position)) {
            throw BoardPositionOutOfBoundsException(position);
        }
        if (!this->isPositionFree(position)) {
            throw BoardPositionNotEmptyException(position);
        }

        this->map[position->x][position->y] = true;
    }

    /**
     * @param BoardPosition* position
     * @return void
     */
    void Board::unmapPosition(BoardPosition* position)
    {
        if (this->isPositionValid(position)) {
            this->map[position->x][position->y] = false;
        }
    }

    /**
     * @return void
     */
    void Board::allocMap()
    {
        this->map = (bool**)malloc(this->size[0] * sizeof(bool*));
        for (int i = 0; i < this->size[0]; i++) {
            this->map[i] = (bool*)calloc(this->size[1], sizeof(bool));
        }
    }
}
