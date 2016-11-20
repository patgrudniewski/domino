/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "BoardPositionException.h"

namespace Domino::Exception {
    using namespace std;

    /**
     * @param BoardPosition* position
     * @param const char* what_arg
     */
    BoardPositionException::BoardPositionException(BoardPosition* position, const char* what_arg)
        : runtime_error(what_arg), position(position) {  }

    /**
     * @return BoardPosition*
     */
    BoardPosition* BoardPositionException::getPosition()
    {
        return this->position;
    }
}
