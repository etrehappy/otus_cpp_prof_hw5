#include "editor_controller.h"
#include <iostream>
#include <limits>

EditorController::EditorController(EditorModel& model, EditorView& view)
    :model_{model}, view_{view}, menu_{CurrentMenu::kNone}
{
}


void EditorController::ShowMenu()
{
    if (menu_ == CurrentMenu::kNone)
    {
        menu_ = CurrentMenu::kMain;
    }

    view_.ShowMenu(menu_);    
}


unsigned short EditorController::GetUserMenuChoise()
{
    unsigned short a{};
    std::cout << "\nEnter: ";
    std::cin >> a;
    while (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<unsigned short>::max(), '\n');
        std::cout << "Input error. Try again: ";
        std::cin >> a;
    }
    
    return a;
}

void EditorController::ExecuteUserAction(unsigned short user_menu_choise)
{  
    if (menu_ == CurrentMenu::kMain)
    {
        switch (static_cast<MainMenu>(user_menu_choise))
        {
        case MainMenu::kExit:
            break;

        case MainMenu::kCreateNewDocument:
            model_.CreateNewDocument();
            menu_ = CurrentMenu::kShape;
            break;

        case MainMenu::kImportFromFile:
            model_.ImportFromFile();
            menu_ = CurrentMenu::kShape;
            break;

        case MainMenu::kExportToFile:
            model_.ExportToFile();
            break;
      
        default:
            break;
        }
    }

    else if (menu_ == CurrentMenu::kShape)
    {
        switch (static_cast<ShapeMenu>(user_menu_choise))
        {
        case ShapeMenu::kCreateShape:            
            menu_ = CurrentMenu::kShapeTypes;
            break;

        case ShapeMenu::kDestroyShape:
            if (model_.GetShapes().empty()) {break;}
            model_.DestroyShape(GetUserMenuChoise()); 
            break;

        default:
            break;
        }
    }

    else if (menu_ == CurrentMenu::kShapeTypes)
    {
        switch (static_cast<ShapeTypes>(user_menu_choise))
        {
        case ShapeTypes::kLine:                        
            
            model_.CreateShape(ShapeTypes::kLine);
            menu_ = CurrentMenu::kShape;
            break;

        case ShapeTypes::kCircle:
            model_.CreateShape(ShapeTypes::kCircle);
            menu_ = CurrentMenu::kShape;
            break;

        default:
            break;
        }
    }

    RenderView();
}

void EditorController::RenderView()
{
    if (!model_.IsDocumentOpened()) { return; }
    
    view_.RenderCanvas(/*ref_on_a_picture_file*/);

    if (const auto& container_shapes = model_.GetShapes();
        !container_shapes.empty())
    {
        view_.Render(container_shapes);
    }
    
}

