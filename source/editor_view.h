#pragma once
#include "menu_enums.h"
#include "shape.h"
#include <memory>
#include <list>

class EditorView
{
public:
	EditorView();
	~EditorView();

	void ShowMenu(const CurrentMenu);

	void RenderCanvas(/*ref_on_a_picture_file*/);
	void Render(const std::list<std::shared_ptr<Shapes>>& shapes);

private:

	void ShowMainMenu();
	void ShowShapeMenu();
	void ShowShapeTypes();
	
};