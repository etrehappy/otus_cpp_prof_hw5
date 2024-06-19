#include "editor_model.h"
#include "editor_view.h"
#include "editor_controller.h"

int main()
{
    EditorModel model{};
    EditorView view{};
    EditorController controller{model, view};

    unsigned short user_menu_choise{};
    do
    {
        controller.ShowMenu();
        user_menu_choise = controller.GetUserMenuChoise();
        controller.ExecuteUserAction(user_menu_choise);
    } 
    while (user_menu_choise != 
        static_cast<unsigned short>(CurrentMenu::kExitWithoutSaving));

    return 0;
}
