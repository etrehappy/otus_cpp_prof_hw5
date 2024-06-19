#pragma once
#include "menu_enums.h"
#include "circle.h"
#include "line.h"
#include <memory>
#include <list>

class EditorModel
{
public:
	EditorModel();
	~EditorModel() = default;

	void CreateNewDocument();
	void ImportFromFile();
	void ExportToFile();

	void CreateShape(ShapeTypes);
	void DestroyShape(size_t shape_number);
	const std::list<std::shared_ptr<Shapes>>& GetShapes() const;
	bool IsDocumentOpened() const;

private:	
	std::list<std::shared_ptr<Shapes> > container_shapes_;
	bool document_opened_;
};

