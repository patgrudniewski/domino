/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "TileLocation.h"

namespace Domino {
#ifdef DEBUG
    using namespace std;
#endif

    /**
     * @param BoardPosition* position
     * @param bool vertical
     */
    TileLocation::TileLocation(BoardPosition* position, bool vertical)
    {
        BoardPosition *pos2;

        pos2 = (BoardPosition*)malloc(sizeof(BoardPosition));
        if (vertical) {
            pos2->x = position->x;
            pos2->y = position->y + 1;
        } else {
            pos2->x = position->x + 1;
            pos2->y = position->y;
        }

        *this = TileLocation(position, pos2);
        free(pos2);
    }

    /**
     * @param BoardPosition* pos1
     * @param BoardPosition* pos2
     */
    TileLocation::TileLocation(BoardPosition* pos1, BoardPosition* pos2)
    {
        this->position[0].x = pos1->x;
        this->position[0].y = pos1->y;
        this->position[1].x = pos2->x;
        this->position[1].y = pos2->y;
    }

    /**
     * @return BoardPosition*
     */
    BoardPosition* TileLocation::getFirstSegmentPosition()
    {
        return &this->position[0];
    }

    /**
     * @return BoardPosition*
     */
    BoardPosition* TileLocation::getSecondSegmentPosition()
    {
        return &this->position[1];
    }

#ifdef DEBUG
    /**
     * @return void
     */
    void TileLocation::printCoordinates()
    {
        cout << "x1=" << this->position[0].x << "  ";
        cout << "y1=" << this->position[0].y << endl;
        cout << "x2=" << this->position[1].x << "  ";
        cout << "y2=" << this->position[1].y << endl;
    }
#endif
}
