#include "runAction.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"


runAction::runAction()
{

    auto man = G4AnalysisManager::Instance();
    man->CreateNtuple("Hits", "Hits"); //create Ntuple rows
    man->CreateNtupleIColumn("fEvent"); //create integer event no column
    man->CreateNtupleDColumn("fX"); 
    man->CreateNtupleDColumn("fY"); 
    man->CreateNtupleDColumn("fZ");  //double columns with x,y,z coord of hit
    man->CreateNtupleDColumn("eDep");
    man->FinishNtuple(0); //finish this first Ntuple
}

//runAction::~runAction()
//{}

void runAction::BeginOfRunAction(const G4Run* run)
{
    auto man = G4AnalysisManager::Instance();

    G4int runID= run->GetRunID();

    std::stringstream strRunID;
    strRunID<<runID;
    
    G4String fileName = "PicOutput"+strRunID.str()+".csv";

    man->OpenFile(fileName);
    
}

void runAction::EndOfRunAction(const G4Run *run)
{
    auto man = G4AnalysisManager::Instance();

    man->Write();
    man->CloseFile();
    
}
