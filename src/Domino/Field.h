/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_FIELD_H
#define DOMINO_FIELD_H

namespace Domino {
    class Field {
        public:
            /**
             * @param int size[]
             */
            Field(int size[]);

            /**
             * @param int size_x
             * @param int size_y
             */
            Field(int size_x, int size_y);
    };
}

#endif
