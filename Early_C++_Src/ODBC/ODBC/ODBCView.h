
// ODBCView.h : CODBCView 类的接口
//

#pragma once

class CODBCSet;

class CODBCView : public CRecordView
{
protected: // 仅从序列化创建
	CODBCView();
	DECLARE_DYNCREATE(CODBCView)

public:
	enum{ IDD = IDD_ODBC_FORM };
	CODBCSet* m_pSet;

// 特性
public:
	CODBCDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ODBCView.cpp 中的调试版本
inline CODBCDoc* CODBCView::GetDocument() const
   { return reinterpret_cast<CODBCDoc*>(m_pDocument); }
#endif

