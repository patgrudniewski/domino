/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Set.h"

namespace Domino {
    using namespace Exception;
    using namespace std;

    /**
     * @param Board* board
     * @param vector<unsigned int>::const_iterator hash
     */
    Set::Set(Board *board, vector<unsigned int>::const_iterator hash)
        :board(board)
    {
        unsigned int tiles_n = this->board->getMaxTilesCount(),
            mask = 1,
            mask_limit = pow(2, tiles_n);

        try {
            while (mask < mask_limit) {
                this->board->addTile((bool)(*hash & mask));
                mask <<= 1;
            }
        } catch (InvalidTileLocationException& e) {
            throw InvalidHashException(hash, e);
        }
    }
}
