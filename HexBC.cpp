#include "HexBC.h"

#include <vtkObjectFactory.h>
#include <vtkIdList.h>
#include <vtkCollection.h>
#include <hexPatch.h>


vtkStandardNewMacro(HexBC);

//Default constructor
HexBC::HexBC()
{
    name = std::string("DefaultPatches");
    type = std::string("patch");
    patchIds = vtkSmartPointer<vtkIdList>::New();
    allPatches = vtkSmartPointer<vtkCollection>::New();
    //delete name;
    //name = new QString("foo");
}

HexBC::~HexBC()
{

}

void HexBC::setPatchColors(double r, double g, double b)
{
    for(vtkIdType i=0; i<patchIds->GetNumberOfIds();i++)
    {
        hexPatch *p =
                hexPatch::SafeDownCast(allPatches->GetItemAsObject(patchIds->GetId(i)));
        p->setColor(r,g,b);
    }
}

void HexBC::resetPatchColors()
{
    for(vtkIdType i=0; i<patchIds->GetNumberOfIds();i++)
    {
        hexPatch *p = hexPatch::SafeDownCast(
                    allPatches->GetItemAsObject(patchIds->GetId(i)));
        p->resetColor();

    }
}

void HexBC::PrintSelf(ostream &os, vtkIndent indent)
{
    os << "This is BC! " << std::endl;
}

bool HexBC::insertPatchIfIdsExists(vtkSmartPointer<vtkIdList> ids)
{

    bool foundIt=false;
    for(vtkIdType i=0;i<allPatches->GetNumberOfItems();i++)
    {
        hexPatch * p = hexPatch::SafeDownCast(allPatches->GetItemAsObject(i));
        if(p->equals(ids))
        {
//            std::cout << "patch exists " << i <<std::endl;
            patchIds->InsertUniqueId(i);
            foundIt=true;
        }
    }

//    for(vtkIdType i=0;i<allPatches->GetNumberOfItems();i++)
//    {

//        hexPatch * p = hexPatch::SafeDownCast(allPatches->GetItemAsObject(i));
//        bool idsInP[4];
//        //return true if all ids in ids exist in patch
//        for(vtkIdType j=0;j<ids->GetNumberOfIds();j++)
//        {
//            idsInP[j]=false;
//            for(vtkIdType k=0;p->vertIds->GetNumberOfIds();k++)
//            {
//                if(p->vertIds->GetId(k) == ids->GetId(j))
//                {

//                    idsInP[j]=true;
//                }
//            }

//        }
//        if(foundIt)
//        {
//            std::cout << "patches are equal, glbpatc" << i << std::endl;
//            patchIds->InsertNextId(i);
//        }
//    }
    return foundIt;
}
