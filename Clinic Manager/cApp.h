#pragma once
#include "wx/wx.h"

class cApp:public wxApp
{
public:
	virtual bool OnInit();
	cApp();
	~cApp();
};
enum
{
	ID_Hello = 1
};