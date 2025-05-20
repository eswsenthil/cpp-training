//
//  Prototype.h
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

#ifndef Prototype_h
#define Prototype_h

#include <string>

using namespace std;

struct Eyes {
};

struct Lips {
    void curveDownwards(){
        //
    }
};

class Face {
    
public:
    Eyes mEyes;
    Lips mLips;
    
    // clone is needed when inheritances are allowed.
    // Pointer return type is needed to prevent loss of data of derived classes when cloning from derived class to base class.
    Face* clone(){
        return new Face();
    }
};


class FaceFactory {
    
    Face *mPrototypeFace;
    string mMood;
    
public:
    
    FaceFactory(Face *inFace) :
        mPrototypeFace(inFace),
        mMood("normal")
    {
    }
    
    void setMood(string_view inMood) {
        mMood = inMood;
    }
    
    Face *getFace() {
        
        // You do not need separate class types like NormalFace, SmilingFace, AngryFace, etc,...
        // Just:
        // 1. get clone from an existing object.
        // 2. change some state values
        // 3. return the modified clone.
        
        if (mMood == "normal") {
            return mPrototypeFace->clone();
        }
        else if (mMood == "happy") {
            
            // No need for new classes through inheritance.
            Face *face = mPrototypeFace->clone();
            face->mLips.curveDownwards();
            return face;
        }
        else {
            return nullptr;
        }
    }
};

class AnimatedFace : public Face
{
    // blinks eyes
};

class ReactionManager {
    
public:
    FaceFactory mFaceFactory;

    ReactionManager() :
        mFaceFactory(new Face)
    {
    }
    
    ReactionManager(bool xyz) :
        mFaceFactory(new AnimatedFace)
    {
    }
    
};

ReactionManager getReactionManager()
{
    return ReactionManager(false);
}

void demoPrototype()
{
    ReactionManager reactionManager = getReactionManager();
    
    Face *face = reactionManager.mFaceFactory.getFace();
    
}

#endif /* Prototype_h */
