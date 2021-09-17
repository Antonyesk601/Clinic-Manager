#pragma once
#include "wx/wx.h"

class cApp:public wxApp
{
public:
	virtual bool OnInit();
	cApp();
	~cApp();
};
enum WINDOWIDS
{
	ID_Hello = 1
};