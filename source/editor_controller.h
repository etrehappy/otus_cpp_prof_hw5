#pragma once
#include "editor_model.h"
#include "editor_view.h"
#include "menu_enums.h"



class EditorController
{
public:
	explicit EditorController(EditorModel&, EditorView&);
	~EditorController() = default;

	void ShowMenu();
	unsigned short GetUserMenuChoise();

	void ExecuteUserAction(unsigned short);	

private:
	void RenderView();

	EditorModel& model_;
	EditorView& view_;

	CurrentMenu menu_;	
};

