
// ODBCView.cpp : CODBCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ODBC.h"
#endif

#include "ODBCSet.h"
#include "ODBCDoc.h"
#include "ODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCView

IMPLEMENT_DYNCREATE(CODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CODBCView, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CODBCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CODBCView 构造/析构

CODBCView::CODBCView()
	: CRecordView(CODBCView::IDD)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CODBCView::~CODBCView()
{
}

void CODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
}

BOOL CODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCSet;
	CRecordView::OnInitialUpdate();

}


// CODBCView 打印


void CODBCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CODBCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CODBCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CODBCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CODBCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CODBCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CODBCView 诊断

#ifdef _DEBUG
void CODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDoc* CODBCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDoc)));
	return (CODBCDoc*)m_pDocument;
}
#endif //_DEBUG


// CODBCView 数据库支持
CRecordset* CODBCView::OnGetRecordset()
{
	return m_pSet;
}



// CODBCView 消息处理程序
