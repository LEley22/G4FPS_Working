#include "SenDet.hh"
#include "G4Gamma.hh"
#include <math.h> 

double EnergyTotaller(G4double E){
    G4double TotalE = 0;
    if (E > 0) {
        TotalE += E;
    };
    
    if (TotalE == 0){
        G4cout << "No hits recorded" << G4endl;
    }
    
    else{
        G4cout << "Total E deposited = " << TotalE << G4endl;
    };

    return TotalE;
}

SenDetClass::SenDetClass(G4String name): G4VSensitiveDetector(name)
{}

SenDetClass::~SenDetClass()
{}


G4bool SenDetClass::ProcessHits(G4Step *aStep, G4TouchableHistory * )
{
    G4Track * track = aStep->GetTrack();

    //track->SetTrackStatus(fStopAndKill); //kill photons after enter detector

    G4StepPoint *preStepPoint = aStep->GetPreStepPoint(); //enter detector

    G4ThreeVector posPhoton = preStepPoint->GetPosition(); //get photon position when it enters
    G4double edep1 = preStepPoint->GetTotalEnergy(); //get photon energy when it enters step

    G4StepPoint *postStepPoint = aStep->GetPostStepPoint(); //exits detector
    G4double edep2 = postStepPoint->GetTotalEnergy(); //get photon energy when it exits det


    G4ParticleDefinition* partID = const_cast<G4ParticleDefinition*>
                                    (track->GetParticleDefinition());
        if(partID!=G4Gamma::Definition()){ //&& ((pow(pow(posPhoton[0],2) + pow(posPhoton[1],2))0.5)<223.75 *mm)){
            return false;
  };


    G4cout << "Particle hit was " << partID << G4endl; //to print pos

    G4AnalysisManager * man = G4AnalysisManager::Instance();

    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    
    
    EnergyTotaller(edep1);
    //G4cout << "Energy Dep " << edep1 << " " << edep2 << G4endl; //to print pos

    man->FillNtupleIColumn(0, evt);                 //fill N tuple 
    man->FillNtupleDColumn(1, posPhoton[0]);
    man->FillNtupleDColumn(2, posPhoton[1]);
    man->FillNtupleDColumn(3, posPhoton[2]);
    man->FillNtupleDColumn(4, edep1);  //take INITIAL energy of photon at end (detector is air so should not affect E)
    man->AddNtupleRow();

return true;
}



