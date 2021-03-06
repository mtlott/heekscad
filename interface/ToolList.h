// ToolList.h
// Copyright (c) 2009, Dan Heeks
// This program is released under the BSD license. See the file COPYING for details.

#pragma once

#include "Tool.h"

class ToolList: public Tool{
private:
	std::list<Tool*>::iterator LoopIt;

public:
	wxString m_title;
	std::list<Tool*> m_tool_list;

	ToolList(const wxChar *t): m_title(t){}
	ToolList(std::list<Tool*>& tools, const wxChar *t): m_title(t), m_tool_list(tools){}
	~ToolList(){Clear();}

	// Tool's virtual functions
	const wxChar* GetTitle(){return m_title.c_str();}
	void Run(){};
	bool IsAToolList(){return true;}

	// member functions
	void Add(Tool *t);
	void Add(std::list<Tool*>& tools);
	void Clear();
};


// splitting undoablelist from toollist

class UndoableList: public Undoable{
private:
	std::list<Undoable*>::iterator LoopIt;

public:
	wxString m_title;
	std::list<Undoable*> m_undoables;

	UndoableList(const wxChar *t): m_title(t){}
	UndoableList(std::list<Undoable*>& undoables, const wxChar *t): m_title(t), m_undoables(undoables){}
	~UndoableList(){Clear();}

	// Tool's virtual functions
	const wxChar* GetTitle(){return m_title.c_str();}
	void Run(bool redo){};
	bool IsAnUndoableList(){return true;}

	// member functions
	void Add(Undoable *u);
	void Add(std::list<Undoable*>& undoables);
	void Clear();
};

