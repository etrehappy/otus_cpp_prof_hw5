#pragma once
enum class CurrentMenu : unsigned short
{
	kExitWithoutSaving = 0,

	kMain,
	kShape,
	kShapeTypes,

	kNone
};

enum class MainMenu : unsigned short
{
	kExit = 0,

	kCreateNewDocument,
	kImportFromFile,
	kExportToFile,

	kNone
};

enum class ShapeMenu : unsigned short
{
	kExit = 0,

	kCreateShape,
	kDestroyShape,

	kNone
};

enum class ShapeTypes : unsigned short
{
	kNone = 0,

	kCircle,
	kLine
	
};

