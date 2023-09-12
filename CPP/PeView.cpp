
// PeView.cpp: CPeView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pe.h"
#endif

#include "PeDoc.h"
#include "PeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPeView

IMPLEMENT_DYNCREATE(CPeView, CView)

BEGIN_MESSAGE_MAP(CPeView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CPeView::OnSelectColor)
	ON_COMMAND(ID_SIZE_1, &CPeView::OnSize1)
	ON_COMMAND(ID_SIZE_4, &CPeView::OnSize4)
	ON_COMMAND(ID_SIZE_8, &CPeView::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CPeView::OnSize16)
	ON_COMMAND(ID_SIZE_32, &CPeView::OnSize32)
END_MESSAGE_MAP()

// CPeView 생성/소멸

CPeView::CPeView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPeView::~CPeView()
{
}

BOOL CPeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPeView 그리기
#include "CLine.h"
void CPeView::OnDraw(CDC* pDC)
{
	CPeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->m_oa.GetSize(); //크기를 나타낸다
	for (int i = 0; i < n; i++) {
		CLine* pLine =( CLine*) pDoc->m_oa[i];
		pLine->Draw(pDC);
	}

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPeView 인쇄

BOOL CPeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPeView 진단

#ifdef _DEBUG
void CPeView::AssertValid() const
{
	CView::AssertValid();
}

void CPeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPeDoc* CPeView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPeDoc)));
	return (CPeDoc*)m_pDocument;
}
#endif //_DEBUG


// CPeView 메시지 처리기
COLORREF Col;
int Size;

#include"CLine.h"
void CPeView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) {
	CPeDoc* pDoc = GetDocument();
	CLine* pLine = new CLine(opnt, point, Size, Col);
	pDoc->m_oa.Add(pLine);
	Invalidate(FALSE);  //화면을 새로그려준다
}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
}


void CPeView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK);
	Col = dlg.GetColor();
}


void CPeView::OnSize1()
{
	Size = 1;

}


void CPeView::OnSize4()
{
	Size = 4;
}


void CPeView::OnSize8()
{
	Size = 8;
}


void CPeView::OnSize16()
{
	Size = 16;
}


void CPeView::OnSize32()
{
	Size = 32;
}
