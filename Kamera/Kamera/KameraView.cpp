// KameraView.cpp : implementation of the CKameraView class
//

#include "stdafx.h"
#include "Kamera.h"
#include <Windows.h>
#include <string.h>
#include <iostream>

#include "KameraDoc.h"
#include "KameraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int ycnt = 0;
int rcnt = 0;
int gcnt = 0;
int bcnt = 0;
int ocnt = 0;
int wcnt = 0;
int owoc = 0;    //1 = pomidor  2 = pomarancza   3 = pieczarka  4 = cukinia  5 = sztuczny banan   6 = kiwi
// CKameraView

IMPLEMENT_DYNCREATE(CKameraView, CView)

BEGIN_MESSAGE_MAP(CKameraView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_KAMERA_POBIERZ, &CKameraView::OnKameraPobierz)
	ON_COMMAND(ID_KAMERA_START, &CKameraView::OnKameraStart)
	ON_COMMAND(ID_KAMERA_STOP, &CKameraView::OnKameraStop)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CKameraView construction/destruction

CKameraView::CKameraView()
{
	// TODO: add construction code here

}

CKameraView::~CKameraView()
{
}

BOOL CKameraView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKameraView drawing

void CKameraView::OnDraw(CDC* /*pDC*/)
{
	CKameraDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CKameraView printing

BOOL CKameraView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKameraView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKameraView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CKameraView diagnostics

#ifdef _DEBUG
void CKameraView::AssertValid() const
{
	CView::AssertValid();
}

void CKameraView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}




CKameraDoc* CKameraView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKameraDoc)));
	return (CKameraDoc*)m_pDocument;
}
#endif //_DEBUG


// CKameraView message handlers

LRESULT CALLBACK cbFunct (HWND hWnd, LPVIDEOHDR lpVHdr){
	long size = lpVHdr->dwBufferLength;

	//PAPRYKA
	for (int x=150; x<170; x++)
		for (int y = 110; y < 130; y++) {
			int i0 = x * 3 + y * 3 * 320;
			if (lpVHdr->lpData[i0] < 120 && lpVHdr->lpData[i0 + 1] < 70 && lpVHdr->lpData[i0 + 2] > 210)
			{
				rcnt++;
			}
		}
	//POMARANCZA
	for (int x = 150; x<170; x++)
		for (int y = 110; y < 130; y++) {
			int i0 = x * 3 + y * 3 * 320;
			if (lpVHdr->lpData[i0] < 80 && lpVHdr->lpData[i0 + 1] > 100  && lpVHdr->lpData[i0 + 2] > 160)
			{
				ocnt++;
			}
		}
	//PIECZARKA
	for (int x = 150; x<170; x++)
		for (int y = 110; y < 130; y++) {
			int i0 = x * 3 + y * 3 * 320;
			if (lpVHdr->lpData[i0] > 235 && lpVHdr->lpData[i0 + 1] > 235 && lpVHdr->lpData[i0 + 2] > 235)
			{
				wcnt++;
			}
		}

	//cukinia
	for (int x = 150; x<170; x++)
		for (int y = 110; y < 130; y++) {
			int i0 = x * 3 + y * 3 * 320;
			if (lpVHdr->lpData[i0] < 70  && lpVHdr->lpData[i0 + 1] > 80 && lpVHdr->lpData[i0 + 2] < 70)
			{
				gcnt++;
			}
		}

	//BANAN
	for (int x = 150; x<170; x++)
		for (int y = 110; y < 130; y++) {
			int i0 = x * 3 + y * 3 * 320;
			if (lpVHdr->lpData[i0] >45 && lpVHdr->lpData[i0] < 90 && lpVHdr->lpData[i0 + 1] < 115 && lpVHdr->lpData[i0 + 1] > 75 && lpVHdr->lpData[i0 + 2] < 150 && lpVHdr->lpData[i0 + 2] > 100)
			{
				bcnt++;
			}
		}
	
	//KIWI
	for (int x = 150; x<170; x++)
		for (int y = 110; y < 130; y++) {
			int i0 = x * 3 + y * 3 * 320;
			if (lpVHdr->lpData[i0] < 110 && lpVHdr->lpData[i0 + 1] > 150 && lpVHdr->lpData[i0 + 2] > 150 && lpVHdr->lpData[i0 + 2] < 200)
			{
				ycnt++;
			}
		}


	////////////////////////////////////////////////////////CZERWONA RAMKA///////////////////////////////////////////// 
	for (int x = 150; x < 170; x++){
		int y1 = 109;
		int y2 = 131;
		int i1 = x*3 + y1*3 * 320;
		int i2 = x * 3 + y2 * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 255;
		lpVHdr->lpData[i2 + 2] = 255; 
	};
	for (int y = 110; y < 130; y++) {
		int x1 = 149;
		int x2 = 171;
		int i1 = x1 * 3 + y * 3 * 320;
		int i2 = x2 * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 255;
		lpVHdr->lpData[i2 + 2] = 255;
	};
	////////////////////////////////PASKI STANU////////////////////////////////////////////////////
	
	//Papryka
	int rtmp = rcnt%359;
	for (int x = 0; x < rtmp; x++) {
		int y = 3;
		int i1 = x * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 255;   // RED
		lpVHdr->lpData[i1 + 1] = 0;	// GREEN
		lpVHdr->lpData[i1] = 0;		// BLUE
	};
																	
	//Pomarancza
	int otmp = ocnt%359;
	for (int x = 0; x < otmp; x++) {
		int y = 5;
		int i1 = x * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 235;   // RED
		lpVHdr->lpData[i1 + 1] = 191;	// GREEN
		lpVHdr->lpData[i1] = 16;		// BLUE
	};

	//Pieczarka
	int wtmp = wcnt%359;
	for (int x = 0; x < wtmp; x++) {
		int y = 7;
		int i1 = x * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 255;   // RED
		lpVHdr->lpData[i1 + 1] = 255;	// GREEN
		lpVHdr->lpData[i1] = 255;		// BLUE
	};

	//cukinia
	int gtmp = gcnt%359;
	for (int x = 0; x < gtmp; x++) {
		int y = 9;
		int i1 = x * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 25;   // RED
		lpVHdr->lpData[i1 + 1] = 255;	// GREEN
		lpVHdr->lpData[i1] = 0;		// BLUE
	};

	//Banan
	int ytmp = ycnt % 359;
	for (int x = 0; x < ytmp; x++) {
		int y = 11;
		int i1 = x * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 255;   // RED
		lpVHdr->lpData[i1 + 1] = 234;	// GREEN
		lpVHdr->lpData[i1] = 0;		// BLUE
	};


	//Kiwi
	int btmp = bcnt % 359;
	for (int x = 0; x < btmp; x++) {
		int y = 13;
		int i1 = x * 3 + y * 3 * 320;
		lpVHdr->lpData[i1 + 2] = 110;   // RED
		lpVHdr->lpData[i1 + 1] = 82;	// GREEN
		lpVHdr->lpData[i1] = 57;		// BLUE
	};

	/////////////////////////////////////////CZUJNIKI//////////////////////////////////////////////////

	if (rcnt > 400)   // papryka
	{
		owoc = 1;
		rcnt = 0;
	}
	if (ocnt > 400)  // pomarancza
	{
		owoc = 2;
		ocnt = 0;
	}
	if (wcnt > 3000)   //pieczarka
	{
		owoc = 3;
		wcnt = 0;
	}
	if (gcnt > 250)   // cukinia
	{
		owoc = 4;
		gcnt = 0;
	}
	if (ycnt > 250)   // banan
	{
		owoc = 5;
		ycnt = 0;
	}
	if (bcnt > 400)   // kiwi
	{
		owoc = 6;
		bcnt = 0;
	}

	/////////////////////////////////////KOMUNIKATY/////////////////////////////////////////

	if (owoc == 1)
	{
		AfxMessageBox(_T("Papryka"));
		owoc = 0;
	}
	if (owoc == 2)
	{
		AfxMessageBox(_T("Pomarancza"));
		owoc = 0;
	}
	if (owoc == 3)
	{
		AfxMessageBox(_T("Pieczarka"));
		owoc = 0;
	}
	if (owoc == 4)
	{
		AfxMessageBox(_T("Cukinia"));
		owoc = 0;
	}
	if (owoc == 5)
	{
		AfxMessageBox(_T("Sztuczny banan"));
		owoc = 0;
	}
	if (owoc == 6)
	{
		AfxMessageBox(_T("Kiwi"));
		owoc = 0;
	}

	return (LRESULT) TRUE;
}



void CKameraView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	HWND hwndParent = this->GetSafeHwnd();
	m_wndKamera = capCreateCaptureWindow( L"Nazwa", WS_CHILD | WS_VISIBLE, 10, 10, 320, 240, hwndParent, ID_CAMWND );

	bool res = capDriverConnect( m_wndKamera, 0 );
	capDlgVideoFormat ( m_wndKamera );

	capSetCallbackOnFrame( m_wndKamera, cbFunct );
	// TODO: Add your specialized code here and/or call the base class
}

void CKameraView::OnKameraPobierz()
{
	capGrabFrame ( m_wndKamera, true );
}

void CKameraView::OnKameraStart()
{
	SetTimer( ID_TIMER, 50, NULL);
}

void CKameraView::OnKameraStop()
{
	KillTimer( ID_TIMER );
}

void CKameraView::OnTimer(UINT_PTR nIDEvent)
{
	capGrabFrame( m_wndKamera, true );
	CView::OnTimer(nIDEvent);
}
