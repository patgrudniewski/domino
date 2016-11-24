/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "ChainException.h"

namespace Exception {
    using namespace std;

    /**
     * @param exception& previous
     */
    ChainException::ChainException(exception& previous)
        :previous(previous) {  }

    /**
     * @return exception& previous
     */
    exception& ChainException::getPrevious()
    {
        return this->previous;
    }
}
