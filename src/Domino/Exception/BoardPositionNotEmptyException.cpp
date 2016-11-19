/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "BoardPositionNotEmptyException.h"

namespace Domino::Exception {
    using namespace std;

    /**
     * @param int x
     * @param int y
     */
    BoardPositionNotEmptyException::BoardPositionNotEmptyException(int x, int y)
        :runtime_error("Board position is not empty")
    {
        this->position.first = x;
        this->position.second = y;
    }

    /**
     * @return int
     */
    int BoardPositionNotEmptyException::getPositionX()
    {
        return this->position.first;
    }

    /**
     * @return int
     */
    int BoardPositionNotEmptyException::getPositionY()
    {
        return this->position.second;
    }
}
