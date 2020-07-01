// KameraView.h : interface of the CKameraView class
//


#pragma once

#include "Vfw.h"

class CKameraView : public CView
{
protected: // create from serialization only
	CKameraView();
	DECLARE_DYNCREATE(CKameraView)

protected: 
	HWND m_wndKamera;



// Attributes
public:
	CKameraDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CKameraView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnKameraPobierz();
	afx_msg void OnKameraStart();
	afx_msg void OnKameraStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in KameraView.cpp
inline CKameraDoc* CKameraView::GetDocument() const
   { return reinterpret_cast<CKameraDoc*>(m_pDocument); }
#endif

