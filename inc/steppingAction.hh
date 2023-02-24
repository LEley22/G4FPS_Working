#ifndef STEPACTION_HH
#define STEPACTION_HH

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4LogicalVolume;
class steppingAction : public G4UserSteppingAction

{
  public:
    steppingAction();
    virtual ~steppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);
};

#endif
