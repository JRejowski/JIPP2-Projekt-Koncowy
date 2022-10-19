//
// Created by Yonasz on 22.01.2022.
//

#ifndef JIPP2_SCENA_H
#define JIPP2_SCENA_H

class Scena {
public:
    /**
     * Virtual function to update consecutive scenes
     * @return false when scene is ending, true when it's still going
     */
    virtual bool update()=0;
};


#endif //JIPP2_SCENA_H
