#ifndef ACTIONINITIALIZATION_HH
#define ACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "primaryGeneratorAction.hh"
#include "runAction.hh"
#include "steppingAction.hh"

class actionInitialization:public G4VUserActionInitialization
{
public: 
    actionInitialization();
    ~actionInitialization();

    virtual void Build() const;
};

#endif