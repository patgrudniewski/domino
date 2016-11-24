/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "InvalidHashException.h"

using Exception::ChainException;

namespace Domino::Exception {
    using namespace std;

    /**
     * @param vector<unsigned int>::const_iterator hash
     * @param exception& previous
     */
    InvalidHashException::InvalidHashException(vector<unsigned int>::const_iterator hash, exception& previous)
        :runtime_error("Invalid tile location"), ChainException(previous), hash(hash) {  }

    /**
     * @return vector<unsigned int>::const_iterator
     */
    vector<unsigned int>::const_iterator InvalidHashException::getHash()
    {
        return this->hash;
    }
}
