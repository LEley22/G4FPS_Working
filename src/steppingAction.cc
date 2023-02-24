#include "steppingAction.hh"
#include "detectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleDefinition.hh"
#include "G4Gamma.hh"


steppingAction::steppingAction()
{}


steppingAction::~steppingAction()
{}

void steppingAction::UserSteppingAction(const G4Step* step)
{

  G4Track * track = step->GetTrack();

  if (step->GetPostStepPoint()->GetStepStatus()==fGeomBoundary){ //fGeomBoundary is first geometric volume (i.e. target), postStep is as it leaves target

    // The crossing coordinates
    G4double x = step->GetPostStepPoint()->GetPosition().getX();
    G4double y = step->GetPostStepPoint()->GetPosition().getY();
    G4double z = step->GetPostStepPoint()->GetPosition().getZ();

// G4ParticleDefinition* partID = const_cast<G4ParticleDefinition*>
//                                     (track->GetParticleDefinition());
//         if(partID!=G4Gamma::Definition()){
//             track->SetTrackStatus(fStopAndKill);
//         };
    // If particle is reflected by target, kill track
    // if(z > 0){
    //     track->SetTrackStatus(fStopAndKill);
    // };
      
};
}


