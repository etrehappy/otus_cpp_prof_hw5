#include "editor_view.h"
#include <iostream>

EditorView::EditorView()
{
}

EditorView::~EditorView()
{
}

void EditorView::ShowMenu(const CurrentMenu menu)
{
    switch (menu)
    {
    case CurrentMenu::kMain:
        ShowMainMenu();
        break;

    case CurrentMenu::kShape:
        ShowShapeMenu();
        break;

    case CurrentMenu::kShapeTypes:
        ShowShapeTypes();
        break;

    default:
        break;
    }

    
}

void EditorView::ShowMainMenu()
{
    std::cout << "\n_____________________________\n";
    std::cout << "*** \t Main Menu \t ***" << "\n\n";

    std::cout << "0. Exit without saving" << "\n";
    std::cout << "1. Create New Document" << "\n";
    std::cout << "2. Import From File" << "\n";
    std::cout << "3. Export To File" << "\n";
}

void EditorView::ShowShapeMenu()
{
    std::cout << "\n_____________________________";
    std::cout << "\n*** \t Shape Menu \t ***" << "\n\n";

    std::cout << "1. Create Shape" << "\n";
    std::cout << "2. Destroy Shape" << "\n";
}

void EditorView::ShowShapeTypes()
{
    std::cout << "\n_____________________________";
    std::cout << "\n*** \t Shape Types \t ***" << "\n\n";

    std::cout << "1. Circle" << "\n";
    std::cout << "2. Line" << "\n";
}


void EditorView::RenderCanvas(/*ref_on_a_picture_file*/)
{
    std::cout << "The canvas is displayed on the screen." << "\n";
}

void EditorView::Render(const std::list<std::shared_ptr<Shapes>>& shapes)
{
    for (const auto& shape : shapes)
    {
        shape->Draw();
    }
}


