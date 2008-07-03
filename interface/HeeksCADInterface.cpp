// HeeksCADInterface.cpp

// included only in the executable

#include "stdafx.h"
#include "HeeksCADInterface.h"
#include "HeeksFrame.h"
#include "PropertiesCanvas.h"
#include "MarkedList.h"
#include "HArc.h"
#include "ObjPropsCanvas.h"

double CHeeksCADInterface::GetTolerance()
{
	return wxGetApp().m_geom_tol;
}

void CHeeksCADInterface::RefreshProperties()
{
	wxGetApp().m_frame->m_properties->RefreshByRemovingAndAddingAll();
}

void CHeeksCADInterface::Repaint()
{
	wxGetApp().Repaint();
}

wxFrame* CHeeksCADInterface::GetMainFrame()
{
	return wxGetApp().m_frame;
}

wxAuiManager* CHeeksCADInterface::GetAuiManager()
{
	return wxGetApp().m_frame->m_aui_manager;
}

void CHeeksCADInterface::AddToolBarButton(wxToolBar* toolbar, const wxString& title, wxBitmap& bitmap, const wxString& caption, void(*onButtonFunction)(wxCommandEvent&))
{
	wxGetApp().m_frame->AddToolBarTool(toolbar, title, bitmap, caption, onButtonFunction);
}

wxString CHeeksCADInterface::GetExeFolder()
{
	return wxGetApp().GetExeFolder();
}

void CHeeksCADInterface::AddUndoably(HeeksObj* object)
{
	wxGetApp().AddUndoably(object, NULL, NULL);
}

const std::list<HeeksObj*>& CHeeksCADInterface::GetMarkedList(void)
{
	return wxGetApp().m_marked_list->list();
}

bool CHeeksCADInterface::GetArcDirection(HeeksObj* object)
{
	return ((HArc*)object)->m_dir;
}

bool CHeeksCADInterface::GetArcCentre(HeeksObj* object, double* c)
{
	extract(((HArc*)object)->m_circle.Location(), c);
	return true;
}

bool CHeeksCADInterface::GetArcAxis(HeeksObj* object, double* a)
{
	extract(((HArc*)object)->m_circle.Axis().Direction(), a);
	return true;
}

void CHeeksCADInterface::get_2d_arc_segments(double xs, double ys, double xe, double ye, double xc, double yc, bool dir, bool want_start, double pixels_per_mm, void(*callbackfunc)(const double* xy))
{
	wxGetApp().get_2d_arc_segments(xs, ys, xe, ye, xc, yc, dir, want_start, pixels_per_mm, callbackfunc);
}

double CHeeksCADInterface::GetPixelScale()
{
	return wxGetApp().GetPixelScale();
}

void CHeeksCADInterface::Mark(HeeksObj* object)
{
	wxGetApp().m_marked_list->Add(object);
}

void CHeeksCADInterface::ClearMarkedList()
{
	wxGetApp().m_marked_list->Clear();
}

void CHeeksCADInterface::WasModified(HeeksObj* object)
{
	wxGetApp().WasModified(object);
}

int CHeeksCADInterface::PickObjects(const char* str)
{
	return wxGetApp().PickObjects(str);
}