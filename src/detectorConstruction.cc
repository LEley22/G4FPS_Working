#include "detectorConstruction.hh"
#include "SenDet.hh"
#include "G4VisAttributes.hh"
#include "GB04BOptrBremSplitting.hh"
#include "G4LogicalVolumeStore.hh"


detectorConstruction::detectorConstruction()//constructor
{}

detectorConstruction::~detectorConstruction() //destructor
{}

G4VPhysicalVolume * detectorConstruction::Construct()
{
    //Manager
    G4NistManager* nist = G4NistManager::Instance();
    //Materials
    G4Material * air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material * vac = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material * Tantalum = nist->FindOrBuildMaterial("G4_Ta");  //tantalum (material)
    G4Material * Aluminium = nist->FindOrBuildMaterial("G4_Al");  //aluminium (material)
    G4Material * Titanium = nist->FindOrBuildMaterial("G4_Ti");  //titanium (material)
    G4Material * Hafnium = nist->FindOrBuildMaterial("G4_Hf");  //tungsten (material
   
    //Elements
    G4Element * Cr = nist->FindOrBuildElement("Cr"); //chromium
    G4Element * Ni = nist->FindOrBuildElement("Ni");  //nickel
    G4Element * Mo = nist->FindOrBuildElement("Mo");  //molybdenum
    G4Element * Mn = nist->FindOrBuildElement("Mn");  //manganese
    G4Element * Si = nist->FindOrBuildElement("Si");  //silicon
    G4Element * Fe = nist->FindOrBuildElement("Fe");  //iron
    G4Element * C = nist->FindOrBuildElement("C");  //carbon
    G4Element * H = nist->FindOrBuildElement("H");  //hydrogen


    //Mixtures/Compounds etc.
    G4double SteelDensity = 8.0 * g/cm3;
    G4Material* Steel = new G4Material("Steel", SteelDensity, 6);
    G4double fracmass;
    Steel->AddElement(Fe, fracmass = 66.5 *perCent);
    Steel->AddElement(Cr, fracmass = 17*perCent);
    Steel->AddElement(Ni, fracmass = 12*perCent);
    Steel->AddElement(Mo, fracmass = 2.5 *perCent);
    Steel->AddElement(Mn, fracmass = 1*perCent);   
    Steel->AddElement(Si, fracmass = 1*perCent);   

    G4double OilDensity = 0.89 * g/cm3;
    G4Material* Oil = new G4Material("Oil", OilDensity, 2);
    G4int Natoms;
    Oil->AddElement(C, Natoms = 19);
    Oil->AddElement(H, Natoms = 38);
  

//WORLD CREATION//
    G4Box * worldSolid = new G4Box("worldSolid", 0.5*m, 0.5*m, 1.*m); //name and half size in m

    G4LogicalVolume * worldLogic = new G4LogicalVolume(worldSolid,   //call solid
                                                        vac,         //material to be made of
                                                        "worldLogic"); //name 

    G4VPhysicalVolume * worldPhysical = new G4PVPlacement(0,    //rotation
                                                        G4ThreeVector(0,0,0), //location
                                                        worldLogic, //logic volume 
                                                        "worldPhysical", //name
                                                        0, //mother volume (0 as it is mother)
                                                        false,
                                                        0, //copy number             
                                                        true); //check overlaps


//FILTER CREATION
//INTERNAL HV ANODE GEOMETRY (COMMENT OUT WHICH IS WANTED)
//    G4Box * SteelSolid = new G4Box("SteelSolid", 0.5*m, 0.5*m, 0.25*mm); //name and half size in m
//
//    G4LogicalVolume * SteelLogic = new G4LogicalVolume(SteelSolid,   //call solid
//                                                        Steel,         //material to be made of
//                                                        "SteelLogic"); //name
//
//    G4VPhysicalVolume * SteelPhysical = new G4PVPlacement(0,    //rotation
//                                                        G4ThreeVector(0,0,-0.5*m), //location
//                                                        SteelLogic, //logic volume
//                                                        "SteelPhysical", //name
//                                                        worldLogic, //mother volume (0 as it is mother)
//                                                        false,
//                                                        0, //copy number
//                                                        true); //check overlaps

//EXTERNAL HV ANODE GEOMETRY
    //Al Filter
    // G4Box * AlSolid = new G4Box("AlSolid", 0.5*m, 0.5*m, 0.25*mm); //name and half size in m

    // G4LogicalVolume * AlLogic = new G4LogicalVolume(AlSolid,   //call solid
    //                                                     Aluminium,         //material to be made of
    //                                                     "AlLogic"); //name 

    // G4VPhysicalVolume * AlPhysical = new G4PVPlacement(0,    //rotation
    //                                                     G4ThreeVector(0,0,-0.5*m), //location
    //                                                     AlLogic, //logic volume 
    //                                                     "AlPhysical", //name
    //                                                     worldLogic, //mother volume (0 as it is mother)
    //                                                     false,
    //                                                     0, //copy number             
    //                                                     true); //check overlaps
    
    // //Oil filter
    // G4Box * OilSolid = new G4Box("OilSolid", 0.5*m, 0.5*m, 5.*mm); //name and half size in m

    // G4LogicalVolume * OilLogic = new G4LogicalVolume(OilSolid,   //call solid
    //                                                     Oil,         //material to be made of
    //                                                     "OilLogic"); //name 

    // G4VPhysicalVolume * OilPhysical = new G4PVPlacement(0,    //rotation
    //                                                     G4ThreeVector(0,0,-0.50525*m), //location
    //                                                     OilLogic, //logic volume 
    //                                                     "OilPhysical", //name
    //                                                     worldLogic, //mother volume (0 as it is mother)
    //                                                     false,
    //                                                     0, //copy number             
    //                                                     true); //check overlaps

    
    // // //Ti filter
    // G4Box * TiSolid = new G4Box("TiSolid", 0.5*m, 0.5*m, 50.*um); //name and half size in m

    // G4LogicalVolume * TiLogic = new G4LogicalVolume(TiSolid,   //call solid
    //                                                     Titanium,         //material to be made of
    //                                                     "TiLogic"); //name 

    // G4VPhysicalVolume * TiPhysical = new G4PVPlacement(0,    //rotation
    //                                                     G4ThreeVector(0,0,-0.5103*m), //location
    //                                                     TiLogic, //logic volume 
    //                                                     "TiPhysical", //name
    //                                                     worldLogic, //mother volume (0 as it is mother)
    //                                                     false,
    //                                                     0, //copy number             
    //                                                     true); //check overlaps


//TARGET CREATION
    G4Box * TargetSolid = new G4Box("TargetSolid", 0.5*m, 0.5*m, 6 *um); //name and half size in m
    //half thickness is 6um for 90 keV, 9 um for 120 keV

    G4LogicalVolume * TargetLogic = new G4LogicalVolume(TargetSolid,   //call solid
                                                        Hafnium,         //material to be made of
                                                        "TargetLogic"); //name 

    G4VPhysicalVolume * TargetPhysical = new G4PVPlacement(0,    //rotation
                                                        G4ThreeVector(0,0,-0.8*m), //location
                                                        TargetLogic, //logic volume 
                                                        "TargetPhysical", //name
                                                        worldLogic, //mother volume (0 as it is mother)
                                                        false,
                                                        0, //copy number             
                                                        true); //check overlaps

//DETECTOR CREATION
    G4Box * detSolid = new G4Box("detSolid", 0.5*m, 0.5*m, 0.1*m); //name and half size in m


    detLogic = new G4LogicalVolume(detSolid,   //call solid
                                                        vac,         //material to be made of
                                                        "detLogic"); //name 

    G4ThreeVector DetPosition = G4ThreeVector(0.,0.,0.100006*m);

    G4VPhysicalVolume * detPhysical = new G4PVPlacement(0,    //rotation
                                                        DetPosition, //location
                                                        detLogic, //logic volume 
                                                        "detPhysical", //name
                                                        worldLogic, //mother volume
                                                        false,
                                                        0, //copy number             
                                                        true); //check overlaps

//VIS ATTRIBUTES (FOR UI)

    G4VisAttributes* visAtt1 = new G4VisAttributes(G4Colour(0.0,1.0,1.0)); //detector is cyan
    visAtt1->SetForceSolid(true);
    detLogic->SetVisAttributes(visAtt1);

    G4VisAttributes* visAtt2 = new G4VisAttributes(G4Colour(0.0,0.0,1.0)); //target is blue
    visAtt2->SetForceSolid(true);
    TargetLogic->SetVisAttributes(visAtt2);

    // G4VisAttributes* visAtt4 = new G4VisAttributes(G4Colour(0.5,0.5,0.5)); //aluminium is grey
    // visAtt4->SetForceSolid(true);
    // AlLogic->SetVisAttributes(visAtt4);

    // G4VisAttributes* visAtt5 = new G4VisAttributes(G4Colour(1.0,0.5,1.0)); //oil is pink
    // visAtt5->SetForceSolid(true);
    // OilLogic->SetVisAttributes(visAtt5);

    // G4VisAttributes* visAtt6 = new G4VisAttributes(G4Colour(0.0,0.1,0.0)); //titanium is green
    // visAtt6->SetForceSolid(true);
    // TiLogic->SetVisAttributes(visAtt6); 

//    G4VisAttributes* visAtt7 = new G4VisAttributes(G4Colour(0.0,0.5,0.5)); //steel is ??
//    visAtt7->SetForceSolid(true);
//    SteelLogic->SetVisAttributes(visAtt7);


return worldPhysical;
}

void detectorConstruction::ConstructSDandField()
{
    SenDetClass *senDet  = new SenDetClass("SensitiveDetector");
    detLogic -> SetSensitiveDetector(senDet);

    //Allow event biasing to be switched on to increase brem scatters in target interactions
    G4LogicalVolume* logicTest = G4LogicalVolumeStore::GetInstance()->GetVolume("TargetLogic");
    GB04BOptrBremSplitting* bremSplittingOperator =  new GB04BOptrBremSplitting();
    bremSplittingOperator->AttachTo(logicTest);
     G4cout << " Attaching biasing operator " << bremSplittingOperator->GetName()
         << " to logical volume " << logicTest->GetName()
         << G4endl;
    G4cout <<"E"<< G4endl;

  
}



