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
        vector<unsigned int> *pool, *possible;
        Board *board;
        Set *set;

        board = new Board(this->board);
        setCount = pow(2, board->getMaxTilesCount());

        possible = new vector<unsigned int>();

        pool = new vector<unsigned int>(setCount);
        iota(begin(*pool), end(*pool), 0);
        for (vector<unsigned int>::const_iterator hash = pool->begin(); hash != pool->end(); ++hash) {
            try {
                set = new Set(board, hash);
                possible->push_back(*hash);
                delete set;
            } catch (InvalidHashException& e) {
                InvalidTileLocationException* previous = (InvalidTileLocationException*) &e.getPrevious();
                delete previous->getLocation();
            }

            board->clean();
        }

        delete board;
        delete pool;

        return possible;
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
