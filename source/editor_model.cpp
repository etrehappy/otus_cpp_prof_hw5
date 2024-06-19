#include "editor_model.h"
#include <iostream>

EditorModel::EditorModel()
    :document_opened_{false}
{
}


void EditorModel::CreateNewDocument()
{
    document_opened_ = true;
}

void EditorModel::ImportFromFile()
{
    document_opened_ = true;
}

void EditorModel::ExportToFile()
{
    
}

void EditorModel::CreateShape(ShapeTypes shape)
{
    switch (shape)
    {   
    case ShapeTypes::kCircle:        
        container_shapes_.emplace_back(std::make_shared<Circle>());        
        break;

    case ShapeTypes::kLine:      
       container_shapes_.emplace_back(std::make_shared<Line>());
       break;
    
    default:
        break;
    }
}



void EditorModel::DestroyShape(size_t shape_number)
{
    auto it = container_shapes_.begin();
   
    for (size_t i = 1; i != shape_number; i++)
    {
        ++it;
    }
    
    container_shapes_.erase(it);
}

const std::list<std::shared_ptr<Shapes>>& EditorModel::GetShapes() const
{  
    return container_shapes_;
}

bool EditorModel::IsDocumentOpened() const
{
    return document_opened_;
}
