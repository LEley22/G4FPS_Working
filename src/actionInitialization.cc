#include "actionInitialization.hh"

actionInitialization::actionInitialization()
{}

actionInitialization::~actionInitialization()
{}

void actionInitialization::Build() const
{
    primaryGeneratorAction * generator = new primaryGeneratorAction();
    SetUserAction(generator);

    runAction * runaction = new runAction();
    SetUserAction(runaction);

    steppingAction *steppingaction = new steppingAction();
    SetUserAction(steppingaction);
    
}