#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

class runAction : public G4UserRunAction
{
    public:
        runAction();
        ~runAction() override = default;

        void BeginOfRunAction(const G4Run*) override;
        void   EndOfRunAction(const G4Run*) override;

//        ~runAction();
//
//        virtual void BeginOfRunAction(const G4Run*);
//        virtual void EndOfRunAction(const G4Run*);
};


#endif
