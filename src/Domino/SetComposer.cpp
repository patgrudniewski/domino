/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "SetComposer.h"

namespace Domino {
    using namespace Exception;
    using namespace std;

    /**
     * @param Board* board
     * @throws InvalidBoardSizeException
     */
    SetComposer::SetComposer(Board* board)
    {
        if (!this->verifyBoard(board)) {
            throw new InvalidBoardSizeException;
        }

        this->board = board;
    }

    /**
     * @return vector<int>*
     */
    vector<unsigned int>* SetComposer::getAllPossibleCompositionHashes()
    {
        unsigned int setCount;
        vector<unsigned int> *hashes;

        setCount = pow(2, this->board->getMaxTilesCount());

        hashes = new vector<unsigned int>(setCount);
        iota(begin(*hashes), end(*hashes), 0);
        for (vector<unsigned int>::const_iterator hash = hashes->begin(); hash != hashes->end(); ++hash) {
            Set *set;
            set = new Set(this->board, hash);
            // @TODO: filter off impossible hashes

            delete set;
        }

        return hashes;
    }

    /**
     * @param Board* board
     * @return bool
     */
    bool SetComposer::verifyBoard(Board* board)
    {
        return 0 == board->getWidth() * board->getHeight() % 2;
    }
}
